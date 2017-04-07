#include <stdio.h>
#include <iostream>
#include<iomanip>
using namespace std;
/*
int main(){
    //int i = 0;
    cout << "   ";
    for (int col = 0; col <= 15; col++) {
        cout << hex << col << " ";
    }
    cout << endl;
    cout << "   ";
    for (int a = 0; a <= 30; a++) {
        cout << '-';
    }
    cout << endl;
    
    for (int row = 2; row <= 15; row++) {
        cout << hex << row << "0" <<'|' << endl;
        //cout << endl;
        char znak;
        for (int i = 0; i < 15; i++) {
            cout << (char)i;
            znak++;
        }
        
    }
    return 0;
}
*/

 void MakeLine(int len)
 {
	cout << "  ";
	for (int i = 0; i < len; i++)
	{
 cout << "-";
	}
	cout << endl;
 }
 
 int main()
 {
 
	//hlaviËka
	cout << "   ";
	for (int i = 0; i < 16; i++)
	{
 cout << " " << hex << i;
	}
 
	cout << endl;
	MakeLine(35);
 
	//tabulka
	for (int i = 0x20; i < 0xFF; i+=0x10)
	{
 cout << hex << i << "| ";
 
 for (int j = 0; j <= 0xF; j++)
 {
 cout << (char)(i + j) << " ";
 }
 
 cout << "|" << endl;
	}
	
	MakeLine(35);
 
	cout << endl << endl << endl;
 
	//--------------------------------------------------------------------
	//dekadick·
 
	//hlaviËka
	cout << "    ";
	for (int i = 0; i < 10; i++)
	{
 cout << " " << i;
	}
 
	cout << endl << " ";
	MakeLine(23);
 
	//tabulka
	for (int i = 30; i <= 250; i += 10)
	{
 if (i < 100) cout << " ";
 cout << dec << i << "| ";
 
 for (int j = 0; j < 10; j++)
 {
 if (j + i < 32 || j+i > 255) cout << "  ";
 else cout << (char)(i + j) << " ";
 }
 
 cout << "|" << endl;
	}
 
	cout << " ";
	MakeLine(23);
 
	return 0;
 }

