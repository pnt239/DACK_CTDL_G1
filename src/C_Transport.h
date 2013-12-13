#include "Transport.h"
#pragma once

class CCar:public CTransport
{
private:
	int m_CostCar; // chi phí xe hơi
public:
	CCar();
	~CCar();
	void setCostCar(int costCar);
	int getCostCar();
	void SetCar(); // cụ thể hoá các thuộc tính của xe hơi
};

class CTrain:public CTransport
{
private:
	int m_CostTrain; // chi phí tàu hoả
public:
	//CTrain();
	//~CTrain();
	void setCostTrain(int costCar);
	int getCostTrain();
	void SetTrain(); // cụ thể hoá các thuộc tính của tàu hoả
};

class CPlane:public CTransport
{
private:
	int m_CostPlane; // chi phí máy bay
public:
	//CPlane();
	//~CPlane();
	void setCostPlane(int costPlane);
	int getCostPlane();
	float Get_LossGar();
	void setPlane(); // cụ thể hoá các thuộc tính của máy bay
};