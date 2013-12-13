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
	CDate BirthDay;
	ustring Phone; 
	ustring Passport;
	UINT TourCode;
	UINT PlaceCode;
	ustring TransportCode;

	m_fileCustomer = fileCustomer;
	ifstream hFile(m_fileCustomer, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	hFile.read((char*)&count, sizeof(int));
	for (int i=0; i<count; i++) {
		//
	}
	hFile.close();
}

void CDatabase::readOfficer(string fileOfficer)
{
	m_fileOfficer = fileOfficer;
	ifstream hFile(m_fileOfficer, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	for (int i=0; i<count; i++) {
		//
	}
	hFile.close();
}

void CDatabase::readTransport(string fileTransport)
{
	m_fileTransport = fileTransport;
	ifstream hFile(m_fileTransport, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	for (int i=0; i<count; i++) {
		//
	}
	hFile.close();
}

void CDatabase::readTour(string fileTour)
{
	m_fileTour = fileTour;
	ifstream hFile(m_fileTour, ios::binary | ios::in);
	if (!hFile.is_open())
		return;
	int count = 0;
	for (int i=0; i<count; i++) {
		//
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