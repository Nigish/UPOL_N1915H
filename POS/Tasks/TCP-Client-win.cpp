
#include <iostream>
#include <string>
#include <windows.h>

#define BUFSIZE 1000

using namespace std;

int main(int argc, char *argv[])
{
    WORD wVersionRequested = MAKEWORD(1,1); // Èíslo verze 
    WSADATA data;                           // Struktura s info. o knihovnì
    string text;                  // Odesílaný a pøijímaný text
    hostent *host;                          // Vzdálený poèítaè
    sockaddr_in serverSock;                 // Vzdálený "konec potrubí"
    int mySocket;                           // Soket
    int port;                               // Èíslo portu
    char buf[BUFSIZE];                      // Pøijímací buffer
    int size;                             // Poèet pøijatých a odeslaných bytù

    start:
    cout << "Tady se pise:\t";
    getline (cin, text);
    text += '\n';

    if (argc != 3)
    {
        cerr << "Syntaxe:\n\t" << argv[0]
             << " " << "adresa port" << endl;
        return -1;
    }
    // Pøipravíme sokety na práci
    if (WSAStartup(wVersionRequested, &data) != 0)
    {
        cout << "Nepodarilo se inicializovat sockety" << endl;
        // Podle všeho, zde se WSACleanup volat nemusí.
        return -1;
    }
    port = atoi(argv[2]);
    // Zjistíme info o vzdáleném poèítaèi
    if ((host = gethostbyname(argv[1])) == NULL)
    {
        cerr << "Spatna adresa" << endl;
        WSACleanup();
        return -1;
    }
    // Vytvoøíme soket
    if ((mySocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
        cerr << "Nelze vytvorit socket" << endl;
        WSACleanup();
        return -1;
    }
    // Zaplníme strukturu sockaddr_in
    // 1) Rodina protokolù
    serverSock.sin_family = AF_INET;
    // 2) Èíslo portu, ke kterému se pøipojíme
    serverSock.sin_port = htons(port);
    // 3) Nastavení IP adresy, ke které se pøipojíme
    memcpy(&(serverSock.sin_addr), host->h_addr, host->h_length);
    // Pøipojení soketu
    if (connect(mySocket, (sockaddr *)&serverSock, sizeof(serverSock)) == -1)
    {
        cerr << "Nelze navazat spojeni" << endl;
        WSACleanup();
        return -1;
    }
    // Odeslání dat
    if ((size = send(mySocket, text.c_str(), text.size() + 1, 0)) == -1)
    {
        cerr << "Problem s odeslanim dat" << endl;
        WSACleanup();
        return -1;
    }
    cout << "Odeslano " << size << endl;
    // Pøíjem dat
    text = "";
    while (((size = recv(mySocket, buf, BUFSIZE, 0)) != 0) && (size != -1))
    {
        cout << "Prijato " << size << endl;
        text += buf;
    }
    if (size == -1)
    {
        cout << "Nelze prijmout data" << endl;
    }
    // Uzavøu spojení
    closesocket(mySocket);
    WSACleanup();
    cout << "---------------------------------------" << endl;
    cout <<  endl << text << endl;
    cout << "---------------------------------------" << endl;
    goto start;
    return 0;
}
