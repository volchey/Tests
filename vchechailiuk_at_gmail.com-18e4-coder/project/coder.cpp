/*
 * coder.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Coder class source.
 *
 * You may have to change this file to fix build errors, and make
 * the unit tests pass.
 *
 * Usually source files are used to write an implementation of
 * global and member functions.
 *
 */

#include "coder.h"
#include <string.h>

/*
 * To make all unit tests pass you may try to puzzle out the ::encode() algorithm
 * and it should help you to write the decoding one. But there are other ways to
 * make them pass.
 *
 * Good luck!
 *
 */


Coder::Coder() : m_buf(NULL), m_size(0)
{}

Coder::Coder(const Coder &obj)
{
	m_buf = new char[obj.m_size];
	if (!m_buf)
		std::cout << "Can't allocate memmory" << std::endl;
	else
	{
		memcpy(m_buf, obj.m_buf, obj.m_size);
		m_size = obj.m_size;
	}
}

Coder::~Coder()
{
	delete[] m_buf;
}

void Coder::encode()
{
	::encode( m_buf, m_size );
}

void Coder::set(const char *buf, int size) throw(std::logic_error)
{
	if (!buf || size <= 0)
		throw std::logic_error("Error");
	m_buf = new char[size];
	if (!m_buf)
		std::cout << "Can't allocate memmory" << std::endl;
	else
	{
		memcpy(m_buf, buf, size);
		m_size = size;
	}
}

char *Coder::buf() const
{
	return (m_buf);
}

int Coder::size() const
{
	return (m_size);
}

void Coder::decode()
{
	m_buf[m_size] |= 255;
	for (int i = m_size - 1; i >= 0; --i)
	{
		m_buf[i] ^= m_buf[i + 1];
	}
}

Coder	&Coder::operator=(const Coder &obj)
{
	if (this != &obj)
	{
		delete m_buf;
		m_buf = new char[obj.m_size];
		if (!m_buf)
			std::cout << "Can't allocate memmory" << std::endl;
		else
		{
			memcpy(m_buf, obj.m_buf, obj.m_size);
			m_size = obj.m_size;
		}
		m_size = obj.m_size;
	}
	return (*this);
}
