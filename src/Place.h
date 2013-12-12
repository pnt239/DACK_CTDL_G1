#pragma once
#include <windows.h>
#include <string>

// A point of graph
class CPlace
{
private:
	std::string m_name;
public:
	CPlace();
	~CPlace();
	void setName(std::string name);
	std::string getName();
};