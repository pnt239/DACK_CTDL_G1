#include<iostream>
#include<Windows.h>
#include <Tour.h>
#include <List.h>
using namespace std;
// File khong can cho chu C o dau
class CDuLich
{
private:
	Clist<Ctour*> p;
public:
	Ctour *searchTour(UINT m_id);
	Ctour *searchTour(string Place);
};

//
Ctour *CDuLich::searchTour(UINT m_id)
{
	for(int i = 0;i < this->p.Size();i++)
	{
		if(this->p.getHead()->Get_ID() == m_id)
			return this->p.getHead();
	}
	return NULL;
}

//
Ctour *CDuLich::searchTour(string Place)
{
	for(int i = 0;i < this->p.Size();i++)
	{
		if(this->p.getHead()->Get_Place() == Place)
			return this->p.getHead();
	}
	return NULL;
}

void main()
{
	system("pause");
}