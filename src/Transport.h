#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

static vector<string> ListNumplate;

class CTransport
{
protected:
	UINT id;
	UINT m_Vehicles;		//loại xe nào? 
	string m_NumPlate;		//biển số xe;
	UINT m_Seat;				//số chỗ ngồi

	float m_Gasoline;		//lượng xăng
	float m_FuelTank;		//dung tích bình xăng
	float m_LossGar;		//độ hao xăng
	string m_Status;		//tinh trang hien tai
	UINT m_Tourcode;		//mã tour
public:
	CTransport();
	~CTransport();
	void Set_Vehicles(UINT vehicles);
	void Set_NumPlate(string numplate);
	void Set_Seat(UINT num);
	void Set_Gasoline(float gasoline);
	void Set_FuelTank(float fuel);
	void Set_LossGar(float lossgar);
	void Set_Status(string sts);
	void set_Tourcode(UINT tourID);
	void set_ID(UINT id);

	UINT Get_Vehicles();
	string Get_NumPlate();
	UINT Get_Seat();
	float Get_Gasoline();
	float Get_FuelTank();
	float Get_LossGar();
	string Get_Status();
	UINT get_Tourcode();
	UINT getID();

	bool Compare_Numplate();
	void ImportAll();
	void ExportAll();
	bool Move(float km);
};
