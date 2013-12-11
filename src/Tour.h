#pragma once
#include "Library.h"
#include "List.h"
#include "Date.h"

//class Place{};

class CTour
{
private:
	UINT m_ID;
	string m_Place;
	Clist<UINT> m_Trans;		//mã số phương tiện di chuyển
	Clist<UINT> m_Customers;	//mã số khách hàng
	//Place m_Place;
	Date m_Time_Start;
	Date m_Time_End;

public:
	void Set_ID(UINT id);
	void Set_Place(string place);
	void Set_Trans(CList<UINT> trans);
	void Set_Customers(CList<UINT> customers);
	void Set_TimeStart(Date time);
	void Set_TimeEnd(Date time);

	UINT Get_ID();
	string Get_Place();
	CList<UINT> Get_Trans();
	CList<UINT> Get_Customers();
	Date Get_TimeStart();
	Date Get_TimeEnd();
	void ShowClist(CList<UINT> a);
};