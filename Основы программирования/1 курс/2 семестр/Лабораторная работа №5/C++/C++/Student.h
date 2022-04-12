#pragma once
#include "Person.h"
#include "Scholarship.h"
class Student : public Person
{
public:
	Student(const string&, const TDate&, const string&, double);
	Student();
	Scholarship getScholarship() const;
	double getSalary() const;
	string getGroupName() const { return m_sGroupName; }
	double getGradePointAverage() const { return m_dbGradePointAverage; }
private:
	string m_sGroupName;
	double m_dbGradePointAverage;
};

ostream& operator << (ostream&, const Student&);
