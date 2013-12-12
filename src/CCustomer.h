#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CCustomer // lớp khách hàng
{
protected:
	int ID; 
	string Name; // tên khách hàng
	//Day BirthDay; // ngày tháng năm sinh thuộc lớp ngày
	string Phone; // số điện thoại
	string Passport; // hộ chiếu
	string TourCode; // mã tour
	string TransportCode; // mã số phương tiện
public:
	CCustomer();
	 
	// các hàm getter và setter
	int getID();
	void setID(int ID);

	string getName();
	void setName(string Name);

	string getPhone();
	void setPhone(string Phone);

	string getPassport();
	void setPassport(string Passport);

	string getTourCode();
	void setTourCode(string TourCode);

	string getTransportCode();
	void setTransportCode(string Transport);

	// hàm assign các thuộc tính
	void AssignName(CCustomer);
	void AssignPhone(CCustomer);
	void AssignPassport(CCustomer);
	void AssignTourCode(CCustomer);
	void AssignTransportCode(CCustomer);
};


class CListCustomer: public CCustomer // lớp danh sách khách hàng
{
private:
	int SL; // số lượng khách hàng
	vector<CCustomer> Cus;
	
public:
	CListCustomer();
	~CListCustomer();
	void Swap(CCustomer&, CCustomer&);
	void SortList(); // hàm sắp xếp danh sách khách hàng theo ID
};
