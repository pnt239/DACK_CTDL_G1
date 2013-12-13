#pragma once
#include <string>

class CDatabase
{
public:
	CDatabase();
	~CDatabase();

	void readCustomer(std::string fileCustomer);
	void readOfficer(std::string fileOfficer);
	void readTransport(std::string fileTransport);
	void readTour(std::string fileTour);

	void writeCustomer(std::string fileCustomer);
	void writeOfficer(std::string fileOfficer);
	void writeTransport(std::string fileTransport);
	void writeTour(std::string fileTour);

	void save();
	void readAll();
private:
	std::string m_fileCustomer;
	std::string m_fileOfficer;
	std::string m_fileTransport;
	std::string m_fileTour;
	bool m_CustSaved;
	bool m_OffcSaved;
	bool m_TranSaved;
	bool m_TourSaved;
};

