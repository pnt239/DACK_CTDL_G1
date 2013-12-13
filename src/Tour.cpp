#include "Tour.h"
using namespace std;

//CTour::CTour()
//{
//}
CTour::~CTour()
{

}

void CTour::setID(UINT id)
{
	this->m_id = id;
}
void CTour::setPlace(ustring place)
{
	this->m_place.setName(place);
}
void CTour::setTimeStart(CDate time)
{
	this->m_timeStart = time;
}
void CTour::setTimeEnd(CDate time)
{
	this->m_timeEnd = time;
}

UINT CTour::getID()
{
	return this->m_id;
}
CPlace & CTour::getPlace()	//co tham chieu
{
	return this->m_place;
}
CDate CTour::getTimeStart()
{
	return this->m_timeStart;
}
CDate CTour::getimeEnd()
{
	return this->m_timeEnd;
}