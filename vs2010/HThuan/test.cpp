#include <iostream>
#include "ustring.h" // cai nao cung duoc
using namespace std;

int main()
{
	ustring s1 = L"b";
	ustring s2 = L"a";
	string a;
	cout << s1.compare(s2);
	return 0;
}