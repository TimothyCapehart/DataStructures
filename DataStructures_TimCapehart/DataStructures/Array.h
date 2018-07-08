#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"
#include <cstring>

template <class T>
class Array
{
private:
	T * m_array;
	int m_length;
	int m_start_index;
public:
	Array();
	Array(int length);
	Array(int length, int start_index);
	Array(const Array<T> & copy);
	~Array();
	T & operator[](int index);
	T & operator[](int index) const;
	Array & operator=(const Array & rhs);
	int getStartIndex() const;
	int getLength() const;
	void setStartIndex(int start_index);
	void setLength(int length);
	T & getData(int index) { return m_array[index]; };
};

template<class T>
inline Array<T>::Array()
{
	m_array = new T[1];
	m_length = 1;
	m_start_index = 0;
}

template<class T>
inline Array<T>::Array(int length)
{
	try
	{
		if (length <= 0)
		{
			throw Exception("Length must be at least 1");
		}

		m_length = length;
		m_start_index = 0;
		m_array = new T[length];
	}
	catch (std::bad_alloc bad)
	{
		std::string b_a_msg = "Cannot allocate";
		b_a_msg += bad.what();
		throw Exception(b_a_msg.c_str());
	}

}
template<class T>
inline Array<T>::Array(int length, int start_index)
{
	try
	{
		if (length <= 0)
		{
			throw Exception("Length must be at least 1");
		}

		m_length = length;
		m_start_index = start_index;
		m_array = new T[length];
	}
	catch (std::bad_alloc bad)
	{
		std::string b_a_msg = "Cannot allocate";
		b_a_msg += bad.what();
		throw Exception(b_a_msg.c_str());
	}

}
template<class T>
inline 	T & Array<T>::operator[](int index) const 
{
	int r_index = 0;
	int max_index = m_start_index + m_length - 1;
	// check if less than start index

	if (index < m_start_index)
	{
		throw Exception("Index less than start");
	}
	// check if start_index is negative
	else if (m_start_index < 0)
	{
		if (index > max_index)
		{
			throw Exception("Index out of bounds");
		}
		else
			r_index = index - m_start_index;

	}
	// start_index 0 or greater
	else if (m_start_index >= 0)
	{
		if (index > max_index)
		{
			throw Exception("Index out of bounds");
		}
		else
		{
			r_index = index - m_start_index;
		}
	}
	else
	{
		throw Exception("Unknown error");
	}
	return m_array[r_index];
}

template<class T>
inline Array<T>::Array(const Array<T> & copy)
{
	try
	{
		m_array = new T[copy.getLength()];
	}
	catch (std::bad_alloc bad)
	{
		std::string b_a_msg = "Cannot allocate";
		b_a_msg += bad.what();
		throw Exception(b_a_msg.c_str());
	}
	m_length = copy.getLength();
	m_start_index = copy.getStartIndex();
	
	for (int i = copy.getStartIndex(); i < m_length + copy.getStartIndex(); i++)
	{
		m_array[i - copy.getStartIndex()] = copy[i];
	}
}

template<class T>
inline Array<T>::~Array()
{
	delete[] m_array;
}

template<class T>
inline T & Array<T>::operator[](int index)
{
	int r_index = 0;
	int max_index = m_start_index + m_length - 1;
	// check if less than start index
	
	if (index < m_start_index)
	{
		throw Exception("Index less than start");
	}
	// check if start_index is negative
	else if (m_start_index < 0)
	{
		if (index > max_index)
		{
			throw Exception ("Index out of bounds");
		}
		else
			r_index = index - m_start_index;

	}
	// start_index 0 or greater
	else if (m_start_index >= 0)
	{
		if (index > max_index)
		{
			throw Exception ("Index out of bounds");
		}
		else
		{
			r_index = index - m_start_index;
		}
	}
	else
	{
		throw Exception ("Unknown error");
	}
	return m_array[r_index];
}

template<class T>
inline Array<T> & Array<T>::operator=(const Array<T> & rhs) 
{
	delete[] m_array;
	m_array = new T[rhs.getLength()];
	m_length = rhs.getLength();
	m_start_index = rhs.getStartIndex();

	for (int i = 0; i < rhs.getLength(); i++)
	{
		m_array[i] = rhs.m_array[i];
	}
	return *this;
}

template<class T>
inline int Array<T>::getLength() const
{
	return m_length;
}

template<class T>
inline int Array<T>::getStartIndex() const
{
	return m_start_index;
}

template<class T>
inline void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<class T> 
inline void Array<T>::setLength(int length)
{
	if (length < 1) // length must be at least 1
	{
		throw Exception("Invalid length");
	}
	if (length == m_length)
	{
		m_length = length;
	}
	else
	{
		size_t shorterLength = (length < m_length) ? length : m_length;

		T *temp = new T[length];
		//Array<T> copy(this);

		for (size_t i = 0; i < shorterLength; ++i)
		{
			temp[i] = m_array[i];
		}
		delete[] m_array;
		m_array = temp;

		m_length = length;
	}
}
#endif
