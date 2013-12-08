#include "Library.h"

static vector<string> ListNumplate;

class CTransport
{
protected:
	int m_Vehicles;		//loại xe nào? 
	string m_NumPlate;		//biển số xe;
	int m_Seat;				//số chỗ ngồi
	float m_Gasoline;		//lượng xăng
	float m_FuelTank;		//dung tích bình xăng
	float m_LossGar;		//độ hao xăng
	string m_Status;		//tinh trang hien tai
public:
	CTransport();
	~CTransport();
	void Set_Vehicles(int vehicles);
	void Set_NumPlate(string numplate);
	void Set_Seat(int num);
	void Set_Gasoline(float gasoline);
	void Set_FuelTank(float fuel);
	void Set_LossGar(float lossgar);
	void Set_Status(string sts);

	int Get_Vehicles();
	string Get_NumPlate();
	int Get_Seat();
	float Get_Gasoline();
	float Get_FuelTank();
	float Get_LossGar();
	string Get_Status();

	bool Compare_Numplate();
	void ImportAll();
	void ExportAll();
	bool Move(float km);
};