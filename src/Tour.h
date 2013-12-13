#pragma once
#include <windows.h>
#include <string>
#include "List.h"
#include "Date.h"
#include "Place.h"

//class CPlace{};

class CTour
{
private:
	UINT m_id;
	UINT m_placeId;
	CDate m_timeStart;
	CDate m_timeEnd;
	ustring m_name; // ten tour
public:
	CTour();
	~CTour();

	void setID(UINT id);
	void setPlace(UINT placeID);
	void setTimeStart(CDate time);
	void setTimeEnd(CDate time);
	void setName(ustring name);

	UINT getID();
	UINT getPlace();
	CDate getTimeStart();
	CDate getimeEnd();
	ustring getName();
};