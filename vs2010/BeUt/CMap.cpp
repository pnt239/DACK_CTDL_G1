#pragma once
#include <iostream>
#include "CMap.h"

using namespace std;

CMap::CMap()
{
}


CMap::~CMap()
{

}

void CMap::setNew(ustring s)
{
	this->m_new = new CPlace(s);
}

ustring CMap::getNew()
{
	return this->m_new->getName();
}


void CMap::AddMap(CPlace* s)
{
	this->m_map.add(s);
}

//so sanh xem địa điểm vừa nhập vào có trong danh sách trước hay chưa
bool CMap::Compare()
{
	bool test = 0;
	for(INT i = 0; i < this->m_map.size(); i++)
	{
		if(this->getNew().compare(this->m_map[i]->getName()) == 0)
		{
			test = 1;
			break;
		}
	}
	this->AddMap(this->m_new);
	if(test == 0)
		return 0;
	else
		return 1;
}

void CMap::creatArr()
{
	this->m_Arr = new float *[this->m_n];
	for(INT i = 0; i < this->m_n; i++)
	{
		this->m_Arr[i] = new float[m_n];
		for(INT j = 0; j < this->m_n; j++)
		{
			this->m_Arr[i][j] = 0;	//no break o day lun	
		}
	}
}

//đọc file Map.txt
bool CMap::readGraph(char* name)
{
	fstream f;
	f.open(name, ios_base::in);
	if(!f.is_open())
	{
		m_n = 0;
		return false;
	}
	while(!f.eof())
	{
		f >> this->m_n;
		this->creatArr();
		for(INT i = 0; i < m_n; i++)
			for(INT j = 0; j < m_n; j++)
			{
				float t;
				f >> t;
				this->m_Arr[i][j] = t;
			}
	}
	f.close();
	return true;
}

//viết kết quả ma trận lại file
void CMap::writeFile(char* name)
{
	fstream f;
	f.open(name, ios_base::out);
	f << this->m_n << endl;
	for(INT i = 0; i < this->m_n; i++)
	{
		for(INT j = 0; j < this->m_n; j++)
		{
			f << this->m_Arr[i][j] << " ";
		}
		f << endl;
	}
	f.close();
}

//thêm 1 đỉnh vào đồ thị
void CMap::addTop()
{
	if(this->Compare())		//nếu đỉnh đó đã có thì bỏ qua
		return;
	INT m = this->m_n;
	float tmp[100][100];
	for(INT i = 0; i < m; i++)
	{
		for(INT j = 0; j < m; j++)
		{
			tmp[i][j] = this->m_Arr[i][j];
		}
	}

	this->m_n += 1;
	this->creatArr();

	for(INT i = 0; i < m; i++)
	{
		for(INT j = 0; j < m; j++)
		{
			this->m_Arr[i][j] = tmp[i][j];
		}
	}

	INT t;
	srand(time(NULL));
	t = rand()%m;
	for(INT i = 0; i < t; i++)
	{
		t = rand()%m;
		this->m_Arr[t][this->m_n - 1] = this->m_Arr[this->m_n - 1][t] = rand() % 1001 + 100;
	}

	for(int i = 0; i < this->m_n; i++)
	{
		for(int j = 0; j < this->m_n; j++)
			cout << this->m_Arr[i][j] << " ";
		cout << endl;
	}
}

//tìm đường đi ngắn nhất trong ma trận
float CMap::findPathMin()
{
	INT li = -1;
	float p = INF;
	for(INT i = 0; i < this->m_n; i++)
	{
		if(Label[i] == 0 && Length[i] < p)
		{
			p = Length[i];
			li = i;
		}
	}
	return li;
}

//cập nhật đường đi
void CMap::UpdatePath(INT u)
{
	Label[u] = 1;
	for(INT i = 0; i < this->m_n; i++)
	{
		if(Label[i] == 0 && this->m_Arr[u][i] > 0 && this->m_Arr[u][i] < INF)	//dinh v chua xet va co noi voi u
			if(Length[i] > Length[u] + this->m_Arr[u][i])
			{
				Length[i] = Length[u] + this->m_Arr[u][i];
				Save[i] = u;
			}
	}
}
//tìm đường đi ngắn nhất
float CMap::finalPath(INT a, INT b)
{
	char * name = "Map.txt";
	this->readGraph(name);
	//this->show();
	this->addTop();
	INT i;
	for(INT i = 0; i < this->m_n; i++)
	{
		Label[i] = 0;
		Length[i] = INF;
		Save[i] = -1;
	}

	Length[a] = 0;
	while(Label[b] == 0)		//neu chua xet toi dinh cuoi thi tiep tuc
	{
		INT u = findPathMin();
		if(u == -1)
		{
			return false;
		}
		UpdatePath(u);
	}
	this->writeFile(name);
	return Length[b];
}

void CMap::show()
{
	for(int i = 0; i < this->m_n; i++)
	{
		for(int j = 0; j < this->m_n; j++)
			cout << this->m_Arr[i][j] << " ";
		cout << endl;
	}
}