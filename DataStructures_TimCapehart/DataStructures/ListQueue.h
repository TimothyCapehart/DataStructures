#ifndef LISTQUEUE_H
#define LISTQUEUE_H
#include "Exception.h"
#include "DLList.h"

template<class T>
class ListQueue
{
private:
	DLList<T> _queue;
	int _size;
public:
	ListQueue();
	ListQueue(const ListQueue<T> & rhs);
	~ListQueue();

	ListQueue<T> & operator=(const ListQueue<T> & rhs);
	ListQueue<T> & operator=(const ListQueue<T> & rhs) const;

	void Enqueue(const T & data);
	T Dequeue();
	T & Front();
	int Size();
	bool IsEmpty();
};

template<class T>
inline ListQueue<T>::ListQueue()
{
	_size = 0;
}

template<class T>
inline ListQueue<T>::ListQueue(const ListQueue<T> & rhs)
{
	_queue = rhs._queue;
	_size = rhs._size;
}

template<class T>
inline ListQueue<T>::~ListQueue()
{

}

template<class T>
inline ListQueue<T> & ListQueue<T>::operator=(const ListQueue<T> & rhs)
{
	_queue = rhs._queue;
	_size = rhs._size;
}

template<class T>
inline ListQueue<T> & ListQueue<T>::operator=(const ListQueue<T> & rhs) const
{
	_queue = rhs._queue;
	_size = rhs._size;
}

template<class T>
inline void ListQueue<T>::Enqueue(const T & data)
{
	_queue.Append(data);
	_size++;
}

template<class T>
inline T ListQueue<T>::Dequeue()
{
	if (IsEmpty())
		throw Exception("Queue is empty!");
	else
	{
		T ret = _queue.getHead()->getData();
		_queue.Extract(ret);
		_size--;
		return ret;
	}
}

template<class T>
inline T & ListQueue<T>::Front()
{
	if (IsEmpty())
		throw Exception("Queue is empty!");
	else
		return _queue.getHead()->getData();
}

template<class T>
inline int ListQueue<T>::Size()
{
	return _size;
}

template<class T>
inline bool ListQueue<T>::IsEmpty()
{
	return _queue.isEmpty();
}
#endif