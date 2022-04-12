#include "Functions.h"

Student* generateStudents(size_t a_cCounter)
{
	Student* arr = new Student[a_cCounter];

	for (size_t i = 0; i < a_cCounter; ++i)
	{
		arr[i] = Student();
	}

	return arr;
}

Teacher* generateTeachers(size_t a_cCounter)
{
	Teacher* arr = new Teacher[a_cCounter];

	for (size_t i = 0; i < a_cCounter; ++i)
	{
		arr[i] = Teacher();
	}

	return arr;
}

void outputStudents(const Student* students, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << students[i] << endl << endl;
	}
}

void outputTeachers(const Teacher* teachers, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << teachers[i] << endl << endl;
	}
}

Teacher getTeacherWithHighestSalary(Teacher* teachers, size_t size)
{
	size_t iHighestIndex = 0;
	double dbHighestSalary = teachers[0].getSalary();

	for (int i = 1; i < size; ++i)
	{
		if (dbHighestSalary < teachers[i].getSalary())
		{
			iHighestIndex = i;
			dbHighestSalary = teachers[i].getSalary();
		}
	}

	return teachers[iHighestIndex];
}