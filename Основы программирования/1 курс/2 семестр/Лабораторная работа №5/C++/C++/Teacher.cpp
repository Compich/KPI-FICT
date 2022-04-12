#include "Teacher.h"

Teacher::Teacher(const string& a_sName, const TDate& a_dt)
	: Person(a_sName, a_dt), m_rgDisciplines{ nullptr }, m_cDisciplinesCount{0}
{}

Teacher::Teacher()
	: m_rgDisciplines{ nullptr }, m_cDisciplinesCount { 0 }
{
	int nDisciplinesGoal = 1 + rand() % 3;

	while (m_cDisciplinesCount != nDisciplinesGoal)
	{
		Discipline randomDiscipline;
		bool bIsInArr = false;

		for (size_t i = 0; i < m_cDisciplinesCount; ++i)
		{
			if (m_rgDisciplines[i].m_sName == randomDiscipline.m_sName)
			{
				bIsInArr = true;
			}
		}

		if (!bIsInArr)
		{
			addDiscipline(randomDiscipline);
		}
	}
}

double Teacher::getSalary() const
{
	int nSalaryBase = 500;
	double nTotalSalary = 0;

	for (size_t i = 0; i < getDisciplinesCount(); ++i)
	{
		nTotalSalary += m_rgDisciplines[i].m_nNumberOfHours * nSalaryBase;
	}

	return nTotalSalary;
}

Teacher& Teacher::addDiscipline(const Discipline& a_discipline)
{
	m_cDisciplinesCount += 1;
	Discipline* newDisciplines = new Discipline[m_cDisciplinesCount];

	for (int i = 0; i < m_cDisciplinesCount - 1; ++i)
	{
		newDisciplines[i] = m_rgDisciplines[i];
	}
	
	if (m_rgDisciplines != nullptr)
	{
		delete[] m_rgDisciplines;
	}

	newDisciplines[m_cDisciplinesCount - 1] = a_discipline;

	m_rgDisciplines = newDisciplines;

	return *this;
}

ostream& operator << (ostream& os, const Teacher& a_teacher)
{
	os << "ПІБ викладача: " << a_teacher.getName() << endl
		<< "Дата народження: " << a_teacher.getBirthday() << " (вік: " << a_teacher.getAge() << ')' << endl
		<< "Місячний заробіток: " << a_teacher.getSalary() << " грн." << endl
		<< "Дисципліни викладача:" << endl;

	Discipline* rgTeacherDisciplines = a_teacher.getDisciplines();
	for (size_t i = 0; i < a_teacher.getDisciplinesCount(); ++i)
	{
		os << rgTeacherDisciplines[i];

		if (i != a_teacher.getDisciplinesCount() - 1)
		{
			os << endl;
		}
	}

	return os;
}