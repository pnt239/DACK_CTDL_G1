#include "Officer.h"
#include "CCustomer.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include<string>
using namespace std;

// Viết các hàm trong lớp nhân viên
COfficer::COfficer()
{
	this->m_ID = -1;
	this->m_Name = "NULL";
	this->m_Passport = "NULL";
	this->m_Phone = "NULL";
	this->m_TourCode = -1;
	this->m_TransportCode = "NULL";
}
int COfficer::getID()
{
	return this->m_ID;
}

void COfficer::setID(int ID)
{
	this->m_ID = ID;
}

string COfficer::getName()
{
	return this->m_Name;
}

void COfficer::setName(std::string Name)
{
	this->m_Name = Name;
}

std::string COfficer::getPhone()
{
	return this->m_Phone;
}

void COfficer::setPhone(std::string Phone)
{
	this->m_Phone = Phone;
}

std::string COfficer::getPassport()
{
	return this->m_Passport;
}

void COfficer::setPassport(std::string Passport)
{
	this->m_Passport = Passport;
}

UINT COfficer::getTourCode()
{
	return this->m_TourCode;
}

void COfficer::setTourCode(UINT TourCode)
{
	this->m_TourCode = TourCode;
}

std::string COfficer::getTransportCode()
{
	return this->m_TransportCode;
}

void COfficer::setTransportCode(std::string TransportCode)
{
	this->m_TransportCode = TransportCode;
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
	this->m_Name = COff.m_Name;
}

void COfficer::AssignPhone(COfficer COff)
{
	this->m_Phone = COff.m_Phone;
}


void COfficer::AssignPassport(COfficer COff)
{
	this->m_Passport = COff.m_Passport;
}

void COfficer::AssignTourCode(COfficer COff)
{
	this->m_TourCode = COff.m_TourCode;
}

void COfficer::AssignTransportCode(COfficer COff)
{
	this->m_TransportCode = COff.m_TransportCode;
}


///////////////////////////////////////////////////////////////////////////////////////////////

// Viết các hàm trong lớp danh sách nhân viên
//CListOfficer::CListOfficer()
//{
//	this->SL = 0;
//}
//
//CListOfficer::~CListOfficer()
//{
//	if(!this->Offi.empty())
//	{
//		this->Offi.~vector();
//	}
//}
//
//
//void CListOfficer::Swap(COfficer& a, COfficer& b) // hàm hoán vị thông tin nhân viên
//{
//	COfficer temp;
//	temp.Assign(a);
//	a.Assign(b);
//	b.Assign(temp);
//}
//void CListOfficer::SortList() // sắp xếp danh sách nhân viên tăng dần theo ID
//{
//	for(int i = 0; i < this->SL-1; i++)
//	{
//		for(int j = i + 1; j < this->SL; j++)
//			if(this->Offi[j].getID() < this->Offi[i].getID())
//				this->Swap(this->Offi[i], this->Offi[j]);
//	}
//}
