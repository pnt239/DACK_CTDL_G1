#pragma once
#include <iostream>
#include <ustring.h>
#include <vector>
#include <Windows.h>
class COfficer
{
protected:
	UINT m_ID; 
	ustring m_Name; // tên nhân viên
	//CDate BirthDay; // ngày tháng năm sinh thuộc lớp ngày
	ustring m_Phone; // số điện thoại
	ustring m_Passport; // hộ chiếu
	UINT m_TourCode; // mã tour
	ustring m_TransportCode; // mã số phương tiện
public:
	COfficer();

	//hàm getter và setter các thuộc tính
	UINT getID();
	void setID(UINT ID);

	ustring getName();
	void setName(ustring Name);

	ustring getPhone();
	void setPhone(ustring Phone);

	ustring getPassport();
	void setPassport(ustring Passport);

	UINT getTourCode();
	void setTourCode(UINT TourCode);

	ustring getTransportCode();
	void setTransportCode(ustring Transport);

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

