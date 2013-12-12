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

void CCustomer::Nhap()
{
	cout << "Nhap ID: ";
	cin >> ID;
	fflush(stdin);
	cout << "Nhap ho va ten: ";
	getline(cin, this->Name);
	cout << "Nhap so dien thoai: ";
	getline(cin, this->Phone);
	cout << "Nhap ho chieu: ";
	getline(cin,this->Passport);
	cout << "Nhap ma Tour: ";
	getline(cin, this->TourCode);
	cout << "Nhap ma phuong tien: ";
	getline(cin,this->TransportCode);
}

void CCustomer::Xuat()
{
	cout << endl;
	cout << "ID: " << this->ID << endl;
	cout << "Ho va ten: " << this->Name << endl;
	cout << "So dien thoai: " << this->Phone << endl;
	cout << "Ho chieu: " << this->Passport << endl;
	cout << "Ma tour: " << this->TourCode << endl;
	cout << "Ma phuong tien: " << this->TransportCode << endl;
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

void CListCustomer::Input()
{
	CCustomer temp;
	cout << "Nhap so luong khach hang: ";
	cin >> this->SL;
	
	for(int i = 0 ; i < SL; i++)
	{
		cout << "\nNhap thong tin khach hang thu " << i+1 << ":\n";
		temp.Nhap();
		this->Cus.push_back(temp);
	}
}

void CListCustomer::Output()
{
	CCustomer temp;
	for(int i = 0; i < this->SL; i++)
	{
		cout << "\nThong tin khach hang thu " << i+1 <<endl;
		this->Cus[i].Xuat();
	}
}

void CListCustomer::Swap(CCustomer& a, CCustomer& b)
{
	CCustomer temp;
	temp = a;
	a = b; 
	b= temp;
}
void CListCustomer::SortList()
{
	int min;
	for(int i = 0; i < this->SL-1; i++)
	{
		for(int j = i + 1; j < this->SL; j++)
			if(this->Cus[j].getID() < this->Cus[i].getID())
				this->Swap(this->Cus[i], this->Cus[j]);
	}
}

