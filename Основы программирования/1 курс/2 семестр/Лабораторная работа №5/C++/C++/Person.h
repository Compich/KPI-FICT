#pragma once
#include "TDate.h"

using std::string;

class Person
{
public:
	Person(const string& name, const TDate& dtBirthday) :m_sName{ name }, m_dtBirthday{ dtBirthday } {}
	Person();
	string getName() const { return m_sName; }
	TDate getBirthday() const { return m_dtBirthday; }
	int getAge() const;
protected:
	virtual double getSalary() const = 0;
private:
	string m_sName;
	TDate m_dtBirthday;
};