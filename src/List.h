#pragma once
#include "LinkedList.h"

template <class T>
class CList :
	public CLinkedList<T>
{
public:
	CList(void)
	{
	}
	~CList(void)
	{
	}
	/* Add to tail */
	void push(T val)
	{
		add(val);
	}
	/* Remove from tail */
	void pop()
	{
		remove(m_size-1);
	}
};
