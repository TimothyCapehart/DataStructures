#ifndef ROWP_H
#define ROWP_H
#include "Exception.h"
#include<iostream>

template<class T>
class Array2DP;

template<class T>
class RowP
{
private:
	Array2DP<T> & m_array2D;
	int m_row;
public:
	RowP(Array2DP<T> & inArray, int row);
	T & operator[](int column);
};

template<class T>
inline RowP<T>::RowP(Array2DP<T> & inArray, int row)
	:m_array2D(inArray), m_row(row)
{
	/*m_array2D = inArray;
	m_row = row;*/
}

template<class T>
inline T & RowP<T>::operator[](int column)
{
	return m_array2D.Select(m_row, column);
}
#endif
