#include <iostream>
#include "Officer.h"
#include "CCustomer.h"
std::string;

int main()
{
	CCustomer C1, C2;
	C1.setID(1089);
	C1.setName("Nguyen Van Nam");
	C1.setPassport("Z13490B");
	C1.setPhone("0909112233");
	C1.setTourCode("Bus13122013");
	C1.setTransportCode("53");
	
	C2.AssignName(C1);
	C2.AssignPassport(C1);
	C2.AssignPhone(C1);
	C2.AssignTourCode(C1);
	C2.AssignTransportCode(C1);
	return 0;
}