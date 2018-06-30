#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H
#include "ListIterator.h"

template<class T>
class DLLNode;

template<class T>
class ForwardIterator : public ListIterator<T>
{
public:
	ForwardIterator();
	~ForwardIterator();

	void Reset() override;
	bool IsDone() override;
	void MoveNext() override;
	DLLNode<T> * operator=(DLLNode<T> * rhs) override;
	DLLNode<T> * operator=(DLLNode<T> * rhs) const;

	ForwardIterator<T> & operator++(int);
	ForwardIterator<T> & operator++();
};

template<class T>
inline ForwardIterator<T>::ForwardIterator()
{
	
}

template<class T>
inline ForwardIterator<T>::~ForwardIterator()
{

}

template<class T>
inline void ForwardIterator<T>::Reset()
{
	while(this->_node->prev != nullptr)
		this->_node = this->_node->prev;
}

template<class T>
inline bool ForwardIterator<T>::IsDone()
{
	if (this->_node->next == nullptr)
		this->_done = true;
	return this->_done;
}

template<class T>
inline void ForwardIterator<T>::MoveNext()
{
	if (this->_node->next != nullptr)
		this->_node = this->_node->next;
}

template<class T>
inline DLLNode<T> * ForwardIterator<T>::operator=(DLLNode<T> * rhs)
{
	return this->_node = rhs;
}

template<class T>
inline DLLNode<T> * ForwardIterator<T>::operator=(DLLNode<T> * rhs) const
{
	return this->_node = rhs;
}

template<class T>
inline ForwardIterator<T> & ForwardIterator<T>::operator++(int)
{
	if (this->_node->next != nullptr)
	{
		this->_node = this->_node->next;
	}
	return *this;
}

template<class T>
inline ForwardIterator<T> & ForwardIterator<T>::operator++()
{
	if (this->_node->next != nullptr)
	{
		this->_node = this->_node->next;
	}
	return *this;
}

#endif

