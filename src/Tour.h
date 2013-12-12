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
	CTour();
	~CTour();

	void setID(UINT id);
	void setPlace(CPlace& place);
	void setTimeStart(CDate time);
	void setTimeEnd(CDate time);

	UINT getID();
	CPlace &getPlace(); // co tham chieu!
	CDate getTimeStart();
	CDate getimeEnd();
};