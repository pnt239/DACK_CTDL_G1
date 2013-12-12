#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class COfficer
{
protected:
	int ID; 
	string Name; // tên nhân viên
	//Day BirthDay; // ngày tháng năm sinh thuộc lớp ngày
	string Phone; // số điện thoại
	string Passport; // hộ chiếu
	string TourCode; // mã tour
	string TransportCode; // mã số phương tiện
public:
	COfficer();

	//hàm getter và setter các thuộc tính
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

	// hàm assign 
	void Assign(COfficer); 
	void AssignName(COfficer);
	void AssignPhone(COfficer);
	void AssignPassport(COfficer);
	void AssignTourCode(COfficer);
	void AssignTransportCode(COfficer);
};

class CListOfficer: public COfficer // lớp danh sách nhân viên
{
private:
	int SL; // số lượng khách hàng
	vector<COfficer> Offi;
	
public:
	CListOfficer();
	~CListOfficer();
	void SortList();// sắp xếp danh sách nhân viên theo ID
	void Swap(COfficer&, COfficer&); // hàm hoán vị
};

