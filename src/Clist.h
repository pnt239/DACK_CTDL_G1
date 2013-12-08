#pragma once
#include "LinkList.h"

#define Success 1
#define Underflow 2
#define Overflow 3

template <class T>
class Clist  : public LinkList<T>
{
private:
	LinkList<T> data;
public:
	bool IsEmpty()	//kiem tra ngan xep rong
	{
		if(this->data.Empty())
			return true;
		return false;
	}

	T Pop()		//lay khoi ngan xep 1 phan tu
	{
		T item ;
		if(!this->IsEmpty())
		{
			item = this->data.getHead();
			this->data.RemoveHead();
			return item;
		}
	}

	//-------->>>>> hàm này chỉ cần vậy là được rồi..thêm vào đầu thì cần j kiểm tra nó rỗng chứ
	void Push(const T item) //dua vao ngan xep 1 phan tu
	{
		//if(!this->IsEmpty())
		//{
		this->data.AddHead(item);
			//return Success;
		//}
		//else
			//return Overflow;
	}

	//lay kich thuoc stack
	int Size()
	{
		if(this->IsEmpty())
			return 0;
		else
		{
			return this->data.Size();
		}
	}

	//hien thi danh sach
	void Show()
	{
		if(!this->IsEmpty())
			this->data.PrintList();
	}
		
	int Top(T &item)		//xem phan tu dinh cua ngan xep
	{
		if(!this->IsEmpty())
		{
			item = this->data.getHead();
			return Success;
		}
		else
			return Underflow;
	}

	void ClearAll()				//xoa tat ca cac phan tu
	{
		this->data.RemoveList();
	}

	//sap xep
	void Sort()
	{
		QuickSort(this->data, 0, this->data.Size()-1);
	}
};
