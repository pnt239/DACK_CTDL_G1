#include "Officer.h"
#include <iostream>
#include <vector>
#include<string>

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

void COfficer::Nhap()
{
	cout << "Nhap ID: ";
	cin >> ID;
	fflush(stdin);
	cout << "Nhap ho va ten: ";
	fflush(stdin);
	getline(cin, this->Name);
	cout << "Nhap so dien thoai: ";
	fflush(stdin);
	getline(cin, this->Phone);
	cout << "Nhap ho chieu: ";
	fflush(stdin);
	getline(cin,this->pPassport);
	cout << "Nhap ma Tour: ";
	fflush(stdin);
	getline(cin, this->TourCode);
	cout << "Nhap ma phuong tien: ";
	fflush(stdin);
	getline(cin,this->TransportCode);
}

void COfficer::Xuat()
{
	cout << endl;
	cout << "ID: " << this->ID << endl;
	cout << "Ho va ten: " << this->Name << endl;
	cout << "So dien thoai: " << this->Phone << endl;
	cout << "Ho chieu: " << this->Passport << endl;
	cout << "Ma tour: " << this->TourCode << endl;
	cout << "Ma phuong tien: " << this->TransportCode << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Viết các hàm trong lớp danh sách nhân viên
CListOfficer::CListOfficer()
{
	this->SL = 0;
}

CListOfficer::~CListOfficer()
{
	if(!this->Cus.empty())
	{
		this->Cus.~vector();
	}
}

void CListOfficer::Input()
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

void CListOfficer::Output()
{
	CCustomer temp;
	for(int i = 0; i < this->SL; i++)
	{
		cout << "\nThong tin khach hang thu " << i+1 <<endl;
		this->Cus.front().Xuat();
	}
}

void CListOfficer::Swap(CCustomer& a, CCustomer& b)
{
	CCustomer temp;
	temp = a;
	a = b; 
	b = temp;
}
void CListOfficer::SortList()
{
	int min;
	for(int i = 0; i < this->SL-1; i++)
	{
		min = i;
		for(int j = i + 1; j < this->SL; j++)
			if(this->Cus[j].getID() < this->Cus[min].getID())
				min = j;
		this->Swap(this->Cus[min], this->Cus[i]);
	}
}
