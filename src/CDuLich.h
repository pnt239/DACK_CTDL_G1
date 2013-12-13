#include <Tour.h>
#include <List.h>
#include <CCustomer.h>
#include <Officer.h>
#include <Transport.h>
#include <ustring.h>
#include <CMap.h>
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

	CTransport* searchTransport(UINT ID);
	CTransport* searchTransport(ustring NumPlate);

	void creatTour( ustring place, CDate m_timeStart, CDate m_timeEnd, ustring m_name);
	void creatOfficer(UINT id, ustring name, ustring phone,ustring passport, UINT tourCode, ustring transportCode);
	void creatCustomer(UINT id, ustring name, ustring phone, ustring passport, UINT tourCode, UINT placeCode, ustring transportCode);
	void creatTransport(UINT id, UINT Vehicles, ustring NumPlate, UINT Seat,float Gasoline,float FuelTank,float LossGar,ustring Status,UINT Tourcode);
};