#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	CDate date;
	date.Import(L"22/03/1994");
	cout<<date.dayOfWeek().ConvertUTF16ToUTF8();
	return 0;
}