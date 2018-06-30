#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "Array.h"

template<class T>
class ArrayQueue
{
private:
	Array<T> _queue;
	int _n;
	int _f;
	int _r;

public:
	ArrayQueue();
	ArrayQueue(int size);
	ArrayQueue(const ArrayQueue<T> & rhs);
	~ArrayQueue();

	ArrayQueue<T> & operator=(const ArrayQueue<T> & rhs);
	ArrayQueue<T> & operator=(const ArrayQueue<T> & rhs) const;

	void Enqueue(const T & data);
	T Dequeue();
	T & Front();
	int Size();
	bool IsEmpty();
	bool IsFull();
};

template<class T>
inline ArrayQueue<T>::ArrayQueue()
{
	_n = 1;
	_f = 0;
	_r = 0;
}

template<class T>
inline ArrayQueue<T>::ArrayQueue(int size)
{
	_queue.setLength(size + 1);
	_n = size + 1;
	_f = 0;
	_r = 0;
}

template<class T>
inline ArrayQueue<T>::ArrayQueue(const ArrayQueue<T> & rhs)
{
	_queue = rhs._queue;
	_n = rhs._n;
	_f = rhs._f;
	_r = rhs._r;
}

template<class T>
inline ArrayQueue<T>::~ArrayQueue()
{

}

template<class T>
inline ArrayQueue<T> & ArrayQueue<T>::operator=(const ArrayQueue<T> & rhs)
{
	_queue = rhs._queue;
	_n = rhs._n;
	_f = rhs._f;
	_r = rhs._r;
	return *this;
}

template<class T>
inline ArrayQueue<T> & ArrayQueue<T>::operator=(const ArrayQueue<T> & rhs) const
{
	_queue = rhs._queue;
	_n = rhs._n;
	_f = rhs._f;
	_r = rhs._r;
	return *this;
}

template<class T>
inline void ArrayQueue<T>::Enqueue(const T & data)
{
	if (IsFull())
		throw Exception("Queue is full!");
	else
	{
		_queue[_r] = data;
		_r = (_r + 1) % _n;
	}
}

template<class T>
inline T ArrayQueue<T>::Dequeue()
{
	if (IsEmpty())
		throw Exception("Queue is empty!");
	else
	{
		T ret = _queue[_f];
		_f = (_f + 1) % _n;
		return ret;
	}
}

template<class T>
inline T & ArrayQueue<T>::Front()
{
	if (IsEmpty())
		throw Exception("Queue is empty!");
	else
	{
		return _queue[_f];
	}
}

template<class T>
inline int ArrayQueue<T>::Size()
{
	return (_n - _f + _r) % _n;
}

template<class T>
inline bool ArrayQueue<T>::IsEmpty()
{
	return _r == _f;
}

template<class T>
inline bool ArrayQueue<T>::IsFull()
{
	return Size() == _n - 1;
}
#endif