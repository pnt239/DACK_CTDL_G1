#pragma once
#include "TransportManager.h"

void TransportManager::Set_Transport(Clist<CTransport> transport)
{
	this->m_Transport = transport;
}
Clist<CTransport> TransportManager::Get_Transport()
{
	return this->m_Transport;
}
