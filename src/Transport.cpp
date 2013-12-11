#include "Transport.h"

CTransport::CTransport()
{
	this->m_FuelTank = 5;
	this->m_Gasoline = 5;
	this->m_LossGar = 0.5;
	this->m_NumPlate = "";
	this->m_Status = "";
	this->m_Vehicles = 0;
	this->m_Seat = 2;
}

CTransport::~CTransport()
{
	this->m_FuelTank = 0;
	this->m_Gasoline = 0;
	this->m_LossGar = 0;
	this->m_NumPlate.clear();
	this->m_Status.clear();
	this->m_Vehicles = 0;
	this->m_Seat = 0;
}

void CTransport::Set_Vehicles(int vehicles)
{
	this->m_Vehicles = vehicles;
}
void CTransport::Set_NumPlate(string numplate)
{
	this->m_NumPlate = numplate;
}
void CTransport::Set_Seat(int num)
{
	this->m_Seat = num;
}

void CTransport::Set_Gasoline(float gasoline)
{
	this->m_Gasoline = gasoline;
}
void CTransport::Set_FuelTank(float fuel)
{
	this->m_FuelTank = fuel;
}
void CTransport::Set_LossGar(float lossgar)
{
	this->m_LossGar = lossgar;
}

void CTransport::Set_Status(string sts)
{
	this->m_Status = sts;
}

int CTransport::Get_Vehicles()
{
	return this->m_Vehicles;
}

string CTransport::Get_NumPlate()
{
	return this->m_NumPlate;
}
int CTransport::Get_Seat()
{
	return this->m_Seat;
}
float CTransport::Get_Gasoline()
{
	return this->m_Gasoline;
}
float CTransport::Get_FuelTank()
{
	return this->m_FuelTank;
}
float CTransport::Get_LossGar()
{
	return this->m_LossGar;
}

string CTransport::Get_Status()
{
	return this->m_Status;
}

bool CTransport::Compare_Numplate()
{
	bool test = true;
	for(int i = 0; i < ListNumplate.size(); i++)
	{
		if(this->m_NumPlate.compare(ListNumplate[i]) == 0)
		{
			test = 0;
			break;
		}
	}
	return test;
}

bool CTransport::Move(float km)
{
	float tmp;
	tmp = this->m_LossGar * km;
	if(tmp > this->m_Gasoline)
		return false;
	float gar = this->Get_Gasoline();
	this->Set_Gasoline(gar - tmp);
	return true;
}
void CTransport::ImportAll()
{
	string name;
	cout << "\nNhap vao bien so xe: ";
	do
	{
		fflush(stdin);
		getline(cin, this->m_NumPlate);
		if(this->Compare_Numplate() == false)
			cout << "\nBien so trung. Moi ban nhap lai: ";
	}while(this->Compare_Numplate() == false);
	int x;
	cout << "\nMoi ban nhap vao loai xe. (Nhap dung: 1, xe may; 2 - xe o to; 3 - xe bus; 4- may bay): ";
	cin >> x;
	this->Set_Vehicles(x);
	int n;
	cout << "\nXe co bao nhieu cho ngoi?: ";
	cin >> n;
	this->Set_Seat(n);
	float gar;
	cout << "\nNhap vao dung tich binh xang: ";
	cin >> gar;
	this->Set_FuelTank(gar);
	cout << "\nNhap vao luong xang hien co trong binh: ";
	cin >> gar;
	this->Set_Gasoline(gar);
	if(this->Get_Gasoline() >= this->Get_FuelTank()/2)
		this->Set_Status("Luong xang van on.");
	else
		this->Set_Status("Luong xang be hon 1/2 binh. Ban nen do xang");
	cout << "\nNhap vao do hao phi xang: ";
	cin >> gar;
	this->Set_LossGar(gar);
}
void CTransport::ExportAll()
{
	if(this->m_Vehicles == 1)
		cout << "motorcycle.";
	else
		if(this->m_Vehicles == 2)
			cout << "Car.";
			else
				if(this->m_Vehicles == 3)
					cout << "Bus.";
				else
					if(this->m_Vehicles == 4)
						cout << "Aircraft.";
	cout << "\t" << this->m_NumPlate;
	cout << "\t" << this->m_FuelTank;
	cout << "\t" << this->m_Gasoline;
	cout << "\t" << this->m_LossGar;
	cout << "\t" << this->m_Seat;;
	cout << "\t" << this->m_Status;
}