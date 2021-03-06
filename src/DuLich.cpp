﻿#include "DuLich.h"

//tìm kiếm tour qua ID
CTour *CDuLich::searchTour(UINT id)
{
	for(UINT i = 0; i < this->m_tour.size();i++)
		if(this->m_tour[i]->getID() == id)
			return this->m_tour[i];
	return NULL;
}

//tìm kiếm tour qua tên tour
CTour *CDuLich::searchTour(ustring Place)
{
	for(UINT i = 0;i < this->m_tour.size();i++)
		if(this->m_tour[i]->getName().compare(Place) == 0)
			return this->m_tour[i];
	return NULL;
}

//tìm kiếm khách hàng qua ID
CCustomer *CDuLich::searchCustomer(UINT m_id)
{
	for(UINT i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getID() == m_id)
			return this->m_customer[i];
	return NULL;
}
//tìm kiếm khách hàng qua tên
CCustomer *CDuLich::searchCustomer(ustring name)
{
	for(UINT i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getName().compare(name) == 0)
			return this->m_customer[i];
	return NULL;
}

//tìm phương tiện qua id
CTransport* CDuLich::searchTransport(UINT ID)
{
	for(UINT i = 0; i < this->m_Transport.size();i++)
		if(this->m_Transport[i]->getID() == ID)
			return this->m_Transport[i];
	return NULL;
}

//tìm phương tiện qua biển số
CTransport* CDuLich::searchTransport(ustring numPlate)
{
	for(UINT i = 0; i < this->m_Transport.size();i++)
		if(this->m_Transport[i]->Get_NumPlate().compare(numPlate) == 0)
			return this->m_Transport[i];
	return NULL;
}

//tìm kiếm danh sách nhân viên qua ID
CList<COfficer*> CDuLich::searchListOfficer(UINT TourCode)
{
	for(UINT i = 0;i < this->m_officer.size();i++)
		if(this->m_officer[i]->getTourCode() == TourCode)
			this->m_off.push(this->m_officer[i]);
	return this->m_off;
}

//search danh sách CCustomer
CList<CCustomer*>  CDuLich::searchListCustomer(UINT TourCode)
{
	for(UINT i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getTourCode() == TourCode)
			this->m_cus.push(this->m_customer[i]);
	return this->m_cus;
}

//tìm kiếm sanh sách phương tiện qua id
CList<CTransport*> CDuLich::searchListTransport(UINT TourCode)
{
	for(UINT i = 0;i < this->m_Transport.size();i++)
		if(this->m_Transport[i]->get_Tourcode() == TourCode)
			this->m_Trans.push(this->m_Transport[i]);
	return this->m_Trans;
}

//tạo 1 tour mới
void CDuLich::creatTour(ustring place,CDate m_timeStart, CDate m_timeEnd, ustring m_name)
{
	CTour* m_newTour = new CTour();
	INT placeCode;
	
	// tìm kiếm địa điểm place này đã tồn tài chưa
	if ((placeCode = m_map.search(place)) == 1)
	{
		// nếu mà không có thì add vào
		m_map.addTop(place);
	}
	m_newTour->setPlace(placeCode);
	m_newTour->setTimeStart(m_timeStart);
	m_newTour->setTimeEnd(m_timeEnd);
	m_newTour->setName(m_name);
	this->m_tour.push(m_newTour);
}

//thêm nhân viên
void CDuLich::creatOfficer(UINT id, ustring name, ustring phone,ustring passport, UINT tourCode, ustring transportCode)
{
	COfficer* m_newOff = new COfficer();
	m_newOff->setID(id);
	m_newOff->setName(name);
	m_newOff->setPhone(phone);
	m_newOff->setPassport(passport);
	m_newOff->setTourCode(tourCode);
	m_newOff->setTransportCode(transportCode);
	this->m_officer.push(m_newOff);
}

//thêm khách hàng
void CDuLich::creatCustomer(UINT id, ustring name, ustring phone, ustring passport, UINT tourCode, UINT placeCode)
{
	CCustomer* m_newCus = new CCustomer();
	m_newCus->setID(id);
	m_newCus->setName(name);
	m_newCus->setPhone(phone);
	m_newCus->setPassport(passport);
	m_newCus->setTourCode(tourCode);
	m_newCus->setPlaceCode(placeCode);
	this->m_customer.push(m_newCus);
}

//thêm phương tiện
void CDuLich::creatTransport(UINT id, UINT Vehicles, ustring NumPlate, UINT Seat,float Gasoline,float FuelTank,float LossGar,ustring Status,UINT Tourcode)
{
	CTransport* m_newTrans = new CTransport();
	m_newTrans->set_ID(id);
	m_newTrans->Set_Vehicles(Vehicles);
	m_newTrans->Set_NumPlate(NumPlate);
	m_newTrans->Set_Seat(Seat);
	m_newTrans->Set_Gasoline(Gasoline);
	m_newTrans->Set_FuelTank(FuelTank);
	m_newTrans->Set_LossGar(LossGar);
	m_newTrans->Set_Status(Status);
	m_newTrans->set_Tourcode(Tourcode);
	this->m_Transport.push(m_newTrans);
}

void main()
{
	system("pause");
}

void CDuLich::removeCustomer(UINT ID)
{
	for(UINT i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getID() == ID)
		{
			this->m_customer.remove(i);
			return;
		}
}
void CDuLich::removeTour(UINT m_id)
{
	for(UINT i = 0; i < this->m_tour.size();i++)
		if(this->m_tour[i]->getID() == m_id)
		{
			this->m_tour.remove(i);
			return;
		}
}
void CDuLich::removeTranspost(UINT ID)
{
	for(UINT i = 0; i < this->m_Transport.size();i++)
		if(this->m_Transport[i]->getID() == ID)
		{
			this->m_Transport.remove(i);
			return;
		}
}