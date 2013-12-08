#pragma once
#include "CTransport.h"
#include "Clist.h"

class TransportManager
{
private:
	Clist<CTransport> m_Transport;		//danh sach cac loai xe
public:
	void Set_Transport(Clist<CTransport> transport);
	Clist<CTransport> Get_Transport();
};