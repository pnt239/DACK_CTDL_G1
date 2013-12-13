#pragma once
#include "CMap.h"

using namespace std;

CMap::CMap()
{
}


CMap::~CMap()
{
}

void CMap::AddMap(CPlace* s)
{
	this->m_map.add(s);
}

//so sanh xem địa điểm vừa nhập vào có trong danh sách trước hay chưa
INT CMap::search(ustring s)
{
	for(INT i = 0; i < this->m_map.size() - 1; i++)
		if(s.compare(this->m_map[i]->getName()) == 0)
			return this->m_map[i]->getID();
	return -1;
}

void CMap::creatArr()
{
	this->m_Arr = new float *[this->m_n];
	for(INT i = 0; i < this->m_n; i++)
	{
		this->m_Arr[m_n] = new float[m_n];
	}
	for(INT i = 0; i < this->m_n; i++)
	{
		for(INT j = 0; j < this->m_n; j++)
		{
			this->m_Arr[i][j] = 0;
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
				f >> this->m_Arr[i][j];
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
void CMap::addTop(ustring name)
{
	if(this->search(name) == -1)		//nếu đỉnh đó đã có thì bỏ qua
		return;
	CPlace *place = new CPlace(name);
	place->setID(m_n);

	m_map.add(place);

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
		if(this->m_Arr[t][this->m_n - 1] != 0)
			this->m_Arr[t][this->m_n - 1] = this->m_Arr[this->m_n - 1][t] = rand() % 1001;
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
	//this->addTop();
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
	return true;
}