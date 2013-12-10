#include <iostream>
#include "Officer.h"
using namespace std;

int main()
{
	CListOfficer L;
	L.Input();
	L.SortList();
	L.Output();
	
	/*CCustomer C1, C2;
	C1.Nhap();
	cout << "\nTest: " << endl;
	C1.Xuat();
	C2.AssignName(C1);
	C2.AssignPassport(C1);
	C2.AssignPhone(C1);
	C2.AssignTourCode(C1);
	C2.AssignTransportCode(C1);
	cout << "\ntTest Assign" << endl;
	C2.Xuat();*/
	return 0;
}