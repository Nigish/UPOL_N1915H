//
//  POS_c2.cpp
//  Viet_TH_UPOL
//
//  Created by Viet Tran Hoang on 26.10.16.
//  Copyright © 2016 Viet Tran Hoang. All rights reserved.
//

#include <sys/socket.h>
#include <sys/types.h>
#include <linux/if_ether.h>
#include <netpacket/packet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define MAX 65536

int main(int argc, char *argv[]) {
    int sock, lenght, count;
    unsigned short int frag_off;
    char buffer[MAX];
    sockaddr_ll addr;
    sockaddr_in address;
    socklen_t size;
    iphdr *ip;
    char *addrString;
    register char mf;
    register short int offset;
    fd_set mySet;
    
    if (argc == 1 or argc > 3) {
        fprintf(stderr, "Syntaxe: %s N index\n\tN je pocet paketu, ktere ma program prijmout\n\tindex je rozhrani linkove vrstvy, volitelne\n", argv[0]);
        return -1;
    }
    
    sscanf(argv[1], "%d", &count);
    
    for (int p = 0; p < count; p++) {
        if ((sock = socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_IP))) == -1) {
            perror("Selhal socket");
            return -1;
        }
        
        FD_ZERO(&mySet);
        FD_SET(sock, &mySet);
        
        if (select(sock + 1, &mySet, NULL, NULL, NULL) == -1) {
            perror("Selhal select");
            close(sock);
            return -1;
        }
        
        size = sizeof(addr);
        
        if ((lenght = recvfrom(sock, buffer, MAX, 0, (sockaddr *)&addr, (unsigned int*)&size)) == -1) {
            perror("Selhal recvfrom");
            close(sock);
            return -1;
        }
        
        if (argv[2] != NULL) {
            if (addr.sll_ifindex != atoi(argv[2])) {close(sock); p--; continue;}
        }
        
        for (int myInt = 0; myInt < 45; myInt++) printf("-");
        
        printf("\n");
        printf("Prijato: %d bytu\n", lenght);
        printf("Protokol (linkovy): %d\n", ntohs(addr.sll_protocol));
        printf("Index sitoveho rozhrani: %d\n", addr.sll_ifindex);
        printf("Velikost (linkove) adresy odesilatele: %d\n", addr.sll_halen);

        if (addr.sll_halen != 0) {
            printf("Adresa (linkova) odesilatele: ");
            for (int i = 0; i < addr.sll_halen - 1; i++) {
                printf("%x:", addr.sll_addr[i]);
            }
            
            printf("%x\n", addr.sll_addr[addr.sll_halen - 1]);
        }
        
        ip = (iphdr*)buffer;
        
	printf("\n");
        addrString=strdup(inet_ntoa(*(in_addr*)&ip->saddr));
        printf("IP adresa odesilatele: %s\n", addrString);
        free(addrString);
        addrString=strdup(inet_ntoa(*(in_addr*)&ip->daddr));
        printf("IP adresa prijemce: %s\n",  addrString);
        free(addrString);
        printf("Verze IP protokolu: %d\n", ip->version);
        printf("Velikost IP hlavicky: %d\n", ip->ihl * 4);
        printf("Velikost IP paketu: %d\n", ntohs(ip->tot_len));
        printf("Identifikátor paketu: %d\n", ntohs(ip->id));
        printf("TTL:  %d\n", ip->ttl);
	
	for (int myInt = 0; myInt < 45; myInt++) printf("-");        
        printf("\n");
	close(sock);
    }
    return 0;
}
