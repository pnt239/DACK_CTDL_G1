#pragma once
#include <windows.h>
#include <ustring.h>

class CDate
{
	INT m_day;
	INT m_month;
	INT m_year;
	BOOL CheckYear(INT year);
public:
	CDate();
	~CDate();
	void Import(ustring a);
	INT getDay();
	INT GetMonth();
	INT GetYear();
	void setDay(INT d);
	void setMonth(INT m);
	void setYear(INT y);
	ustring dayOfWeek();
};