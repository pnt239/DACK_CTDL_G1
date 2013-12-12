#include "Officer.h"
#include "CCustomer.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

// Viết các hàm trong lớp nhân viên
COfficer::COfficer()
{
	this->ID = -1;
	this->Name = "NULL";
	this->Passport = "NULL";
	this->Phone = "NULL";
	this->TourCode = "NULL";
	this->TransportCode = "NULL";
}
int COfficer::getID()
{
	return this->ID;
}

void COfficer::setID(int ID)
{
	this->ID = ID;
}

string COfficer::getName()
{
	return this->Name;
}

void COfficer::setName(string Name)
{
	this->Name = Name;
}

string COfficer::getPhone()
{
	return this->Phone;
}

void COfficer::setPhone(string Phone)
{
	this->Phone = Phone;
}

string COfficer::getPassport()
{
	return this->Passport;
}

void COfficer::setPassport(string Passport)
{
	this->Passport = Passport;
}

string COfficer::getTourCode()
{
	return this->TourCode;
}

void COfficer::setTourCode(string TourCode)
{
	this->TourCode = TourCode;
}

string COfficer::getTransportCode()
{
	return this->TransportCode;
}

void COfficer::setTransportCode(string TransportCode)
{
	this->TransportCode = TransportCode;
}

void  COfficer::Assign(COfficer COff)
{
	this->AssignName(COff);
	this->AssignPhone(COff);
	this->AssignPassport(COff);
	this->AssignTourCode(COff);
	this->AssignTransportCode(COff);
}
void COfficer::AssignName(COfficer COff)
{
	this->Name = COff.Name;
}

void COfficer::AssignPhone(COfficer COff)
{
	this->Phone = COff.Phone;
}


void COfficer::AssignPassport(COfficer COff)
{
	this->Passport = COff.Passport;
}

void COfficer::AssignTourCode(COfficer COff)
{
	this->TourCode = COff.TourCode;
}

void COfficer::AssignTransportCode(COfficer COff)
{
	this->TransportCode = COff.TransportCode;
}


///////////////////////////////////////////////////////////////////////////////////////////////

// Viết các hàm trong lớp danh sách nhân viên
CListOfficer::CListOfficer()
{
	this->SL = 0;
}

CListOfficer::~CListOfficer()
{
	if(!this->Offi.empty())
	{
		this->Offi.~vector();
	}
}


void CListOfficer::Swap(COfficer& a, COfficer& b) // hàm hoán vị thông tin nhân viên
{
	COfficer temp;
	temp.Assign(a);
	a.Assign(b);
	b.Assign(temp);
}
void CListOfficer::SortList() // sắp xếp danh sách nhân viên tăng dần theo ID
{
	for(int i = 0; i < this->SL-1; i++)
	{
		for(int j = i + 1; j < this->SL; j++)
			if(this->Offi[j].getID() < this->Offi[i].getID())
				this->Swap(this->Offi[i], this->Offi[j]);
	}
}
