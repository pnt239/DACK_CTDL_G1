#include "Transport.h"

CTransport::CTransport()
{
	this->m_FuelTank = 5;
	this->m_Gasoline = 5;
	this->m_LossGar = 0.5;
	this->m_NumPlate.Set(L"");
	this->m_Status.Set(L"");
	this->m_Vehicles = 0;
	this->m_Seat = 2;
}

CTransport::~CTransport()
{
	this->m_FuelTank = 0;
	this->m_Gasoline = 0;
	this->m_LossGar = 0;
	this->m_NumPlate.clear();
	this->m_Status.clear();
	this->m_Vehicles = 0;
	this->m_Seat = 0;
}

void CTransport::Set_Vehicles(UINT vehicles)
{
	this->m_Vehicles = vehicles;
}
void CTransport::Set_NumPlate(ustring numplate)
{
	this->m_NumPlate = numplate;
}
void CTransport::Set_Seat(UINT num)
{
	this->m_Seat = num;
}

void CTransport::Set_Gasoline(float gasoline)
{
	this->m_Gasoline = gasoline;
}
void CTransport::Set_FuelTank(float fuel)
{
	this->m_FuelTank = fuel;
}
void CTransport::Set_LossGar(float lossgar)
{
	this->m_LossGar = lossgar;
}

void CTransport::Set_Status(ustring sts)
{
	this->m_Status = sts;
}

void CTransport::set_Tourcode(UINT tourcode)
{
	this->m_Tourcode = tourcode;
}

void CTransport::set_ID(UINT id)
{
	this->id = id;
}

UINT CTransport::Get_Vehicles()
{
	return this->m_Vehicles;
}

ustring CTransport::Get_NumPlate()
{
	return this->m_NumPlate;
}
UINT CTransport::Get_Seat()
{
	return this->m_Seat;
}
float CTransport::Get_Gasoline()
{
	return this->m_Gasoline;
}
float CTransport::Get_FuelTank()
{
	return this->m_FuelTank;
}
float CTransport::Get_LossGar()
{
	return this->m_LossGar;
}

ustring CTransport::Get_Status()
{
	return this->m_Status;
}

UINT CTransport::get_Tourcode()
{
	return this->m_Tourcode;
}

UINT CTransport::getID()
{
	return this->id;
}

bool CTransport::Compare_Numplate()
{
	bool test = true;
	for(UINT i = 0; i < ListNumplate.size(); i++)
	{
		if(this->m_NumPlate.compare(ListNumplate[i]) == 0)
		{
			test = 0;
			break;
		}
	}
	return test;
}

bool CTransport::Move(float km)
{
	float tmp;
	tmp = this->m_LossGar * km;
	if(tmp > this->m_Gasoline)
		return false;
	float gar = this->Get_Gasoline();
	this->Set_Gasoline(gar - tmp);
	return true;
}
