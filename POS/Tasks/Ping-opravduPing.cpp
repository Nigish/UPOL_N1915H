#include <stdio.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/time.h> // For time
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

using namespace std;

uint16_t checksum(uint8_t *addr_b, unsigned len) {
	uint16_t* addr = (uint16_t*) addr_b;
	uint16_t answer = 0;
	/*
	 * Our algorithm is simple, using a 32 bit accumulator (sum), we add
	 * sequential 16 bit words to it, and at the end, fold back all the
	 * carry bits from the top 16 bits into the lower 16 bits.
	 */
	uint32_t sum = 0;
	while (len > 1) {
		sum += *addr++;
		len -= 2;
	}

// mop up an odd byte, if necessary
	if (len == 1) {
		*(unsigned char *) &answer = *(unsigned char *) addr;
		sum += answer;
	}

// add back carry outs from top 16 bits to low 16 bits
	sum = (sum >> 16) + (sum & 0xffff); // add high 16 to low 16
	sum += (sum >> 16); // add carry
	answer = ~sum; // truncate to 16 bits
	return answer;
}

int main(int argc, char *argv[]) {
	size_t size;
	hostent *host;
	icmphdr *icmp, *icmpRecv;
	iphdr *ip;
	int sock,lenght;
	unsigned int ttl;
	sockaddr_in sendSockAddr, receiveSockAddr;
	char buffer[BUFSIZE];
	fd_set mySet;
	timeval tv;
	char *addrString;
	int count;

	unsigned short int pid = getpid(), p;

	if (argc != 3) {
		cerr << "Syntaxe:\n\t" << argv[0] << " " << "adresa" << endl;
		return -1;
	}

	if ((host = gethostbyname(argv[1])) == NULL) {
		cerr << "Špatná adresa" << endl;
		return -1;
	}

	if ((count = atoi(argv[2])) < 1) {
		count = 5;
	}

	if ((sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1) {
		cerr << "Nelze vytvořit soket" << endl;
		return -1;
	}

	ttl = 255;
	setsockopt(sock, IPPROTO_IP, IP_TTL, (const char *) &ttl, sizeof(ttl));

	icmp = (icmphdr *) malloc(sizeof(icmphdr));
	icmp->type = ICMP_ECHO;
	icmp->code = 0;
	icmp->un.echo.id = pid;

	sendSockAddr.sin_family = AF_INET;
	sendSockAddr.sin_port = 0;
	memcpy(&sendSockAddr.sin_addr, host->h_addr, host->h_length);

	struct timeval start, end;
	float mtime, seconds, useconds;

	for (p = 1; p <= count; p++) {
		icmp->checksum = 0;
		icmp->un.echo.sequence = p;
		icmp->checksum = checksum((unsigned char *) icmp, sizeof(icmphdr));

		gettimeofday(&start, NULL);

		sendto(sock, (char *) icmp, sizeof(icmphdr), 0,
				(sockaddr *) &sendSockAddr, sizeof(sockaddr));

		tv.tv_sec = 5;
		tv.tv_usec = 0;
		do {
			FD_ZERO(&mySet);
			FD_SET(sock, &mySet);
			if (select(sock + 1, &mySet, NULL, NULL, &tv) < 0) {
				cerr << "Selhal select" << endl;
				break;
			}
			if (FD_ISSET(sock, &mySet)) {
				size = sizeof(sockaddr_in);
				if ((lenght = recvfrom(sock, buffer, BUFSIZE, 0,
						(sockaddr *) &receiveSockAddr, (socklen_t*) &size))
						== -1) {
					cerr << "Problém při přijímáni dat" << endl;
				}
				ip = (iphdr *) buffer;
				icmpRecv = (icmphdr *) (buffer + ip->ihl * 4);
				if ((icmpRecv->un.echo.id == pid)
						&& (icmpRecv->type == ICMP_ECHOREPLY)
						&& (icmpRecv->un.echo.sequence == p)) {
					addrString = strdup(inet_ntoa(receiveSockAddr.sin_addr));
					host = gethostbyaddr(&receiveSockAddr.sin_addr, 4, AF_INET);

					//Time
					gettimeofday(&end, NULL);
					seconds = end.tv_sec - start.tv_sec;
					useconds = end.tv_usec - start.tv_usec;

					mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;

					cout << lenght << " bytů z "
							<< (host == NULL ? "?" : host->h_name) << " ("
							<< addrString << "): icmp_seq="
							<< icmpRecv->un.echo.sequence << " ttl="
							<< (int) ip->ttl << " time=" << mtime << " ms"
							<< endl;
					free(addrString);
				}
			} else {
				cout << "Čas vypršel" << endl;
				break;
			}
		} while (!((icmpRecv->un.echo.id == pid)
				&& (icmpRecv->type == ICMP_ECHOREPLY)
				&& (icmpRecv->un.echo.sequence == p)));

	}
	close(sock);
	free(icmp);
	return 0;
}
