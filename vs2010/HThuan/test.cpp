#include <iostream>
#include <fstream>
#include "ustring.h" // cai nao cung duoc
using namespace std;

int main()
{
	ustring s1 = L"hôm nay";
	ustring s2 = L"a";
	char* tam = new char[500];
	fstream f;
	f.open("text.txt",ios_base::out);
	f << s1.ConvertUTF16ToUTF8();
	f.close();
	f.open("text.txt",ios_base::in);
	f.getline(tam,500);
	f.close();
	s2.ConvertUTF8ToUTF16(tam);
	cout << s2;
	return 0;
}