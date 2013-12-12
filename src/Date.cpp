#pragma once
#include "Date.h"
#include "Library.h"
using namespace std;

const int SizeMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Kích thước của 12 tháng trong năm thường
const int _SizeMonth[] = {31,29,31,30,31,30,31,31,30,31,30,31}; //Kích thước của 12 tháng trong năm nhuận
const ustring days[] =  {L"Sunday", L"Monday", L"Tuesday", L"Wednesday", L"Thursday", L"Friday", L"Saturday"};

CDate::CDate()
{

}

CDate::~CDate()
{

}

void CDate::Import(ustring a)
{
	do
	{
		int dem = 0;
		int dk = 0;
		int j = 0;
		char** temp = new char*[3]; //Tạo con trỏ hai chiều kiểu char
		for(int i = 0; i < 3; i++) //Vòng lặp khởi tạo vùng nhớ cho biến
			temp[i] = new char[a.length()];

		for(int i = 0; i < a.length(); i++) //Vòng lặp chạy từ cuối chuỗi
		{
			if(a[i] >= '0' && a[i] <= '9') //Nếu gặp phần tử là số thì thêm vào biến tạm thứ dem.
			{
				temp[dem][j] = a[i];
				j++;
			}
			else //Nếu gặp thì tăng dem lên 1 để chuyển biến tạm và j = 0 để trở về vị trí ban đầu của biến tạm mới
			{
				dem++;
				j = 0;
			}
		}

		this->m_day = atoi(temp[0]); //Chuyển giá trị trong chuỗi thành kiểu nguyên và gán cho thuộc tính của con trỏ this
		this->m_month = atoi(temp[1]); //Tương tự
		this->m_year = atoi(temp[2]); //Tương tự

	} while(this->m_year < 0 || this->m_month < 0 || this->m_month > 12 || (CheckYear(this->m_year) == 0 && this->m_day > SizeMonth[this->m_month - 1] || this->m_day < 0) || (CheckYear(this->m_year) == 1 && this->m_day > _SizeMonth[this->m_month - 1] || this->m_day < 0)); //Điều kiện dùng của vòng lặp nhập thời gian
}

INT CDate::GetMonth()
{
	return this->m_month;
}

INT CDate::getDay()
{
	return this->m_day;
}

INT CDate::GetYear()
{
	return this->m_year;
}

void CDate::setDay(INT d)
{
	this->m_day = d;
}
void CDate::setMonth(INT m)
{
	this->m_month = m;
}
void CDate::setYear(INT y)
{
	this->m_year = y;
}

BOOL CDate::CheckYear(INT year)
{
	if(year % 400 == 0) //Nếu năm đó chia hết cho 400 thì là năm nhuận
		return 1;
	if(year % 100 != 0 && year % 4) //nếu năm đó chia hết cho 4 nhưng không chia hết cho 100 thì là năm nhuận, vì điều kiện chia hết cho 400 đã xét
		return 1;
	return 0; //Nếu không thỏa mãn điều kiện thì thoát hàm.
}

ustring CDate::dayOfWeek()
{
	int tmp;
	tmp=((int)(m_day+2*m_month+3*(m_month+1)/5+m_year+m_year/4))%7;
	return days[tmp];
}