#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include "AbstractIterator.h"

template<class T>
class DLLNode;

template<class T>
class ListIterator : public AbstractIterator<T>
{
protected:
	DLLNode<T> * _node = nullptr;
	bool _done = false;
public:
	virtual void Reset() = 0;
	virtual bool IsDone() = 0;
	virtual void MoveNext() = 0;
	T & GetCurrent() override;
	T & GetCurrent() const;
	virtual DLLNode<T> * operator=(DLLNode<T> * rhs) = 0;
	T & operator*();
	void setDone(bool done);
};


template<class T>
inline T & ListIterator<T>::GetCurrent()
{
	return _node->getData();
}

template<class T>
inline T & ListIterator<T>::GetCurrent() const
{
	return _node->getData();
}

template<class T>
inline T & ListIterator<T>::operator*()
{
	return _node->getData();
}

template<class T>
inline  void ListIterator<T>::setDone(bool done)
{
	this->_done = done;
}

#endif

