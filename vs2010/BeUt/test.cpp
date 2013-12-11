#pragma once
#include "Tour.h"
#include "Date.h"
#include "List.h"
#include "TransportManager.h"

void main()
{
	// only for test
	/*Ctour a;
	UINT id = 1;
	a.Set_ID(id);
	string place;
	place = "Vung Tau";
	a.Set_Place(place);
	Clist<UINT> mapt;
	UINT tmp = 3;
	mapt.Push(tmp);
	a.Set_Trans(mapt);
	Clist<UINT> makh;
	tmp = 13;
	makh.Push(tmp);
	a.Set_Customers(makh);						
	Date sta;
	Date end;
	sta.setD(11);
	sta.setM(3);
	sta.setY(2012);
	a.Set_TimeStart(sta);
	end.setD(2);
	end.setM(4);
	end.setY(2012);
	a.Set_TimeEnd(end);

	cout << "\n\nget\n\n";
	cout << "\nID = " << a.Get_ID();
	string p = a.Get_Place();
	cout << "\nDia diem: " << p << endl;
	Clist<UINT> t;
	t = a.Get_Trans();		
	a.ShowClist(t);
	cout << endl;
	t = a.Get_Customers();
	t.Show();
	cout << endl;
	Date k;
	k = a.Get_TimeStart();
	k.Export();
	cout << endl;
	k = a.Get_TimeEnd();
	k.Export();
	cout << endl;
								
	cout << "\n\n Phan Transports:\n";
	CTransport b;
	b.Set_FuelTank(5);
	b.Set_Gasoline(3);
	b.Set_LossGar(0.5);
	b.Set_NumPlate("11N3");
	b.Set_Seat(4);
	b.Set_Status("Binh thuong nha.");
	b.Set_Vehicles(3);
	//b.ImportAll();
	//c.ImportAll();
	Clist<CTransport> g;
	g.Push(b);
	TransportManager x;
	x.Set_Transport(g);
	Clist<CTransport> h;
	h = x.Get_Transport();
	int n;
	n = h.Size();
	for(int i = 0; i < n; i++)
	{
		CTransport r;
		r = h.Pop();
		r.ExportAll();
		cout << endl;
	}*/


}

