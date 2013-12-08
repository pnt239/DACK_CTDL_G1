#pragma once
#include "Ctour.h"

void Ctour::Set_ID(UINT id)
{
	this->m_ID = id;
}
void Ctour::Set_Place(string place)
{
	this->m_Place = place;
}
void Ctour::Set_Trans(Clist<UINT> trans)
{
	this->m_Trans = trans;
}
void Ctour::Set_Customers(Clist<UINT> customers)
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
Clist<UINT> Ctour::Get_Trans()
{
	return this->m_Trans;
}

Clist<UINT> Ctour::Get_Customers()
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

void Ctour::ShowClist(Clist<UINT> a)
{
	a.Show();
}