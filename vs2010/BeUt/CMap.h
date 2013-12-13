#pragma once
#include "Place.h"
#include "List.h"
#include <fstream>
#include "ustring.h"
#include <time.h>
#define MAX 100
#define INF INT_MAX

class CMap
{
private:
	INT Save[MAX];
	INT Label[MAX];
	float Length[MAX];
	CPlace* m_new;		//lưu địa điểm mới
	CList<CPlace *> m_map;
	UINT m_n;		//số đỉnh của đồ thị 
	INT m_Place;
	float **m_Arr;	//ma trận lưu thông tin đồ thị
public:
	CMap();
	
	~CMap();
	void setNew(ustring s);
	ustring getNew();
	void AddMap(CPlace*);
	bool Compare();
	void creatArr();
	bool readGraph(char* name);
	void writeFile(char* name);
	void addTop();
	float findPathMin();
	void UpdatePath(INT u);
	float finalPath(INT a, INT b);
	void show();
};