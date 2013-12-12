#pragma once
#include "Library.h"

const int SizeMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Kích thước của 12 tháng trong năm thường
const int _SizeMonth[] = {31,29,31,30,31,30,31,31,30,31,30,31}; //Kích thước của 12 tháng trong năm nhuận

class CDate
{
	int m_day;
	int m_month;
	int m_year;
public:
	CDate();
	~CDate();
	void Import(string a);
	int getD();
	int GetM();
	int GetY();
	void setD(int d);
	void setM(int m);
	void setY(int y);
};

bool CheckYear(int year);