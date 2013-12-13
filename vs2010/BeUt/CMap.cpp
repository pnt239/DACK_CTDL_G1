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

bool CMap::Compare(ustring s)
{
	bool test = 0;
	for(int i = 0; i < this->m_map.size() - 1; i++)
	{
		if(s.compare(this->m_map[i]->getName()) == 0)
		{
			test = 1;
			break;
		}
	}
	if(test == 0)
		return 0;
	else
		return 1;
}

void CMap::creatArr()
{
	this->m_Arr = new float *[this->m_n];
	for(int i = 0; i < this->m_n; i++)
	{
		this->m_Arr[m_n] = new float[m_n];
	}
	for(int i = 0; i < this->m_n; i++)
	{
		for(int j = 0; j < this->m_n; j++)
		{
			this->m_Arr[i][j] = 0;
		}
	}

}
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
		for(int i = 0; i < m_n; i++)
			for(int j = 0; j < m_n; j++)
			{
				f >> this->m_Arr[i][j];
			}
	}
	f.close();
	return true;
}

void CMap::writeFile(char* name)
{
	fstream f;
	f.open(name, ios_base::out);
	f << this->m_n << endl;
	for(int i = 0; i < this->m_n; i++)
	{
		for(int j = 0; j < this->m_n; j++)
		{
			f << this->m_Arr[i][j] << " ";
		}
		f << endl;
	}
	f.close();
}

void CMap::addTop()
{
	if(this->Compare(this->m_map[this->m_map.size()]->getName()))
		return;
	int m = this->m_n;
	float tmp[100][100];
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			tmp[i][j] = this->m_Arr[i][j];
		}
	}
	this->m_n += 1;
	this->creatArr();

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			this->m_Arr[i][j] = tmp[i][j];
		}
	}
	int t;
	srand(time(NULL));
	t = rand()%m;
	for(int i = 0; i < t; i++)
	{
		t = rand()%m;
		if(this->m_Arr[t][this->m_n - 1] != 0)
			this->m_Arr[t][this->m_n - 1] = this->m_Arr[this->m_n - 1][t] = rand() % 1001;
	}
}

float CMap::findPathMin()
{
	int li = -1;
	float p = INF;
	for(int i = 0; i < this->m_n; i++)
	{
		if(Label[i] == 0 && Length[i] < p)
		{
			p = Length[i];
			li = i;
		}
	}
	return li;
}
void CMap::UpdatePath(int u)
{
	Label[u] = 1;
	for(int i = 0; i < this->m_n; i++)
	{
		if(Label[i] == 0 && this->m_Arr[u][i] > 0 && this->m_Arr[u][i] < INF)	//dinh v chua xet va co noi voi u
			if(Length[i] > Length[u] + this->m_Arr[u][i])
			{
				Length[i] = Length[u] + this->m_Arr[u][i];
				Save[i] = u;
			}
	}
}
float CMap::finalPath(int a, int b)
{
	char * name = "Map.txt";
	this->readGraph(name);
	this->addTop();
	int i;
	for(int i = 0; i < this->m_n; i++)
	{
		Label[i] = 0;
		Length[i] = INF;
		Save[i] = -1;
	}

	Length[a] = 0;
	while(Label[b] == 0)		//neu chua xet toi dinh cuoi thi tiep tuc
	{
		int u = findPathMin();
		if(u == -1)
		{
			return false;
		}
		UpdatePath(u);
	}
	this->writeFile(name);
	return true;
}