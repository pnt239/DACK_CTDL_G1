#pragma once
#include <windows.h>
#include <string>

// A point of graph
class CPlace
{
private:
	std::string m_name;
	INT m_x;
	INT m_y;
public:
	CPlace();
	~CPlace();

	void setName(std::string name);
	std::string getName();
	void setX(INT x);
	void setY(INT y);
	INT getX();
	INT getY();
};