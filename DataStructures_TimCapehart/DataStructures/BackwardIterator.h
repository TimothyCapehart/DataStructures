#ifndef BACKWARDITERATOR_H
#define BACKWARDITERATOR_H
#include "ListIterator.h"

template<class T>
class DLLNode;

template<class T>
class BackwardIterator : public ListIterator<T>
{
public:
	 void Reset() override;
	 bool IsDone() override;
	 void MoveNext() override;
	 DLLNode<T> * operator=(DLLNode<T> * rhs) override;
	 DLLNode<T> * operator=(DLLNode<T> * rhs) const;
	 BackwardIterator<T> & operator++(int);
	 BackwardIterator<T> & operator++();
};


template<class T>
inline void BackwardIterator<T>::Reset()
{
	while (this->_node->next != nullptr)
		this->_node = this->_node->next;
}

template<class T>
inline bool BackwardIterator<T>::IsDone()
{
	if (this->_node->prev == nullptr)
		this->setDone(true);
	return this->_done;
}

template<class T>
inline void BackwardIterator<T>::MoveNext()
{
	if (this->_node->prev != nullptr)
		this->_node = this->_node->prev;
}

template<class T>
inline DLLNode<T> * BackwardIterator<T>::operator=(DLLNode<T> * rhs)
{
	return this->_node = rhs;
}

template<class T>
inline DLLNode<T> * BackwardIterator<T>::operator=(DLLNode<T> * rhs) const
{
	return this->_node = rhs;
}

template<class T>
inline BackwardIterator<T> & BackwardIterator<T>::operator++(int)
{
	if (this->_node->prev != nullptr)
		this->_node = this->_node->prev;
	return *this;
}

template<class T>
inline BackwardIterator<T> & BackwardIterator<T>::operator++()
{
	if (this->_node->prev != nullptr)
		this->_node = this->_node->prev;
	return *this;
}
#endif

