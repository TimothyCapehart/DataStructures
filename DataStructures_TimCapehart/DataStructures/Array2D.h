#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <iostream>
#include <string>
#include "Exception.h"
#include "Array.h"
using namespace std;

template<class T>
class Row;

template<class T>
class Array2D
{
private:
	Array<T> m_array;
	int m_row;
	int m_col;
	int m_size;
public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D<T> & rhs);
	~Array2D();
	Array2D<T> & operator=(const Array2D<T> & rhs);
	Row<T> operator[](int index);
	Row<T> operator[](int index) const;
	int getRow() const;
	int getRow();
	void setRow(int rows);
	int getColumn() const;
	int getColumn();
	void setColumn(int columns);
	int getSize() const;
	int getSize();
	void setSize();
	T & Select(int row, int column);
	T & getData(int index) const;
	T & getData(int index);

};

template<class T>
inline Array2D<T>::Array2D()
{
	m_array.setLength(1);
	m_array.setStartIndex(0);
	m_row = 1;
	m_col = 1;
	m_size = 1;
}

template<class T>
inline Array2D<T>::Array2D(int row, int col)
{
	if (row < 1 || col < 1) // check for invalid parameters
	{
		throw Exception("Invalid. Must have at least 1 row and column.");
	}
	else
	{
		try // Reset size
		{
			m_array.setLength(row*col);
		}
		catch (std::bad_alloc bad)
		{
			std::string b_a_msg = "Cannot allocate" + *bad.what();
			throw Exception(b_a_msg.c_str());
		}
		// Set data members
		m_row = row;
		m_col = col;
		m_size = row * col;
		m_array.setLength(m_size);
		m_array.setStartIndex(0);
	}
}

template<class T>
inline Array2D<T>::~Array2D()
{
	
}

template<class T>
inline Array2D<T>::Array2D(const Array2D<T> & rhs)
{
	try //Reset length and start index
	{
		m_array.setLength(rhs.getRow() * rhs.getColumn());
	}
	catch (std::bad_alloc bad)
	{
		std::string b_a_msg = "Cannot allocate";
		throw Exception(b_a_msg.c_str());
	}
	
	m_array.setStartIndex(0);
	//Set data members
	m_row = rhs.getRow();
	m_col = rhs.getColumn();
	m_size = m_row * m_col;
	m_array = rhs.m_array;
}

template<class T>
inline Array2D<T> & Array2D<T>::operator=(const Array2D<T> & rhs) //assignment
{
	//Reset length and data members
	try
	{
		m_array.setLength(rhs.getRow() * rhs.getColumn());
	}
	catch (Exception &e)
	{
		std::cerr << e.getMessage() << std::endl;
	}
	m_row = rhs.getRow();
	m_col = rhs.getColumn();
	m_size = m_row * m_col;

	//Fill elements
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = rhs.m_array[i];
	}
	return *this;
}

template<class T>
inline Row<T> Array2D<T>::operator[](int index)
{
	return Row<T>(*this, index);
}

template<class T>
inline Row<T> Array2D<T>:: operator[](int index) const
{
	return Row<T>(*this, index);
}

template<class T>
inline int Array2D<T>::getRow() 
{
	return m_row;
}

template<class T>
inline int Array2D<T>::getRow() const
{
	return m_row;
}

template<class T>
inline int Array2D<T>::getColumn() const
{
	return m_col;
}

template<class T>
inline int Array2D<T>::getColumn() 
{
	return m_col;
}

template<class T>
inline void Array2D<T>::setRow(int rows)
{
	if (rows < 1)
	{
		throw Exception("Invalid. Must have at least 1 row.");
	}
	try
	{
		m_array.setLength(rows * m_col);
	}
	catch (bad_alloc bad)
	{
		std::cerr << bad.what() << std::endl;
	}
	m_row = rows;
	this->setSize();
}

template<class T>
inline void Array2D<T>::setColumn(int columns)
{
	if (columns < 1)
	{
		throw Exception("Invalid. Must have at least 1 column.");
	}
	if (columns < m_col)
	{
		Array2D<T> temp(m_row, columns);
		for (size_t i = 0; i < m_row; i++)
			for (size_t j = 0; j < columns; j++)
				temp.Select(i, j) = this->Select(i, j);
		m_array = temp.m_array;
		m_col = columns;
		this->setSize();
	}
	else
	{
		try
		{
			m_array.setLength(columns * m_row);
		}
		catch (bad_alloc bad)
		{
			std::cerr << bad.what() << std::endl;
		}
		m_col = columns;
		this->setSize();
	}
}

template<class T>
inline T & Array2D<T>::Select(int row, int column)
{
	if (column > m_col || row > m_row)
	{
		std::cout << "Row: " << row << "\tCol: " << column << std::endl;
		throw Exception("Invalid row or column. Out of bounds.");
	}
	else if (column < 0 || row < 0)
	{
		std::cout << "Row: " << row << "\tCol: " << column << std::endl;
		throw Exception("Invalid row or column. Out of bounds.");
	}

	return m_array[m_col * row + column];
} 

template<class T>
inline T & Array2D<T>::getData(int index) const
{
	return m_array[index];
}

template<class T>
inline T & Array2D<T>::getData(int index) 
{
	return m_array[index];
}

template<class T>
inline int Array2D<T>::getSize() const
{
	return m_size;
}

template<class T>
inline int Array2D<T>::getSize() 
{
	return m_size;
}

template<class T>
inline void Array2D<T>::setSize()
{
	m_size = m_row * m_col;
}
#endif