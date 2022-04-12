#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::endl;

struct Discipline
{
	Discipline(const string& sName, double nNumberOfHours) : m_sName{sName}, m_nNumberOfHours{nNumberOfHours} {}
	Discipline();
	string m_sName;
	double m_nNumberOfHours;
};

ostream& operator << (ostream& os, const Discipline& a_discipline);