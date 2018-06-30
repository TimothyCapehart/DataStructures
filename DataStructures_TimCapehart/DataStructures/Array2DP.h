#ifndef ARRAY2DP_H
#define ARRAY2DP_H
#include <iostream>
#include <string>
#include "Exception.h"
//using namespace std;

template<class T>
class RowP;

template<class T>
class Array2DP
{
private:
	T ** m_array;
	int m_row;
	int m_col;
	int m_size;
	
public:
	Array2DP();
	Array2DP(int row, int col);
	Array2DP(const Array2DP &);
	~Array2DP();
	void purge();
	void purgeRows();
	Array2DP & operator=(const Array2DP & rhs);
	RowP<T> operator[](int index);
	T & Select(int row, int column);
	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int columns);
	int getSize() const;
	void setSize();
};

template<class T>
inline Array2DP<T>::Array2DP()
{
	m_array = new T*[1];
	m_row = 1;
	m_col = 1;
	m_size = 1;
}

template<class T>
inline Array2DP<T>::Array2DP(int row, int col)
{
	if (row < 1 || col < 1) // check for invalid parameters
	{
		throw Exception("Invalid. Must have at least 1 row and column.");
	}
	try
	{
		m_array = new T*[row];
	}
	catch (std::bad_alloc bad)
	{
		std::cerr << bad.what() << std::endl;
	}
	for (int i = 0; i < row; i++)
	{
		try
		{
			m_array[i] = new T[col];
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what() << std::endl;
		}
	}
	m_row = row;
	m_col = col;
	m_size = row * col;
}

template<class T>
inline Array2DP<T>::Array2DP(const Array2DP & rhs)
{
	try // allocate 
	{
		m_array = new T*[rhs.getRow()];
	}
	catch (std::bad_alloc bad)
	{
		std::cerr << bad.what() << std::endl;
	}
	for (int i = 0; i < rhs.getRow(); i++)
	{
		m_array[i] = new T[rhs.getColumn()];
	}
	
	// set members
	m_row = rhs.getRow();
	m_col = rhs.getColumn();
	m_size = rhs.getRow() * rhs.getColumn();
	//fill elements
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = rhs.m_array[i][j];
		}
	}
}

template<class T>
inline Array2DP<T>::~Array2DP()
{
	if (m_size == 1)
	{
		delete[]m_array;
	}
	else
	{
		for (int i = 0; i < m_row; i++)
		{
			delete m_array[i];
		}
		delete[] m_array;
	}
}

template<class T>
inline void Array2DP<T>::purge()
{
	if (m_size == 1)
	{
		delete[]m_array;
	}
	else
	{
		for (int i = 0; i < m_row; i++)
		{
			delete m_array[i];
		}
		delete[] m_array;
	}
}

template<class T>
inline void Array2DP<T>::purgeRows()
{
	if (m_size == 1)
	{
		delete[]m_array;
	}
	else
	{
		for (int i = 0; i < m_row; i++)
		{
			delete m_array[i];
		}
	}
}

template<class T>
inline Array2DP<T> & Array2DP<T>::operator=(const Array2DP & rhs)
{
	this->purge();
	try // allocate 
	{
		m_array = new T*[rhs.getRow()];
	}
	catch (std::bad_alloc bad)
	{
		std::cerr << bad.what() << std::endl;
	}
	for (int i = 0; i < rhs.getRow(); i++)
	{
		m_array[i] = new T[rhs.getColumn()];
	}
	// set members
	m_row = rhs.getRow();
	m_col = rhs.getColumn();
	m_size = rhs.getRow() * rhs.getColumn();
	//fill elements
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = rhs.m_array[i][j];
		}
	}
	return *this;
}

template<class T>
inline RowP<T> Array2DP<T>::operator[](int index)
{
	return RowP<T>(*this, index);
}

template<class T>
inline T & Array2DP<T>::Select(int row, int column)
{
	if (column > m_col || row > m_row)
		throw Exception("Invalid row or column. Out of bounds.");
	if (column < 0 || row < 0)
		throw Exception("Invalid row or column. Out of bounds.");

	return m_array[row][column];
}

template<class T>
inline int Array2DP<T>::getRow() const
{
	return m_row;
}

template<class T>
inline int Array2DP<T>::getColumn() const
{
	return m_col;
}

template<class T>
inline int Array2DP<T>::getSize() const
{
	return m_size;
}

template<class T>
inline void Array2DP<T>::setSize()
{
	m_size = m_row * m_col;
}

template<class T>
inline void Array2DP<T>::setRow(int rows)
{
	if (rows < 1)
	{
		throw Exception("Invalid. Must have at least 1 row.");
	}
	if (rows < m_row) // losing rows
	{
		Array2DP<T> copy(*this);
		this->purge();
		try // allocate new size
		{
			m_array = new T*[rows];
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what() << std::endl;
		}
		for (int i = 0; i < rows; i++)
		{
			m_array[i] = new T[copy.getColumn()];
		}
		// set members
		m_row = rows;
		m_col = copy.getColumn();
		setSize();
		//fill elements
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < copy.getColumn(); j++)
			{
				m_array[i][j] = copy.m_array[i][j];
			}
		}
	}
	else if (rows > m_row) // adding rows
	{

		Array2DP<T> copy(*this); // copy this
		this->purge();
		try // allocate new size
		{
			m_array = new T*[rows];
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what() << std::endl;
		}
		for (int i = 0; i < rows; i++)
		{
			m_array[i] = new T[copy.getColumn()];
		}
		// set members
		m_row = rows;
		m_col = copy.getColumn();
		setSize();
		//fill elements
		for (int i = 0; i < copy.getRow(); i++)
		{
			for (int j = 0; j < copy.getColumn(); j++)
			{
				m_array[i][j] = copy.m_array[i][j];
			}
		}
	}
	else // rows == m_rows
	{
		return;
	}
}

template<class T>
inline void Array2DP<T>::setColumn(int columns)
{
	if (columns < 1)
	{
		throw Exception("Invalid. Must have at least 1 row.");
	}
	if (columns < m_col) // losing columns
	{
		Array2DP<T> copy(*this); // copy this
		this->purge();
		try // allocate new size
		{
			m_array = new T*[copy.getRow()];
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what() << std::endl;
		}
		for (int i = 0; i < copy.getRow(); i++)
		{
			m_array[i] = new T[columns];
		}
		//Set Members
		m_row = copy.getRow();
		m_col = columns;
		setSize();
		//Fill 
		for (int i = 0; i < copy.getRow(); i++)
		{
			for (int j = 0; j < columns; j++)
			{
				m_array[i][j] = copy.m_array[i][j];
			}
		}
	}
	else if (columns > m_col)// Add columns
	{
		Array2DP<T> copy(*this); // copy this
		this->purge();
		try // allocate new size
		{
			m_array = new T*[copy.getRow()];
		}
		catch (std::bad_alloc bad)
		{
			std::cerr << bad.what() << std::endl;
		}
		for (int i = 0; i < copy.getRow(); i++)
		{
			m_array[i] = new T[columns];
		}
		//Set Members
		m_row = copy.getRow();
		m_col = columns;
		setSize();
		//Fill 
		for (int i = 0; i < copy.getRow(); i++)
		{
			for (int j = 0; j < copy.getColumn(); j++)
			{
				m_array[i][j] = copy.m_array[i][j];
			}
		}
	}
}
#endif
