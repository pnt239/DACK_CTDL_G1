#pragma once
#include "Library.h"

template <class T>
class CNode
{
public:
	T value;
	CNode *pNext;

	//contructor
	CNode(T data)
	{
		value = data;
		pNext = NULL;
	}	
	CNode()
	{
		//*this = NULL;
	}
};
template <class T>
class LinkList
{
protected:
	CNode<T> *pHead; // Con trỏ chỉ phần tử đầu của danh sách.
public:
	//các hàm thực hiện thêm  phần tử vào
	bool AddHead(T nValue)
	{
		CNode<T> *p;
		p = new CNode<T>;
		p->value = nValue;
		p->pNext = this->pHead;
		this->pHead = p;
		return true;
	}

	//lay phan tu dau tien
	T getHead()
	{
		return  this->pHead->value;
	}

	//them phan tu vao cuoi danh sach
	bool AddTail(T nValue)
	{
		CNode<T> *p = this->pHead;
		CNode<T> *q = new CNode<T>;
		q->value = nValue;
		if(this->pHead == NULL)
			this->pHead = q;
		else
		{
			while(p->pNext != NULL) 
			{
				p = p->pNext;
			}
			p->pNext = q;
			q->pNext = NULL;
		}
		return true;
	}

	//them phan tu sau 1 vi tri nao do trong danh sach
	bool AddAfter(T nValue, int x)
	{
		CNode<T> *p = this->pHead;
		CNode<T> *q = new CNode<T>;
		q->value = nValue;
		int count = 1;
		if(x == 1)
		{
			q->pNext = this->pHead->pNext;
			this->pHead->pNext = q;
		}
		else
		{
			do
			{
				p = p->pNext;
				count++;
			}while(count != x);
		}
		q->pNext = p->pNext;
		p->pNext = q;
		return true;
	}

	//ham lay kich thuoc cua danh sach
	int Size()
	{
		CNode<T> *p = this->pHead;
		int count = 1;
		if(this->Empty())
			return 0;
		if(p->pNext == NULL)
			return count;
		do
		{
			p = p->pNext;
			count ++;
		}while(p->pNext != NULL);
		return count;
	}

	//các hàm xóa đi một phần tử
	void RemoveHead()
	{
		CNode<T> *p = this->pHead;
		if(this->pHead != NULL)
		{
			this->pHead = p->pNext;
			p->pNext = NULL;
		}
		delete p;
		}

	//xoa phan tu cuoi
	void RemoveTail()
	{
		CNode<T> *p = this->pHead;
		while(p->pNext != NULL)
			p = p->pNext;
		delete p;
	}

	//xoa node co gia tri nao do
	void RemoveNode(T item)
	{
		CNode<T> *p = this->pHead;
		if(this->pHead->value == item)
			this->RemoveHead();
		else
		{
			while(p->pNext->value != item)
				p = p->pNext;
			delete p->pNext;
		}
	}

	//xoa toan bo danh sach
	void RemoveList()
	{
		while(this->pHead != NULL)
		{
			this->RemoveHead();
		}
	}

	//kiem tra rong
	bool Empty()
	{
		if(this->pHead == NULL)
			return true;
		return false;
	}

	// Duyệt in danh sách
	void PrintList()
	{
		CNode<T> *p = this->pHead;
		if(this->Empty())
		{
			cout << "\nEmpty";
			return;
		}
		while(p != NULL)
		{
			cout << p->value << " ";
			p = p->pNext;
		}
	}
	// Các phương thức bảo đảm tính an toàn cho CTDL có chứa thuộc tính con 
	//trỏ.
	~LinkList(){};

	LinkList()
	{
		this->pHead = NULL;
	}
	//------------>>>> hàm này hình như viết chưa đúng...nếu bài này hk cần thì khỏi viết hàm này
	/*LinkList(const LinkList &copy)
	{
		CNode<T> *pN;
		pN = copy.pHead;

		while(pN != NULL)
		{
			CNode<T> *p = new CNode<T>(pN->value);
			this->AddTail(p->value);
			p = p->pNext;
		}
	}*/
	
	LinkList<T>& LinkList<T>::operator=(const LinkList<T>* copy)		
	{
		if (this != copy)		
		{
			copy->pHead = this->pHead;
		}
		return *this;
	}
};

template<class T>
void QuickSort(LinkList<T> &a, int l, int r)
{
	if(l >= r)
		return;
	int pivot = a.getValue((r+l)/2);
	int i = l, j = r;

	do
	{
		while(a.getValue(i) < pivot)
			i++;
		while(a.getValue(j) > pivot)
			j--;
		if(i <= j)
		{
			T tmp, tmp1;
			tmp = a.getValue(j);
			tmp1 = a.getValue(i);
			a.setValue(i, tmp);
			a.setValue(j, tmp1);
			i++;

			j--;
		}
	}while(i <= j);
	if(l < j)
		quic(a, l, j);
	if(j < i)
		quic(a, i, r);
}