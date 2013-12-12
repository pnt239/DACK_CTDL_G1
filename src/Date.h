#pragma once
#include "Library.h"


class CDate
{
	int m_day;
	int m_month;
	int m_year;
	bool CheckYear(int year);
public:
	CDate();
	~CDate();
	void Import(string a);
	int getDay();
	int GetMonth();
	int GetYear();
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	string dayOfWeek(int d, int m, int y);
};