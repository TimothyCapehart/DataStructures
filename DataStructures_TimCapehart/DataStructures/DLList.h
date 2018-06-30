#ifndef DLLIST_H
#define DLLIST_H
#include<iostream>
#include "ForwardIterator.h"
#include "BackwardIterator.h"

template<class T>
class DLLNode
{
public:
	T data;
	DLLNode * prev = nullptr;
	DLLNode * next = nullptr;

	DLLNode() { next = prev = nullptr; };
	DLLNode(T el);
	DLLNode(const T & element, DLLNode *p, DLLNode *n);
	~DLLNode() { };

	void setNext(DLLNode *n) { next = n; };
	DLLNode<T> * getNext() { return next; };
	DLLNode<T> * getNext() const { return next; };
	void setPrev(DLLNode *p) { prev = p; };
	DLLNode<T> * getPrev() { return prev; };
	DLLNode<T> * getPrev() const { return prev; };
	void setData(T d) { data = d; };
	T & getData();
	T & getData() const { return data; };
};

template<class T>
inline DLLNode<T>::DLLNode(const T & element, DLLNode *p, DLLNode *n)
{
	data = element;
	prev = p;
	next = n;
}

template<class T>
DLLNode<T>::DLLNode(T el)
{
	next = prev = nullptr;
	data = el;
}

template<class T>
inline T & DLLNode<T>::getData()
{
	return data;
}

//********************************************************

template<class T>
class DLList
{
protected:
	DLLNode<T> *head = nullptr; 
	DLLNode<T> *tail = nullptr;
	
public:
	DLList();
	DLList(const DLList & rhs);
	~DLList();

	void setHead(DLLNode<T> * h) { head = h; };
	DLLNode<T> * getHead() { return head; };
	DLLNode<T> * getHead() const { return head; };
	void setTail(DLLNode<T> * t) { tail = t; };
	DLLNode<T> * getTail() { return tail; };
	DLLNode<T> * getTail() const { return tail; };

	DLList<T> & operator=(const DLList<T> & rhs); 
	DLList<T> & operator=(const DLList<T> & rhs) const;

	bool isEmpty();
	const T & First();
	const T & Last();
	void Prepend(const T & data);
	void Append(const T & data);
	void Purge();
	void Extract(const T & data);
	void InsertAfter(const T & data, const T & prev);
	void InsertBefore(const T & data, const T & after);
};

template<class T>
inline DLList<T>::DLList()
{

}

template<class T>
inline DLList<T>::DLList(const DLList & rhs)
{
	DLLNode<T> *nodePtr;
	nodePtr = rhs.head;
	while (nodePtr != nullptr)
	{
		Append(nodePtr->getData());
		nodePtr = nodePtr->next;
	}
}

template<class T>
inline DLList<T>::~DLList()
{
	DLLNode<T> *nodePtr = head;
	while (nodePtr != tail)
	{
		DLLNode<T> *next = nodePtr->next;
		delete nodePtr;
		nodePtr = next;
	}
	delete nodePtr;
}

template<class T>
inline bool DLList<T>::isEmpty()
{
	return (head == nullptr && tail == nullptr);
}

template<class T>
inline const T & DLList<T>::First()
{
	return head->getData();
}

template<class T>
inline const T & DLList<T>::Last()
{
	return tail->getData();
}

template<class T>
inline void DLList<T>::Prepend(const T & data)
{
	if (head)
	{
		head = new DLLNode<T>(data, 0, head);
		head->next->prev = head;
	}
	else
		head = tail = new DLLNode<T>(data);
}

template<class T>
inline void DLList<T>::Append(const T & data)
{
	if (tail)
	{
		try
		{
			tail = new DLLNode<T>(data, tail, 0);
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what();
		}
		tail->prev->next = tail;
	}
	else
	{
		try
		{
			head = tail = new DLLNode<T>(data);
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what();
		}
	}
}

template<class T>
inline void DLList<T>::Purge()
{
	DLLNode<T> *nodePtr = head;
	while (nodePtr != nullptr)
	{
		DLLNode<T> *next = nodePtr->next;
		delete nodePtr;
		nodePtr = next;
	}
	head = tail = nullptr;
}

template<class T>
inline void DLList<T>::Extract(const T & data)
{
	DLLNode<T> *nodePtr = tail;
	while (nodePtr->getData() != data)
	{
		nodePtr = nodePtr->prev;
	}
	if (nodePtr == nullptr)
		throw Exception("Not Found.");

	if (nodePtr == tail && nodePtr == head)
	{
		Purge();
	}
	else if (nodePtr == head)
	{
		nodePtr->next->prev = nullptr;
		head = nodePtr->next;
		delete nodePtr;
	}
	else if (nodePtr == tail)
	{
		tail = nodePtr->prev;
		tail->next = nullptr;
		delete nodePtr;
	}
	else
	{
		nodePtr->prev->next = nodePtr->next;
		nodePtr->next->prev = nodePtr->prev;
		delete nodePtr;
	}
}

template<class T>
inline void DLList<T>::InsertAfter(const T & data, const T & prev)
{
	DLLNode<T> *nodePtr;
	DLLNode<T> *newNode;
	nodePtr = head;
	while (nodePtr->getData() != prev)
	{
		if (nodePtr->next != nullptr)
			nodePtr = nodePtr->next;
		else
			throw Exception("Data not found.");
	}
	if (nodePtr == tail)
	{
		Append(data);
	}
	else
	{
		try
		{
			newNode = new DLLNode<T>(data, nodePtr, nodePtr->next);
		}
		catch (std::bad_alloc bad)
		{
			std::cerr <<  bad.what();
		}
		nodePtr->next = newNode;
		newNode->next->prev = newNode;
	}
}

template<class T>
inline void DLList<T>::InsertBefore(const T & data, const T & after)
{
	DLLNode<T> *nodePtr;
	DLLNode<T> *newNode;
	nodePtr = head;
	while (nodePtr->getData() != after)
	{
		if (nodePtr->next != nullptr)
			nodePtr = nodePtr->next;
		else
			throw Exception("Data not found.");
	}
	if (nodePtr == head)
	{
		Prepend(data);
	}
	else
	{
		try
		{
			newNode = new DLLNode<T>(data, nodePtr->prev, nodePtr);
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what();
		}
		nodePtr->prev = newNode;
		nodePtr->prev->next = newNode;
	}
}

template<class T>
DLList<T> & DLList<T>:: operator=(const DLList<T> & rhs)
{
	Purge();
	DLLNode<T> *nodePtr = rhs.head;
	while (nodePtr != nullptr)
	{
		Append(nodePtr->getData());
		nodePtr = nodePtr->next;
	}
	return *this;
}

template<class T>
DLList<T> & DLList<T>:: operator=(const DLList<T> & rhs) const
{
	Purge();
	DLLNode<T> *nodePtr = rhs.head;
	while (nodePtr != nullptr)
	{
		Append(nodePtr->getData());
		nodePtr = nodePtr->next;
	}
	return *this;
}
#endif