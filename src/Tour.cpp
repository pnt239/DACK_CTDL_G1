#pragma once
#include "Tour.h"

void Ctour::Set_ID(UINT id)
{
	this->m_ID = id;
}
void Ctour::Set_Place(string place)
{
	this->m_Place = place;
}
void Ctour::Set_Trans(CList<UINT> trans)
{
	this->m_Trans = trans;
}
void Ctour::Set_Customers(CList<UINT> customers)
{
	this->m_Customers = customers;
}
void Ctour::Set_TimeStart(Date time)
{
	this->m_Time_Start = time;
}
void Ctour::Set_TimeEnd(Date time)
{
	this->m_Time_End = time;
}

UINT Ctour::Get_ID()
{
	return this->m_ID;
}
string Ctour::Get_Place()
{
	return this->m_Place;
}
CList<UINT> Ctour::Get_Trans()
{
	return this->m_Trans;
}

CList<UINT> Ctour::Get_Customers()
{
	return this->m_Customers;
}

Date Ctour::Get_TimeStart()
{
	return this->m_Time_Start;
}

Date Ctour::Get_TimeEnd()
{
	return this->m_Time_End;
}

void Ctour::ShowCList(CList<UINT> a)
{
	a.Show();
}