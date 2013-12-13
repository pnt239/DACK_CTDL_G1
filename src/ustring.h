#pragma once
#include <string>
#include <vector>
#include <cstringt.h>
#include <atlstr.h>
#include <strsafe.h>
#include <windows.h>
#pragma once

class ustring
{
private:
	std::wstring str;
public:
	//default constructor
	ustring();
	//para constructor
	ustring(LPWSTR str);
	//setter, kiểu dữ liệu input wchar_t*
	void Set(WCHAR *u);
	//getter, kiểu dữ liệu trả về wstring
	std::wstring Get();
	//lấy data, kiểu dữ liệu trả về const wchar_t*
	LPCWSTR data();
	//lấy độ dài
	int length();
	//clear
	void clear();
	//chuyển UTF8 sang UTF16 và gán vào biến str
	void ConvertUTF8ToUTF16( __in const CHAR * pszTextUTF8 );
	//chuyển UTF16(biến str) thành UTF8 rồi return kiểu string
	std::string ConvertUTF16ToUTF8();

	WCHAR& operator[] (INT pos);
	ustring& operator= (LPWSTR str);
	friend std::ostream &operator<<(std::ostream &out, ustring c) 
	{
        out<<c.str.data();
        return out;
	}
	//< return -1 | == return 0 | > return 1
	int compare(ustring _Ptr);
	//friend std::fstream& operator<<(std::fstream& fs, const ustring &MyData)
	//{
	//	fs << MyData.str.c_str();
	//	return fs;
	//}
	//friend std::fstream& operator>>(std::fstream& fs, const ustring &MyData)
	//{
	//	fs >> MyData;
	//	return fs;
	//}
};
