#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "Array.h"

template<class T>
class ArrayStack
{
private:
	Array<T> _stack;
	int _top;
	int _length;

public:
	ArrayStack();
	ArrayStack(int size);
	ArrayStack(const ArrayStack<T> & rhs);
	~ArrayStack();
	
	ArrayStack<T> & operator=(const ArrayStack<T> & rhs);
	ArrayStack<T> & operator=(const ArrayStack<T> & rhs) const;
	T & operator[](int index);
	T & operator[](int index) const;

	void Push(const T & data);
	T & Pop();
	T & Pop() const;
	T & Peek();
	T & Peek() const;
	int Size();
	int Size() const;
	bool IsEmpty();
	bool IsFull();

	void setTop(int t) { _top = t; };
	int getTop() { return _top; };
	int getTop() const { return _top; };
	void setLength(int l) { _length = l; };
	int getLength() { return _length; };
	int getLength() const { return _length; };
	void setArrayLength(int l) { _stack.setLength(l); _length = l; };
};

template<class T>
inline ArrayStack<T>::ArrayStack()
{
	_stack.setLength(1);
	_length = 1;
	_top =-1;
}

template<class T>
inline ArrayStack<T>::ArrayStack(int size)
{
	_stack.setLength(size);
	_length = size;
	_top = -1;
}

template<class T>
inline ArrayStack<T>::ArrayStack(const ArrayStack<T> & rhs)
{
	_stack.setLength(rhs.getLength());
	_length = rhs.getLength();
	_top = rhs.getTop();
	for (size_t i = 0; i < _length; i++)
		_stack[i] = rhs[i];
}

template<class T>
inline ArrayStack<T>::~ArrayStack()
{

}

template<class T>
inline ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs)
{
	_stack.setLength(rhs.getLength());
	_length = rhs.getLength();
	_top = rhs.getTop();
	for (size_t i = 0; i <= _top; i++)
		_stack[i] = rhs[i];
	return *this;
}

template<class T>
inline ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs) const
{
	_stack.setLength(rhs.getLength());
	_length = rhs.getLength();
	_top = rhs.getTop();
	for (size_t i = 0; i <= _top; i++)
		_stack[i] = rhs[i];
	return *this;
}

template<class T>
inline T & ArrayStack<T>::operator[](int index)
{
	if (index < 0)
		throw Exception("Index less than 0.");
	else if (index > _top)
		throw Exception("Index greater than top.");
	else
		return _stack[index];
}

template<class T>
inline T & ArrayStack<T>::operator[](int index) const
{
	if (index < 0)
		throw Exception("Index less than 0.");
	else if (index > _top)
		throw Exception("Index greater than top.");
	else
		return _stack[index];
}

template<class T>
inline void ArrayStack<T>::Push(const T & data)
{
	if (IsFull())
		throw Exception("Stack is full!");
	else
		_stack[++_top] = data;
}

template<class T>
inline T & ArrayStack<T>::Pop()
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
		return _stack[_top--];
}

template<class T>
inline T & ArrayStack<T>::Pop() const
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
		return _stack[_top--];
}

template<class T>
inline T & ArrayStack<T>::Peek()
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
		return _stack[_top];
}

template<class T>
inline T & ArrayStack<T>::Peek() const
{
	if (IsEmpty())
		throw Exception("Stack is empty!");
	else
		return _stack[_top];
}

template<class T>
inline int ArrayStack<T>::Size()
{
	if (IsEmpty())
		return 0;
	else
		return _top + 1;
}

template<class T>
inline int ArrayStack<T>::Size() const
{
	if (IsEmpty())
		return 0;
	else
		return _top + 1;
}

template<class T>
inline bool ArrayStack<T>::IsEmpty()
{
	return (_top < 0);
}

template<class T>
inline bool ArrayStack<T>::IsFull()
{
	return (_top == _length - 1);
}
#endif