#pragma once
#include <string>
#include <vector>
#include <cstringt.h>
#include <atlstr.h>
#include <strsafe.h>
#include <windows.h>

class ustring
{
private:
	std::wstring str;
public:
	//constructor
	ustring();
	//setter, kiểu dữ liệu input wchar_t*
	void Set(WCHAR *u);
	//getter, kiểu dữ liệu trả về wstring
	std::wstring Get();
	//lấy data, kiểu dữ liệu trả về const wchar_t*
	const wchar_t* data();
	//lấy độ dài
	int length();
	//clear
	void clear();
	//chuyển UTF8 sang UTF16 và gán vào biến str
	void ConvertUTF8ToUTF16( __in const CHAR * pszTextUTF8 );
	//chuyển UTF16(biến str) thành UTF8 rồi return kiểu string
	std::string ConvertUTF16ToUTF8();

	WCHAR& operator[] (INT pos);
};
