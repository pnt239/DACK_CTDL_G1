#pragma once
#include "Place.h"

CPlace::CPlace()
{
}
CPlace::~CPlace()
{
	this->m_name.clear();
}

CPlace::CPlace(ustring s)
{
	this->m_name = s;
}

void CPlace::setName(ustring name)
{
	this->m_name = name;
}
ustring CPlace::getName()
{
	return this->m_name;
}

void CPlace::setX(INT x)
{
	this->m_x = x;
}
void CPlace::setY(INT y)
{
	this->m_y = y;
}

void CPlace::setID(UINT id)
{
	this->m_id = id;
}
INT CPlace::getX()
{
	return this->m_x;
}
INT CPlace::getY()
{
	return this->m_y;
}

UINT CPlace::getID()
{
	return this->m_id;
}
//
//void Place::ReadFile(string fileName)
//{
//	fstream f;
//	f.open(fileName , ios_base::in);
//		f>>this->n;
//		for(int i = 0;i < this->n;i++)
//			for(int j = 0;j < this->n;j++)
//				f>>this->L[i][j];
//	f.close();
//}
//
////hàm khởi tạo các giá trị ban đầu cho thuật toán dijstra
//void Place::Creat(int T[], int label[],int length[], int A)
//{
//	for(int i = 0;i < this->n;i++)
//	{
//		T[i] = 1;
//		label[i] = -1;
//		length[i] = VOCUC;
//	}
//	length[A-1] = 0;
//	T[A-1] = 0;
//}
//
////hàm tìm đường ngắn nhất từ 2 đỉnh bất kỳ
//void Place::PathFind(int T[], int label[],int length[], int A, int C)
//{
//	this->Creat( T, label, length, A);//gọi hàm khởi tạo giá trị
//	for(int i = 0;i < this->n;i++)
//	{
//		if(this->L[A-1][i] > 0)
//			length[i] = this->L[A-1][i];
//	}
//	while(T[C-1] != 0)
//	{
//		int temp = -1;
//		int min = VOCUC;
//		//tìm giá trị nhỏ nhất trong các cạnh nối
//		for(int i = 0;i < this->n;i++)
//		{
//			if(T[i] != 0 && min > length[i])
//			{
//				min = length[i];
//				temp = i;
//			}
//		}
//		if(temp == -1)//trường hợp không tìm thấy đường đi
//		{
//			cout<<"khong tim thay!"<<endl;
//			break;
//		}
//		T[temp] = 0;//đánh dấu đỉnh temp đã xét
//		for(int j = 0;j < this->n;j++)//xét các cạnh liền kề
//		{
//			if(this->L[temp][j] > 0 && length[j] > length[temp] + this->L[temp][j])
//			{
//				length[j] = length[temp] + this->L[temp][j];
//				label[j] = temp;
//			}
//		}
//	}
//}
//
//int Place::Cost()
//{
//	int sl = 0, len = 0, post = -1, T[MAX], label[MAX], length[MAX], temp = 0, region = 0;
//	this->List();
//	cout<<"so luong diem don khach: ";
//	cin>>sl;
//	for(int i = 0;i < sl;i++)
//	{
//		cout<<"nhap dia diem don khach thu "<<i+1<<" : ";
//		cin>>post;
//		this->PathFind( T, label, length, post,1);
//		len += length[0];
//		cout<<length[0]<<endl;
//	}
//	do
//	{
//		cout<<"phuong tien di chuyen: ";
//		cin>>region;
//		if(region == 7)
//			len += 6;
//		else if(region == 8)
//			len += 7;
//	}while(region < 7 || region > 8);
//	do
//	{
//		cout<<"Khu du lich: ";
//		cin>>temp;
//		if(temp == 9)
//		{
//			if(region == 7)
//				len += 10;
//			else len += 13;
//		}
//		else if(temp == 10)
//		{
//			if(region == 7)
//				len += 13;
//			else len += 12;
//		}
//		else if(temp == 11)
//		{
//			if(region == 7)
//				len += 17;
//			else len += 18;
//		}
//		else if(temp == 12)
//		{
//			if(region == 7)
//				len += 19;
//			else len += 20;
//		}
//	}while(temp < 9 || temp > 12);
//	return len;
//}
//
//void Place::List()
//{
//	cout<<"\tvi tri don khach: "<<endl
//		<<"2. Quan 1."<<endl
//		<<"3. Quan 5."<<endl
//		<<"4. Quan 7."<<endl
//		<<"5. Go Vap."<<endl
//		<<"6. Quan 9."<<endl
//		<<"\tPhuong tien: "<<endl
//		<<"7. xe khach."<<endl
//		<<"8. may bay."<<endl
//		<<"\tKhu du lich:"<<endl
//		<<"9. Nha Trang."<<endl
//		<<"10. Da Lat."<<endl
//		<<"11. Da Nang."<<endl
//		<<"12. Ha Long."<<endl<<endl;
//}