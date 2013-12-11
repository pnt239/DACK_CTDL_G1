#pragma once
#include "TransportManager.h"

void TransportManager::Set_Transport(CList<CTransport> transport)
{
	this->m_Transport = transport;
}
CList<CTransport> TransportManager::Get_Transport()
{
	return this->m_Transport;
}
