#include "CCustomer.h"
#include <string>
#include <vector>
using namespace std;

// Viết các hàm trong lớp khách hàng
CCustomer::CCustomer()
{
	this->ID = -1;
	this->Name = "NULL";
	this->Passport = "NULL";
	this->Phone = "NULL";
	this->TourCode = "NULL";
	this->TransportCode = "NULL";
}
int CCustomer::getID()
{
	return this->ID;
}

void CCustomer::setID(int ID)
{
	this->ID = ID;
}

string CCustomer::getName()
{
	return this->Name;
}

void CCustomer::setName(string Name)
{
	this->Name = Name;
}

string CCustomer::getPhone()
{
	return this->Phone;
}

void CCustomer::setPhone(string Phone)
{
	this->Phone = Phone;
}

string CCustomer::getPassport()
{
	return this->Passport;
}

void CCustomer::setPassport(string Passport)
{
	this->Passport = Passport;
}

string CCustomer::getTourCode()
{
	return this->TourCode;
}

void CCustomer::setTourCode(string TourCode)
{
	this->TourCode = TourCode;
}

string CCustomer::getTransportCode()
{
	return this->TransportCode;
}

void CCustomer::setTransportCode(string TransportCode)
{
	this->TransportCode = TransportCode;
}

void CCustomer::AssignName(CCustomer COff)
{
	this->Name = COff.Name;
}

void CCustomer::AssignPhone(CCustomer COff)
{
	this->Phone = COff.Phone;
}


void CCustomer::AssignPassport(CCustomer COff)
{
	this->Passport = COff.Passport;
}

void CCustomer::AssignTourCode(CCustomer COff)
{
	this->TourCode = COff.TourCode;
}

void CCustomer::AssignTransportCode(CCustomer COff)
{
	this->TransportCode = COff.TransportCode;
}


//////////////////////////////////////////////////////////////////////////////////////

// Viết các hàm trong danh sách khách hàng
CListCustomer::CListCustomer()
{
	this->SL = 0;
}

CListCustomer::~CListCustomer()
{
	if(!this->Cus.empty())
	{
		this->Cus.~vector();
	}
}


void CListCustomer::Swap(CCustomer& a, CCustomer& b) // hoán vị thông tin hai khách hàng
{
	CCustomer temp;
	temp = a;
	a = b; 
	b= temp;
}
void CListCustomer::SortList() // sắp xếp danh sách khách hàng tăng dần theo ID
{
	int min;
	for(int i = 0; i < this->SL-1; i++)
	{
		for(int j = i + 1; j < this->SL; j++)
			if(this->Cus[j].getID() < this->Cus[i].getID())
				this->Swap(this->Cus[i], this->Cus[j]);
	}
}

