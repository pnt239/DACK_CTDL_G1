#include "Database.h"
#include <fstream>
#include <Date.h>
#include <CCustomer.h>
using namespace std;

CDatabase::CDatabase()
{
}

CDatabase::~CDatabase()
{
}

void CDatabase::readCustomer(string fileCustomer)
{
	UINT ID; 
	ustring Name;
	int day, mon, year;
	ustring Phone; 
	ustring Passport;
	UINT TourCode;
	UINT PlaceCode;

	m_fileCustomer = fileCustomer;
	ifstream hFile(m_fileCustomer, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	hFile.read((char*)&count, sizeof(int));
	for (int i=0; i<count; i++) {
		// doc id
		hFile.read((char*)&ID, sizeof(UINT));
		Name.ConvertUTF8ToUTF16(readStr(hFile));
		// doc ngay sinh
		hFile.read((char*)&day, sizeof(int));
		hFile.read((char*)&mon, sizeof(int));
		hFile.read((char*)&year, sizeof(int));
		CDate BirthDay(day, mon, year);
		// doc phone
		Phone.ConvertUTF8ToUTF16(readStr(hFile));
		// doc passport
		Passport.ConvertUTF8ToUTF16(readStr(hFile));
		// doc TourCode + PlaceCode
		hFile.read((char*)&TourCode, sizeof(UINT));
		hFile.read((char*)&PlaceCode, sizeof(UINT));
		m_travel.creatCustomer(ID, Name, Phone, Passport, TourCode, PlaceCode);
	}
	hFile.close();
}

void CDatabase::readOfficer(string fileOfficer)
{
	UINT ID; 
	ustring Name; 
	int day, mon, year;
	ustring Phone; 
	ustring Passport;
	UINT TourCode;
	ustring TransportCode;

	m_fileOfficer = fileOfficer;
	ifstream hFile(m_fileOfficer, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	hFile.read((char*)&count, sizeof(int));
	for (int i=0; i<count; i++) {
		// doc id
		hFile.read((char*)&ID, sizeof(UINT));
		Name.ConvertUTF8ToUTF16(readStr(hFile));
		// doc ngay sinh
		hFile.read((char*)&day, sizeof(int));
		hFile.read((char*)&mon, sizeof(int));
		hFile.read((char*)&year, sizeof(int));
		CDate BirthDay(day, mon, year);
		// doc phone
		Phone.ConvertUTF8ToUTF16(readStr(hFile));
		// doc passport
		Passport.ConvertUTF8ToUTF16(readStr(hFile));
		// doc TourCode + PlaceCode
		hFile.read((char*)&TourCode, sizeof(UINT));
		TransportCode.ConvertUTF8ToUTF16(readStr(hFile));
		m_travel.creatOfficer(ID, Name, Phone, Passport, TourCode, TransportCode);
	}
	hFile.close();
}

void CDatabase::readTransport(string fileTransport)
{
	UINT ID;
	UINT Vehicles;
	ustring NumPlate;
	UINT Seat;

	float Gasoline;
	float FuelTank;
	float LossGar;
	ustring Status;
	UINT Tourcode;

	m_fileTransport = fileTransport;
	ifstream hFile(m_fileTransport, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	hFile.read((char*)&count, sizeof(int));
	for (int i=0; i<count; i++) {
		// doc id
		hFile.read((char*)&ID, sizeof(UINT));
		//doc loai xe
		hFile.read((char*)&Vehicles, sizeof(UINT));
		// doc bien so
		NumPlate.ConvertUTF8ToUTF16(readStr(hFile));
		// doc so cho ngoi
		hFile.read((char*)&Seat, sizeof(UINT));
		// doc luong xang
		hFile.read((char*)&Gasoline, sizeof(float));
		//doc dung tich binh xang
		hFile.read((char*)&FuelTank, sizeof(float));
		//doc do hao xang
		hFile.read((char*)&LossGar, sizeof(float));
		//doc trang thai hien tai
		Status.ConvertUTF8ToUTF16(readStr(hFile));
		//doc tour code
		hFile.read((char*)&Tourcode, sizeof(float));
		m_travel.creatTransport( ID, Vehicles, NumPlate, Seat, Gasoline, FuelTank, LossGar, Status, Tourcode);
	}
	hFile.close();
}

void CDatabase::readTour(string fileTour)
{
	UINT ID;
	UINT placeId;
	int dayStar, monStar,yearStar;
	int dayEnd, monEnd,yearEnd;
	ustring name;

	m_fileTour = fileTour;
	ifstream hFile(m_fileTour, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	hFile.read((char*)&count, sizeof(int));
	for (int i=0; i<count; i++) {
		// doc id
		hFile.read((char*)&ID, sizeof(UINT));
		hFile.read((char*)&placeId, sizeof(UINT));
		// doc ngay bat dau
		hFile.read((char*)&dayStar, sizeof(int));
		hFile.read((char*)&monStar, sizeof(int));
		hFile.read((char*)&yearStar, sizeof(int));
		CDate timeStart(dayStar, monStar, yearStar);
		//doc ngay ket thuc
		hFile.read((char*)&dayEnd, sizeof(int));
		hFile.read((char*)&monEnd, sizeof(int));
		hFile.read((char*)&yearEnd, sizeof(int));
		CDate timeEnd(dayEnd, monEnd, yearEnd);
		// doc ten
		name.ConvertUTF8ToUTF16(readStr(hFile));
		m_travel.creatTour( name, timeStart, timeEnd, name);
	}
	hFile.close();
}

// ========================= write ========================= //
void CDatabase::writeCustomer(string fileCustomer)
{
	ofstream hFile(fileCustomer, ios::in | ios::out);
	if (!hFile.is_open())
		return;

	hFile.close();
}

void CDatabase::writeOfficer(string fileOfficer)
{
	ofstream hFile(fileOfficer, ios::in | ios::out);
	if (!hFile.is_open())
		return;

	hFile.close();
}

void CDatabase::writeTransport(string fileTransport)
{
	ofstream hFile(fileTransport, ios::in | ios::out);
	if (!hFile.is_open())
		return;

	hFile.close();
}

void CDatabase::writeTour(string fileTour)
{
	ofstream hFile(fileTour, ios::in | ios::out);
	if (!hFile.is_open())
		return;

	hFile.close();
}


void CDatabase::save()
{
	//
}

void CDatabase::readAll()
{
	//
}

LPSTR CDatabase::readStr(ifstream &hFile)
{
	CHAR len;
	LPSTR str; 
	// doc chieu dai chuoi name
	hFile.read((char*)&len, sizeof(CHAR));
	// cap phat dong + dong chuoi
	str = new CHAR[len];
	hFile.read(str, len);
	return str;
}

CDuLich &CDatabase::getTravel()
{
	return m_travel;
}