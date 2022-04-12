#include "String.h"

String::String(const string& a_s)
	:m_sStr{ a_s }
{}

String& String::addText(const String& a_s)
{
	m_sStr += a_s.getString();

	return *this;
}

String& String::addText(const string& a_s)
{
	m_sStr += a_s;

	return *this;
}

String& String::setText(const String& a_s)
{
	m_sStr = a_s.getString();

	return *this;
}

String& String::setText(const string& a_s)
{
	m_sStr = a_s;

	return *this;
}

size_t String::count(char c) const
{
	size_t cCounter = 0;

	for (size_t i = 0; i < symbolsCount(); ++i)
	{
		if (m_sStr[i] == c)
		{
			cCounter += 1;
		}
	}

	return cCounter;
}