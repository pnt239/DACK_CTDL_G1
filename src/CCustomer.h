#pragma once
#include <iostream>
#include <string>
#include <vector>


class CCustomer // lớp khách hàng
{
protected:
	int m_ID; 
	std::string m_Name; // tên khách hàng
	//Day BirthDay; // ngày tháng năm sinh thuộc lớp ngày
	std::string m_Phone; // số điện thoại
	std::string m_Passport; // hộ chiếu
	std::string m_TourCode; // mã tour
	std::string m_TransportCode; // mã số phương tiện
public:
	CCustomer();
	 
	// các hàm getter và setter
	int getID();
	void setID(int ID);

	std::string getName();
	void setName(std::string Name);

	std::string getPhone();
	void setPhone(std::string Phone);

	std::string getPassport();
	void setPassport(std::string Passport);

	std::string getTourCode();
	void setTourCode(std::string TourCode);

	std::string getTransportCode();
	void setTransportCode(std::string Transport);

	// hàm assign các thuộc tính
	void AssignName(CCustomer);
	void AssignPhone(CCustomer);
	void AssignPassport(CCustomer);
	void AssignTourCode(CCustomer);
	void AssignTransportCode(CCustomer);
};


//class CListCustomer: public CCustomer // lớp danh sách khách hàng
//{
//private:
//	int SL; // số lượng khách hàng
//	vector<CCustomer> Cus;
//	
//public:
//	CListCustomer();
//	~CListCustomer();
//	void Swap(CCustomer&, CCustomer&);
//	void SortList(); // hàm sắp xếp danh sách khách hàng theo ID
//};
