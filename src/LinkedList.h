#pragma once
#include <Windows.h>

template <class T>
class CLinkedList
{
public:
	struct Element
	{
		T data;
		Element *next;
	};
	// default constructor
	CLinkedList(void)
	{
		m_head = NULL;
		m_tail = NULL;
		m_size = 0;
	}
	// copy constructor
	CLinkedList(CLinkedList &linkedlist)
	{
		Element *elem = new Element, *last_elem;
		elem->data = linkedlist.at(0);
		elem->next = NULL;

		m_head = elem;

		for (int i=1; i<linkedlist.size(); i++) {
			last_elem = elem;
			elem = new Element;
			elem->data = linkedlist.at(i);
			elem->next = NULL;
			last_elem->next = elem;
		}
		m_size = linkedlist.size();
	}
	// destructor
	~CLinkedList(void)
	{
		clear();
	}

	/* Get value at pos */
	T& at(INT pos)
	{
		Element *elem = m_head;
		//if (m_size == 0)
		if (pos >= m_size)
			return at(m_size-1);
		if (pos < 0)
			return at(0);
		for (int i=0; i<pos; i++, elem = elem->next);
		return elem->data;
	}
	/* Get size of Linked List */
	UINT size()
	{
		return m_size;
	}
	/* Is empty Linked List */
	bool empty()
	{
		return (m_head == NULL | m_tail == NULL);
	}

	/* Add to tail */
	void add(T val)
	{
		Element *elem = new Element;
		elem->data = val;
		elem->next = NULL;

		if (m_size == 0) {
			m_head = elem;
			m_tail = elem;
			m_size++;
			return;
		}

		m_tail->next = elem;
		m_tail = elem;
		m_size++;
	}
	/* Insert a element at position pos */
	void insert(T val, INT pos)
	{
		// Add to tail
		if (pos < 0 || pos >= m_size) {
			add(val);
			return;
		}

		Element *elem = new Element;
		elem->data = val;
		elem->next = NULL;
		m_size++;

		// Add to head
		if (pos == 0) {
			elem->next = m_head;
			m_head = elem;
			return;
		}

		Element *t_elem = m_head, *next_telem;
		for (int i=0; i<pos; i++, t_elem = t_elem->next);
		next_telem = t_elem->next;

		t_elem->next = elem;
		elem->next = next_telem;
	}
	/* Remove a element at position pos */
	void remove(INT pos)
	{
		Element *elem;
		// Delete at head
		if (pos == 0) {
			elem = m_head;
			m_head = elem->next;
			delete elem;
			m_size--;
			return;
		}

		// Delete at tail
		if (pos < 0 || pos >= m_size) {
			remove(m_size - 1);
			return;
		}

		elem = m_head;
		for (int i=0; i<pos-1; i++, elem = elem->next);
			delete elem->next;
		elem->next = NULL;
		m_size--;
	}
	/* Clear all */
	void clear()
	{
		while (m_size != 0)
			remove(0);
	}
	/* operator [] */
	T& operator[] (INT pos)
	{
		return at(pos);
	}
protected:
	Element *m_head;
	Element *m_tail;
	UINT m_size;
};