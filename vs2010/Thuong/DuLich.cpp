#include <Tour.h>
#include <List.h>
#include <CCustomer.h>
#include <Officer.h>
#include <Transport.h>
#include <ustring.h>
using namespace std;
// File khong can cho chu C o dau

class CDuLich
{
private:
	CList<CTour*> m_tour;
	CList<CCustomer*> m_customer;
	CList<COfficer*> m_officer;
	CList<CTransport*> m_Transport;

	CList<COfficer*> m_off;
	CList<CCustomer*> m_cus;
	CList<CTransport*> m_Trans;
public:
	CTour *searchTour(UINT m_id);
	CTour *searchTour(ustring Place);

	CList<COfficer*> searchListOfficer(UINT TourCode);
	CList<CTransport*> searchListTransport(UINT TourCode);
	CList<CCustomer*> searchListCustomer(UINT TourCode);

	COfficer* searchOfficer(UINT ID);
	COfficer* searchOfficer(ustring name);

	CCustomer* searchCustomer(UINT ID);
	CCustomer* searchCustomer(ustring name);

	CTransport* searchTransport(UINT TourCode);
	CTransport* searchTransport(ustring name);

	void creatTour( ustring place, CDate m_timeStart, CDate m_timeEnd, ustring m_name);
};

//tìm kiếm tour qua ID
CTour *CDuLich::searchTour(UINT id)
{
	for(int i = 0; i < this->m_tour.size();i++)
		if(this->m_tour[i]->getID() == id)
			return this->m_tour[i];
	return NULL;
}

//tìm kiếm tour qua tên tour
CTour *CDuLich::searchTour(ustring Place)
{
	for(int i = 0;i < this->m_tour.size();i++)
		if(this->m_tour[i]->getName().compare(Place))
			return this->m_tour[i];
	return NULL;
}

//tìm kiếm khách hàng qua ID
CCustomer *CDuLich::searchCustomer(UINT m_id)
{
	for(int i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getID() == m_id)
			return this->m_customer[i];
	return NULL;
}
//tìm kiếm khách hàng qua tên
CCustomer *CDuLich::searchCustomer(ustring name)
{
	for(int i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getName().compare(name))
			return this->m_customer[i];
	return NULL;
}

//tìm phương tiện qua id

//tìm kiếm danh sách nhân viên qua ID
CList<COfficer*> CDuLich::searchListOfficer(UINT TourCode)
{
	for(int i = 0;i < this->m_officer.size();i++)
		if(this->m_officer[i]->getTourCode() == TourCode)
			this->m_off.push(this->m_officer[i]);
	return this->m_off;
}

//search danh sách CCustomer
CList<CCustomer*>  CDuLich::searchListCustomer(UINT TourCode)
{
	for(int i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getTourCode() == TourCode)
			this->m_cus.push(this->m_customer[i]);
	return this->m_cus;
}

//tìm kiếm sanh sách phương tiện qua id
CList<CTransport*> CDuLich::searchListTransport(UINT TourCode)
{
	for(int i = 0;i < this->m_Transport.size();i++)
		if(this->m_Transport[i]->get_Tourcode() == TourCode)
			this->m_Trans.push(this->m_Transport[i]);
	return this->m_Trans;
}

void CDuLich::creatTour(ustring place,CDate m_timeStart, CDate m_timeEnd, ustring m_name)
{
	CTour* m_newTour = new CTour();
	UINT placeCode;
	// tìm kiếm địa điểm place này đã tồn tài chưa
	if ((placeCode = CMap.search(place)) > -1)
	{
		// nếu mà không có thì add vào
		CMap.add(place);
	}

	m_newTour->setPlace(place);
	m_newTour->setTimeStart(m_timeStart);
	m_newTour->setTimeEnd(m_timeEnd);
	m_newTour->setName(m_name);
}

void main()
{
	system("pause");
}