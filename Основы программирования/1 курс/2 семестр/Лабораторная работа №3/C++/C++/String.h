#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::cout;

class String
{
public:
	String(const string& a_s="");
	size_t symbolsCount() const { return m_sStr.length(); }
	String& addText(const String& a_s);
	String& addText(const string& a_s);
	String& setText(const String& a_s);
	String& setText(const string& a_s);
	string getString() const { return m_sStr; }
	char getSymbol(size_t pos) const { return m_sStr[pos]; }
	size_t count(char c) const;
	void output(ostream& os=cout) { os << m_sStr; }
private:
	string m_sStr;
};

