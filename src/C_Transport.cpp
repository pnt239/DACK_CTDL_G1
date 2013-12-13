#include"C_Transport.h"


// Viết các hàm trong lớp car
//CCar::CCar()
//{
//	this->m_CostCar = 0;
//	CTransport::CTransport();
//}
//
//CCar::~CCar()
//{
//	CTransport::~CTransport();
//}

void CCar::setCostCar(int costCar)
{
	this->m_CostCar = costCar;
}

int CCar::getCostCar()
{
	return this->m_CostCar;
}

void CCar::SetCar()
{
	this->setCostCar(500000); // chi phí là 500 000 vnd
	this->Set_Seat(50); // xe loại 50 chỗ ngồi
	this->Set_LossGar(0.5); // độ hao xăng là 0.5 l/km
}

////////////////////////////////////////////////////////////////////////////

// viết các hàm trong lớp Train
//CTrain::CTrain()
//{
//	this->m_CostTrain = 0;
//	CTransport::CTransport();
//}
//
//CTrain::~CTrain()
//{
//	CTransport::~CTransport();
//}

void CTrain::setCostTrain(int costTrain)
{
	this->m_CostTrain = costTrain;
}

int CTrain::getCostTrain()
{
	return this->m_CostTrain;
}

void CTrain::SetTrain()
{
	this->setCostTrain(700000); // chi phí tàu hoả là 700 000 vnd
	this->Set_Seat(400); // tàu hoả có thể chở 400 người
	this->Set_LossGar(1.2); // độ hao xăng là 1.2 l/km
}

////////////////////////////////////////////////////////////////////////////

// viết các hàm trong lớp Plane

//CPlane::CPlane()
//{
//	this->m_CostPlane = 0;
//	CTransport::CTransport();
//}
//
//CPlane::~CPlane()
//{
//	CTransport::~CTransport();
//}

void CPlane::setCostPlane(int costPlane)
{
	this->m_CostPlane = costPlane;
}

int CPlane::getCostPlane()
{
	return this->m_CostPlane;
}

void CPlane::setPlane()
{
	this->setCostPlane(900000); // chi phí của máy bay là 900 000 vnd
	this->Set_Seat(200); // máy bay có 200 chỗ ngồi
	this->Set_LossGar(1.5); // độ hao xăng là 1.5 l/km
}