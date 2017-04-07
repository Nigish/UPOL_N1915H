#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


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
		std::cout << hp->h_name;
	}
}


int main(int argc, char *argv[])
{	if (argc < 2)
	{
		std::cerr << "Syntax:\n\t" << argv[0] << " " << "adresa [adresa1 […]]"
		 << std::endl;
		return -1;
	}

	for (int i = 1;i <argc;i++){
		std::cout << std::endl << "----------------------------------------" << std::endl;
		hostent *H = gethostbyname(argv[i]);
		if (H == NULL)
		{
			std::cerr << "Nepodarilo se zjistit adresu" << std::endl;
				return -1;
		}
		std::cout << "Oficialni jmeno: " << H->h_name << std::endl;
		std::cout << "Alternativy: " << std::endl;
		/* Budeme prochazet pole H->h_aliases. Pole je ukoncene NULL.*/
			char **alternativy = H->h_aliases;
		while(*alternativy != NULL)
		{
			std::cout << "\t" << *(alternativy++) << std::endl;
		}
		/* Budeme prochazet pole H->h_addr_list. Pole je ukoncene NULL.
			   jiny postup.*/
		std::cout << "Adresy: " << std::endl;
		register int index = 0;
		while (	H->h_addr_list[index]!= NULL)
		{
			/* H->h_addr_list je binarni forma IP adresy. Pro prevod na
			   teckovu konvenci pouzijeme inet_ntoa.*/
			std::cout<<"\t"<< inet_ntoa(*(in_addr *)H->h_addr_list[index]) << " -> ";
			reverseIP( inet_ntoa(*(in_addr *)H->h_addr_list[index++]));
			std::cout<< std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
