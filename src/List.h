#pragma once
#include "LinkedList.h"

template <class T>
class CList  : 
	public LinkedList<T>
{
public:
	CList(void)
	{
	}
	~CList(void)
	{
	}

	/* Add to tail */
	void push_back(T val)
	{
		add(val);
	}
	/* Free from tail */
	void pop_back()
	{
		remove(m_size-1);
	}
};
