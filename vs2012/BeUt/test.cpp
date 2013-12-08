#pragma once
#include "Ctour.h"
#include "Date.h"
#include "Clist.h"
#include "TransportManager.h"

void main()
{
	Ctour a;
	UINT id;
	cout << "\nNhap vao ma tour: ";
	cin >> id;
	a.Set_ID(id);
	string place;
	cout << "\nNhap vap dia diem: ";
	cin.ignore();
	getline(cin, place);
	a.Set_Place(place);
	Clist<UINT> mapt;
	int n;
	cout << "\nBan muon nhap bao nhieu loai phuong tien? : ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "\nMa phuong tien thu " << i << ": ";
		UINT tmp;
		cin >> tmp;
		mapt.Push(tmp);
	}
	a.Set_Trans(mapt);
	cout << "\nBan muon nhap bao nhieu khach hang? : ";
	cin >> n;
	Clist<UINT> makh;
	for(int i = 0; i < n; i++)
	{
		cout << "\nMa khach hang thu " << i << ": ";
		UINT tmp;
		cin >> tmp;
		makh.Push(tmp);
	}

	a.Set_Customers(makh);						
	cout << "\nNhap vao thoi gian bat dau: ";
	Date sta;
	Date end;
	sta.Import();
	a.Set_TimeStart(sta);
	cout << "\nNhap thoi gian ket thuc tour: ";
	end.Import();
	a.Set_TimeEnd(end);

	cout << "\n\nget\n\n";
	cout << "\nID = " << a.Get_ID();
	string p = a.Get_Place();
	cout << "\nDia diem: " << p << endl;
	Clist<UINT> tmp;
	tmp = a.Get_Trans();		
	a.ShowClist(tmp);
	cout << endl;
	tmp = a.Get_Customers();
	tmp.Show();
	cout << endl;
	Date k;
	k = a.Get_TimeStart();
	k.Export();
	cout << endl;
	k = a.Get_TimeEnd();
	k.Export();
	cout << endl;
								
	cout << "\n\n Phan Transports:\n";
	CTransport b, c;
	b.ImportAll();
	c.ImportAll();
	Clist<CTransport> g;
	g.Push(b);
	g.Push(c);
	TransportManager x;
	x.Set_Transport(g);
	Clist<CTransport> t;
	t = x.Get_Transport();
	n = t.Size();
	for(int i = 0; i < n; i++)
	{
		CTransport tmp;
		tmp = t.Pop();
		tmp.ExportAll();
		cout << endl;
	}
}

