//
//  POS_c3.cpp
//  Viet_TH_UPOL
//
//  Created by Viet Tran Hoang on 07.12.16.
//  Copyright © 2016 Viet Tran Hoang. All rights reserved.
//

#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


void reverseIP(char *argv)
{
    //91.213.160.118
    struct hostent *hp;
    char *ip;
    in_addr_t data;
    
    ip = argv;
    data = inet_addr(ip);
    hp = gethostbyaddr(&data, 4, AF_INET);
    
    if (hp == NULL) {
        printf("Unknown host\n");
        exit(1);
    }
    else {
        //printf(hp->h_name);
        cout << hp->h_name;
    }
}


int main(int argc, char *argv[])
{	if (argc < 2)
{
    cerr << "Syntax:\n\t" << argv[0] << " " << "adresa [adresa1 […]]"
    << endl;
    return -1;
}
    
    for (int i = 1;i <argc;i++){
        cout << endl << "----------------------------------------" << endl;
        hostent *H = gethostbyname(argv[i]);
        if (H == NULL)
        {
            cerr << "Nepodarilo se zjistit adresu" << endl;
            return -1;
        }
        cout << "Oficialni jmeno: " << H->h_name << endl;
        cout << "Alternativy: " << endl;
        /* Budeme prochazet pole H->h_aliases. Pole je ukoncene NULL.*/
        char **alternativy = H->h_aliases;
        while(*alternativy != NULL)
        {
            cout << "\t" << *(alternativy++) << endl;
        }
        /* Budeme prochazet pole H->h_addr_list. Pole je ukoncene NULL.
         jiny postup.*/
        cout << "Adresy: " << endl;
        register int index = 0;
        while (	H->h_addr_list[index]!= NULL)
        {
            /* H->h_addr_list je binarni forma IP adresy. Pro prevod na
             teckovu konvenci pouzijeme inet_ntoa.*/
            cout<<"\t"<< inet_ntoa(*(in_addr *)H->h_addr_list[index]) << " -> ";
            reverseIP( inet_ntoa(*(in_addr *)H->h_addr_list[index++]));
            cout<< endl;
        }
        cout << endl;
    }
    return 0;
}


