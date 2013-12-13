#include "CCustomer.h"
#include <string>
#include <vector>
using namespace std;

// Viết các hàm trong lớp khách hàng
CCustomer::CCustomer()
{
	this->m_ID = -1;
	this->m_Name.Set(L"NULL");
	this->m_Passport.Set(L"NULL");
	this->m_Phone.Set(L"NULL");
	this->m_TourCode = -1;
	this->m_TransportCode.Set(L"NULL");
}
int CCustomer::getID()
{
	return this->m_ID;
}

void CCustomer::setID(int ID)
{
	this->m_ID = ID;
}

UINT CCustomer::getPlaceCode()
{
	return this->m_PlaceCode;
}
void CCustomer::setPlaceCode(UINT placecode)
{
	this->m_PlaceCode = placecode;
}


ustring CCustomer::getName()
{
	return this->m_Name;
}

void CCustomer::setName(ustring Name)
{
	this->m_Name = Name;
}

ustring CCustomer::getPhone()
{
	return this->m_Phone;
}

void CCustomer::setPhone(ustring Phone)
{
	this->m_Phone = Phone;
}

ustring CCustomer::getPassport()
{
	return this->m_Passport;
}

void CCustomer::setPassport(ustring Passport)
{
	this->m_Passport = Passport;
}

UINT CCustomer::getTourCode()
{
	return this->m_TourCode;
}

void CCustomer::setTourCode(UINT TourCode)
{
	this->m_TourCode = TourCode;
}

ustring CCustomer::getTransportCode()
{
	return this->m_TransportCode;
}

void CCustomer::setTransportCode(ustring TransportCode)
{
	this->m_TransportCode = TransportCode;
}

void CCustomer::AssignName(CCustomer COff)
{
	this->m_Name = COff.m_Name;
}

void CCustomer::AssignPhone(CCustomer COff)
{
	this->m_Phone = COff.m_Phone;
}


void CCustomer::AssignPassport(CCustomer COff)
{
	this->m_Passport = COff.m_Passport;
}

void CCustomer::AssignTourCode(CCustomer COff)
{
	this->m_TourCode = COff.m_TourCode;
}

void CCustomer::AssignTransportCode(CCustomer COff)
{
	this->m_TransportCode = COff.m_TransportCode;
}

void CCustomer::AssignPlaceCode(CCustomer COff)
{
	this->m_PlaceCode = COff.m_PlaceCode;
}

//////////////////////////////////////////////////////////////////////////////////////

// Viết các hàm trong danh sách khách hàng
//CListCustomer::CListCustomer()
//{
//	this->SL = 0;
//}
//
//CListCustomer::~CListCustomer()
//{
//	if(!this->Cus.empty())
//	{
//		this->Cus.~vector();
//	}
//}
//
//
//void CListCustomer::Swap(CCustomer& a, CCustomer& b) // hoán vị thông tin hai khách hàng
//{
//	CCustomer temp;
//	temp = a;
//	a = b; 
//	b= temp;
//}
//void CListCustomer::SortList() // sắp xếp danh sách khách hàng tăng dần theo ID
//{
//	int min;
//	for(int i = 0; i < this->SL-1; i++)
//	{
//		for(int j = i + 1; j < this->SL; j++)
//			if(this->Cus[j].getID() < this->Cus[i].getID())
//				this->Swap(this->Cus[i], this->Cus[j]);
//	}
//}
//