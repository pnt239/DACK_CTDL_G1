#include <Tour.h>
#include <List.h>
#include <CCustomer.h>
#include <Officer.h>
#include <Transport.h>
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
public:
	CTour *searchTour(UINT m_id);
	CTour *searchTour(string Place);

	CList<COfficer*> searchListOfficer(UINT TourCode);
	CList<CTransport*> searchListTransport(UINT TourCode);;
	CList<CCustomer*> searchListCustomer(UINT TourCode);

	COfficer* searchOfficer(UINT ID);
	COfficer* searchOfficer(string name);
	CCustomer* searchCustomer(UINT ID);
	CCustomer* searchCustomer(string name);

	void creatTour( ustring place, CDate m_timeStart, CDate m_timeEnd, string m_name);
};

//tìm kiếm tour qua ID
CTour *CDuLich::searchTour(UINT m_id)
{
	for(int i = 0; i < this->m_tour.size();i++)
		if(this->m_tour[i]->getID() == m_id)
			return this->m_tour[i];
	return NULL;
}

//tìm kiếm tour qua tên tour
CTour *CDuLich::searchTour(string Place)
{
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
CCustomer *CDuLich::searchCustomer(string name)
{
	for(int i = 0;i < this->m_customer.size();i++)
		if(this->m_customer[i]->getName() == name)
			return this->m_customer[i];
	return NULL;
}

//tìm kiếm nhân viên qua ID
CList<COfficer*> CDuLich::searchListOfficer(UINT TourCode)
{
	for(int i = 0;i < this->m_officer.size();i++)
		if(this->m_officer[i]->getTourCode() == TourCode)
			this->m_off.push(this->m_officer[i]);
	return this->m_off;
}

void CDuLich::creatTour(ustring place,CDate m_timeStart, CDate m_timeEnd, string m_name)
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