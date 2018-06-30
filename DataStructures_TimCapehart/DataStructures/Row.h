#ifndef ROW_H
#define ROW_H
#include "Array2D.h"
#include "Exception.h"
#include<iostream>

template<class T>
class Array2D;

template<class T>
class Row
{
private:
	Array2D<T> & m_array2D;
	int m_row;
public:
	Row(Array2D<T> & inArray, int row);
	T & operator[](int column);
};

template<class T>
inline Row<T>::Row(Array2D<T> & inArray, int row)
	:m_array2D(inArray), m_row(row)
{
	/*m_array2D = inArray;
	m_row = row;*/
}
template<class T>
inline T & Row<T>::operator[](int column)
{
	return m_array2D.Select(m_row, column);
}
#endif

