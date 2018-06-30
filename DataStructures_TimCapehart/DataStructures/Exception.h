#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>
#include <string>
#include <cstring>

const int MAX = 140;

class Exception
{
private:
	char * m_msg;
	wchar_t * w_msg;
public:
	Exception();
	Exception(const char * msg);
	Exception(const wchar_t * msg);
	Exception(const Exception & copy);
	~Exception();
	Exception & operator= (const Exception & rhs);
	char* getMessage() const;
	//const wchar_t * message() const;
	const wchar_t * getMessageWcharT() const;
	const wchar_t * getMessageWcharT();
	void setMessage(char * msg);
	friend std::ostream & operator<<(std::ostream & stream, const Exception & except);
};

inline Exception::Exception()
{
	m_msg = new char[MAX];
	m_msg = '\0';
}

inline Exception::Exception(const char * msg)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

inline Exception::Exception(const wchar_t * msg)
{
	w_msg = new wchar_t[MAX];
	
}

inline Exception::~Exception()
{
	delete m_msg;
}

inline Exception::Exception(const Exception & copy)
{
	m_msg = new char[MAX];
	m_msg = copy.getMessage();
}

inline char * Exception::getMessage() const
{
	return m_msg;
}

//inline const wchar_t * Exception::message() const
//{
//	return w_msg;
//}

inline Exception & Exception::operator= (const Exception & rhs)
{
	m_msg = rhs.getMessage();
}

inline void Exception::setMessage(char *msg)
{
	m_msg = msg;
}

inline std::ostream & operator<< (std::ostream & stream, const Exception & except)
{
	stream << "Message: " << except.getMessage() << std::endl;
	return stream;
}
inline const wchar_t * Exception::getMessageWcharT() const
{
	const size_t size = strlen(m_msg) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, m_msg, size);
	return wText;
}

inline const wchar_t * Exception::getMessageWcharT()
{
	const size_t size = strlen(m_msg) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, m_msg, size);
	return wText;
}

#endif
