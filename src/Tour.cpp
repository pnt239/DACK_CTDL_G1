#include "Tour.h"
using namespace std;

CTour::CTour()
{
}

CTour::~CTour()
{

}

void CTour::setID(UINT id)
{
	this->m_id = id;
}
void CTour::setPlace(UINT place)
{
	this->m_placeId = place;
}
void CTour::setTimeStart(CDate time)
{
	this->m_timeStart = time;
}
void CTour::setTimeEnd(CDate time)
{
	this->m_timeEnd = time;
}

void CTour::setName(ustring name)
{
	this->m_name = name;
}

UINT CTour::getID()
{
	return this->m_id;
}
UINT CTour::getPlace()
{
	return this->m_placeId;
}
CDate CTour::getTimeStart()
{
	return this->m_timeStart;
}
CDate CTour::getimeEnd()
{
	return this->m_timeEnd;
}

ustring CTour::getName()
{
	return this->m_name;
}