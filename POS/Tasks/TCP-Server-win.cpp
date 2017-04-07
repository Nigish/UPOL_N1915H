#include <iostream>
#include <windows.h>
#include <string>

#define BUFSIZE 1000

using namespace std;

int main(int argc, char *argv[])
{
    WORD wVersionRequested = MAKEWORD(1,1); // Èíslo verze
    WSADATA data;           // Struktura s info. o knihovnì;    
    std::string text, ret = "", splitter = ":   ";       
    sockaddr_in sockName;   // "Jméno" soketu a èíslo portu
    sockaddr_in clientInfo; // Klient, který se pøipojil 
    SOCKET mainSocket;      // Soket
    int port;               // Èíslo portu
    char buf[BUFSIZE];      // Pøijímací buffer
    int size;               // Poèet pøijatých a odeslaných bytù
    int addrlen;            // Velikost adresy vzdáleného poèítaèe
    int count = 0;          // Poèet pøipojení
    bool end = true;

    if (argc != 2)
    {
        cerr << "Syntaxe:\n\t" << argv[0]
                << " " << "port" << endl;
        return -1;
    }
    // Pøipravíme sokety na práci
    if (WSAStartup(wVersionRequested, &data) != 0)
    {
        cout << "Nepodarilo se inicializovat sockety" << endl;
        return -1;
    }    
    port = atoi(argv[1]);
    // Vytvoøíme soket
    if ((mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) 
                 == INVALID_SOCKET)
    {
        cerr << "Nelze vytvorit socket" << endl;
        WSACleanup();
        return -1;
    }
    // Zaplníme strukturu sockaddr_in
    // 1) Rodina protokolù;
    sockName.sin_family = AF_INET;
    // 2) Èíslo portu, na kterém èekáme
    sockName.sin_port = htons(port);
    // 3) Nastavení IP adresy lokální síové karty, pøes kterou 
    // je možno se pøipojit. 
    // Nastavíme možnost pøipojit se odkudkoliv. 
    sockName.sin_addr.s_addr = INADDR_ANY;
    //pøiøadíme soketu jméno
    if (bind(mainSocket, (sockaddr *)&sockName, sizeof(sockName)) 
                == SOCKET_ERROR)
    {
        cerr << "Problem s pojmenovanim socketu." << endl;
        WSACleanup();
        return -1;
    }
    // Vytvoøíme frontu požadavkù na spojení. 
    // Vytvoøíme frontu maximální velikosti 10 požadavkù.
    if (listen(mainSocket, 10) == SOCKET_ERROR)
    {
        cerr << "Problem s vytvorením fronty" << endl;
        WSACleanup();
        return -1;
    }
    do
    {
        // Poznaèím si velikost struktury clientInfo.
        // Pøedám to funkci accept. 
        addrlen = sizeof(clientInfo);
        // Vyberu z fronty požadavek na spojení.
        // "client" je nový soket spojující klienta se serverem.
        SOCKET client = accept(mainSocket, (sockaddr*)&clientInfo, 
                              &addrlen);
        int totalSize = 0;
        if (client == INVALID_SOCKET)
        {
                cerr << "Problem s prijetim spojeni" <<endl;
                WSACleanup();
                return -1;
        }
        // Zjistím IP adresu klienta.
        cout << "Nekdo se pripojil z adresy: " 
                << inet_ntoa((in_addr)clientInfo.sin_addr) << endl;
        // Pøijmu data. Ke komunikaci s klientem používám soket 
        //"client"
        text = "";

                if ((size = recv(client, buf, BUFSIZE - 1, 0)) 
                          == SOCKET_ERROR)
                {
                        cerr << "Problem s prijetimm dat." << endl;
                        WSACleanup();
                        return -1;
                }
                cout << "Prijato: " << size << endl;
                totalSize += size;
                text += buf;

        cout << text; 
       if(text == "*shutdown*\n"){
        end = false;
        text = "*Spojeni ukonceno*";
       }
     	ret += inet_ntoa((in_addr)clientInfo.sin_addr) + splitter + text;
     	// Odešlu pozdrav
     	if ((size = send(client, ret.c_str(), ret.size() + 1, 0)) == -1)
     	{
                cerr << "Problem s odeslanim dat" << endl;
                WSACleanup();
                return -1;
        }
        cout << "Odeslano: " << size << endl;
        // Uzavøu spojení s klientem
        closesocket(client);
    }while (end);
    cout << "Koncim" << endl;
    closesocket(mainSocket); 
    WSACleanup();    
    return 0;
}
