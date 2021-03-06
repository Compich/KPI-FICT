#pragma once
#include "Person.h"
#include "Discipline.h"

class Teacher : public Person
{
public:
	Teacher(const string& name, const TDate& dtBirthday);
	Teacher(const Teacher&);
	Teacher(Teacher&&) noexcept;
	Teacher& operator=(Teacher&&) noexcept;
	Teacher();
	double getSalary() const;
	Discipline* getDisciplines() const { return m_rgDisciplines; }
	size_t getDisciplinesCount() const { return m_cDisciplinesCount; }
	Teacher& addDiscipline(const Discipline&);
	~Teacher();
private:
	Discipline* m_rgDisciplines;
	size_t m_cDisciplinesCount;
};

ostream& operator << (ostream&, const Teacher&);