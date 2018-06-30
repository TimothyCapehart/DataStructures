#ifndef LISTSTACK_H
#define LISTSTACK_H
#include "DLList.h"
#include "Exception.h"

template<class T>
class ListStack
{
private:
	DLList<T> _stack;
	int _size;
public:
	ListStack();
	ListStack(const ListStack<T> & rhs);
	~ListStack();

	ListStack<T> & operator=(const ListStack<T> & rhs);
	ListStack<T> & operator=(const ListStack<T> & rhs) const;

	void Push(const T & data);
	T & Pop();
	T & Pop() const;
	T & Peek();
	T & Peek() const;
	int Size();
	int Size() const;
	bool IsEmpty();
};

template<class T>
inline ListStack<T>::ListStack()
{
	_size = 0;
}

template<class T>
inline ListStack<T>::ListStack(const ListStack<T> & rhs)
{
	_stack.Purge();
	_stack = rhs._stack;
	_size = rhs._size;
}

template<class T>
inline ListStack<T>::~ListStack()
{

}

template<class T>
inline ListStack<T> & ListStack<T>::operator=(const ListStack<T> & rhs)
{
	_stack.Purge();
	_stack = rhs._stack;
	_size = rhs._size;
	return *this;
}

template<class T>
inline ListStack<T> & ListStack<T>::operator=(const ListStack<T> & rhs) const
{
	_stack.Purge();
	_stack = rhs._stack;
	_size = rhs._size;
	return *this;
}

template<class T>
inline void ListStack<T>::Push(const T & data)
{
	_stack.Append(data);
	_size++;
}

template<class T>
inline T & ListStack<T>::Pop()
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
	{
		T data = _stack.getTail()->getData();
		_stack.Extract(data);
		_size--;
		return data;
	}
}

template<class T>
inline T & ListStack<T>::Pop() const
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
	{
		T data = _stack.getTail()->getData();
		_stack.Extract(data);
		_size--;
		return data;
	}
}

template<class T>
inline T & ListStack<T>::Peek()
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
		return _stack.getTail()->getData();
}

template<class T>
inline T & ListStack<T>::Peek() const
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
		return _stack.getTail()->getData();
}

template<class T>
inline int ListStack<T>::Size()
{
	return _size;
}

template<class T>
inline int ListStack<T>::Size() const
{
	return _size;
}

template<class T>
inline bool ListStack<T>::IsEmpty()
{
	return _stack.isEmpty();
}
#endif