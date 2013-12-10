#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
#define MAX 100
#define VO_CUC 32760


class DiaDiem
{
private:
	INT m_Dinh;
	INT m_L[MAX][MAX];
public:
	void DocFile(string m_fileName);
	void KhoiTao(INT m_T[], INT m_nhan[],INT m_doDai[], INT m_dinhA);
	void TimDuong(INT m_T[], INT m_nhan[],INT m_doDai[], INT m_dinhA, INT m_dinhC);
	INT ChiPhi();
	void DanhSach();
};

void DiaDiem::DocFile(string m_fileName)
{
	fstream f;
	f.open(m_fileName , ios_base::in);
		f>>this->m_Dinh;
		for(INT i = 0;i < this->m_Dinh;i++)
			for(INT j = 0;j < this->m_Dinh;j++)
				f>>this->m_L[i][j];
	f.close();
}

//hàm khởi tạo các giá trị ban đầu cho thuật toán dijstra
void DiaDiem::KhoiTao( INT m_T[], int m_nhan[],INT m_doDai[], INT m_dinhA)
{
	for(INT i = 0;i < this->m_Dinh;i++)
	{
		m_T[i] = 1;
		m_nhan[i] = -1;
		m_doDai[i] = VO_CUC;
	}
	m_doDai[m_dinhA-1] = 0;
	m_T[m_dinhA-1] = 0;
}

//hàm tìm đường ngắn nhất từ 2 đỉnh bất kỳ
void DiaDiem::TimDuong( INT m_T[], INT m_nhan[],INT m_doDai[], INT m_dinhA, INT m_dinhC)
{
	this->KhoiTao( m_T, m_nhan, m_doDai, m_dinhA);//gọi hàm khởi tạo giá trị
	for(INT i = 0;i < this->m_Dinh;i++)
	{
		if(this->m_L[m_dinhA-1][i] > 0)
			m_doDai[i] = this->m_L[m_dinhA-1][i];
	}
	while(m_T[m_dinhC-1] != 0)
	{
		INT m_temp = -1;
		INT m_min = VO_CUC;
		//tìm giá trị nhỏ nhất trong các cạnh nối
		for(INT i = 0;i < this->m_Dinh;i++)
		{
			if(m_T[i] != 0 && m_min > m_doDai[i])
			{
				m_min = m_doDai[i];
				m_temp = i;
			}
		}
		if(m_temp == -1)//trường hợp không tìm thấy đường đi
		{
			cout<<"khong tim thay!"<<endl;
			break;
		}
		m_T[m_temp] = 0;//đánh dấu đỉnh temp đã xét
		for(INT j = 0;j < this->m_Dinh;j++)//xét các cạnh liền kề
		{
			if(this->m_L[m_temp][j] > 0 && m_doDai[j] > m_doDai[m_temp] + this->m_L[m_temp][j])
			{
				m_doDai[j] = m_doDai[m_temp] + this->m_L[m_temp][j];
				m_nhan[j] = m_temp;
			}
		}
	}
}

INT DiaDiem::ChiPhi()
{
	INT m_sl = 0, m_dai = 0, m_post = -1, m_T[MAX], m_nhan[MAX], m_doDai[MAX], m_temp = 0, m_khu = 0;
	this->DanhSach();
	cout<<"so luong diem don khach: ";
	cin>>m_sl;
	for(INT i = 0;i < m_sl;i++)
	{
		cout<<"nhap dia diem don khach thu "<<i+1<<" : ";
		cin>>m_post;
		this->TimDuong( m_T, m_nhan, m_doDai, m_post,1);
		m_dai += m_doDai[0];
		cout<<m_doDai[0]<<endl;
	}
	do
	{
		cout<<"phuong tien di chuyen: ";
		cin>>m_khu;
		if(m_khu == 7)
			m_dai += 6;
		else if(m_khu == 8)
			m_dai += 7;
	}while(m_khu < 7 || m_khu > 8);
	do
	{
		cout<<"Khu du lich: ";
		cin>>m_temp;
		if(m_temp == 9)
		{
			if(m_khu == 7)
				m_dai += 10;
			else m_dai += 13;
		}
		else if(m_temp == 10)
		{
			if(m_khu == 7)
				m_dai += 13;
			else m_dai += 12;
		}
		else if(m_temp == 11)
		{
			if(m_khu == 7)
				m_dai += 17;
			else m_dai += 18;
		}
		else if(m_temp == 12)
		{
			if(m_khu == 7)
				m_dai += 19;
			else m_dai += 20;
		}
	}while(m_temp < 9 || m_temp > 12);
	return m_dai;
}

void DiaDiem::DanhSach()
{
	cout<<"\tvi tri don khach: "<<endl
		<<"2. Quan 1."<<endl
		<<"3. Quan 5."<<endl
		<<"4. Quan 7."<<endl
		<<"5. Go Vap."<<endl
		<<"6. Quan 9."<<endl
		<<"\tPhuong tien: "<<endl
		<<"7. xe khach."<<endl
		<<"8. may bay."<<endl
		<<"\tKhu du lich:"<<endl
		<<"9. Nha Trang."<<endl
		<<"10. Da Lat."<<endl
		<<"11. Da Nang."<<endl
		<<"12. Ha Long."<<endl<<endl;
}

void main()
{
	DiaDiem p;
	string m_fileName = "diaDiem.txt";
	p.DocFile(m_fileName);
	cout<<"chi phi la: "<<p.ChiPhi()<<endl;
	system("pause");
}