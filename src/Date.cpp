#pragma once
#include "Date.h"

void Date::Import()
{
	do
	{
		int dem = 0;
		string a;
		int dk = 0;
		int j = 0;
		cout << "Nhap vao chuoi co dang (dd/mm/yyyy): ";
		fflush(stdin);
		getline(cin, a); //Nhập chuỗi thời gian vào chuỗi a
		fflush(stdin);
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

	}while(this->m_year < 0 || this->m_month < 0 || this->m_month > 12 || (CheckYear(this->m_year) == 0 && this->m_day > SizeMonth[this->m_month - 1] || this->m_day < 0) || (CheckYear(this->m_year) == 1 && this->m_day > _SizeMonth[this->m_month - 1] || this->m_day < 0)); //Điều kiện dùng của vòng lặp nhập thời gian
}

void Date::Export()
{
	cout << this->m_day << '/' << this->m_month << '/' << this->m_year; //Xuất ngày tháng năm ra màn hình
}

int Date::GetM()
{
	return this->m_month;
}

int Date::getD()
{
	return this->m_day;
}

int Date::GetY()
{
	return this->m_year;
}

void Date::setD(int d)
{
	this->m_day = d;
}
void Date::setM(int m)
{
	this->m_month = m;
}
void Date::setY(int y)
{
	this->m_year = y;
}

bool CheckYear(int year)
{
	if(year % 400 == 0) //Nếu năm đó chia hết cho 400 thì là năm nhuận
		return 1;
	if(year % 100 != 0 && year % 4) //nếu năm đó chia hết cho 4 nhưng không chia hết cho 100 thì là năm nhuận, vì điều kiện chia hết cho 400 đã xét
		return 1;
	return 0; //Nếu không thỏa mãn điều kiện thì thoát hàm.
}