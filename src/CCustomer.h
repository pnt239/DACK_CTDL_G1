#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ustring.h>
#include <Windows.h>


class CCustomer // lớp khách hàng
{
protected:
	int m_ID; 
	ustring m_Name; // tên khách hàng
	//Day BirthDay; // ngày tháng năm sinh thuộc lớp ngày
	ustring m_Phone; // số điện thoại
	ustring m_Passport; // hộ chiếu
	UINT m_TourCode; // mã tour
	UINT m_PlaceCode;	//mã địa điểm
	ustring m_TransportCode; // mã số phương tiện
public:
	CCustomer();
	 
	// các hàm getter và setter
	int getID();
	void setID(int ID);

	UINT getPlaceCode();
	void setPlaceCode(UINT placecode);

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

	// hàm assign các thuộc tính
	void AssignName(CCustomer);
	void AssignPhone(CCustomer);
	void AssignPassport(CCustomer);
	void AssignTourCode(CCustomer);
	void AssignTransportCode(CCustomer);
	void AssignPlaceCode(CCustomer);
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
