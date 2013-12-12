#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
class COfficer
{
protected:
	int m_ID; 
	std::string m_Name; // tên nhân viên
	//Day BirthDay; // ngày tháng năm sinh thuộc lớp ngày
	std::string m_Phone; // số điện thoại
	std::string m_Passport; // hộ chiếu
	std::string m_TourCode; // mã tour
	std::string m_TransportCode; // mã số phương tiện
public:
	COfficer();

	//hàm getter và setter các thuộc tính
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

	// hàm assign 
	void Assign(COfficer); 
	void AssignName(COfficer);
	void AssignPhone(COfficer);
	void AssignPassport(COfficer);
	void AssignTourCode(COfficer);
	void AssignTransportCode(COfficer);
};

//class CListOfficer: public COfficer // lớp danh sách nhân viên
//{
//private:
//	int SL; // số lượng khách hàng
//	vector<COfficer> Offi;
//	
//public:
//	CListOfficer();
//	~CListOfficer();
//	void SortList();// sắp xếp danh sách nhân viên theo ID
//	void Swap(COfficer&, COfficer&); // hàm hoán vị
//};

