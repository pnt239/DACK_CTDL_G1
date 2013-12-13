#pragma once
#include "List.h"
#include <iostream>
#include "CMap.h"
#include "Place.h"
using namespace std;

void main()
{
	CPlace *s = new CPlace(L"Thanh");
	CMap a;
	a.setNew(s->getName());
	float z =  a.finalPath(0, 4);
	cout << z;
}