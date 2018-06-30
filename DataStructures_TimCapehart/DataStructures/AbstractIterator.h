#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H


template<class T>
class DLLNode;

template<class T>
class DLList;

template<class T>
class AbstractIterator
{
public:
	virtual void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsDone() = 0;
	virtual T & GetCurrent() = 0;
};
#endif

