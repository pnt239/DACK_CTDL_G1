#pragma once
#include <windows.h>
#include <string>
#include "List.h"
#include "Date.h"

class CPlace{};

class CTour
{
private:
	UINT m_id;
	CPlace &m_place; // Dia diem cua diem du lich, co tham chieu!
	CDate m_timeStart;
	CDate m_timeEnd;
	std::string m_name; // ten tour
public:
	void setID(UINT id);
	void setPlace(string place);
	void setTimeStart(Date time);
	void setTimeEnd(Date time);

	UINT getID();
	CPlace &getPlace(); // co tham chieu!
	Date getTimeStart();
	Date getimeEnd();
};