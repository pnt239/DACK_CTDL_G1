#pragma once
#include <windows.h>
#include <ustring.h>



// A point of graph
class CPlace
{
private:
	ustring m_name;
	INT m_x;
	INT m_y;
public:
	CPlace();
	~CPlace();
	CPlace(ustring s);
	void setName(ustring name);
	ustring getName();
	void setX(INT x);
	void setY(INT y);
	INT getX();
	INT getY();
};