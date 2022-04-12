#include "Student.h"
Student::Student(const string& name, const TDate& dtBirthday, const string& sGroupName, double dbGradePointAverage)
	:Person(name, dtBirthday), m_sGroupName{ sGroupName }, m_dbGradePointAverage{ dbGradePointAverage }
{}

Scholarship Student::getScholarship() const
{
	Scholarship resultScholarship;

	if (95 <= m_dbGradePointAverage)
	{
		resultScholarship = Scholarship::Increased;
	}
	else if (85 <= m_dbGradePointAverage)
	{
		resultScholarship = Scholarship::Default;
	}
	else
	{
		resultScholarship = Scholarship::None;
	}

	return resultScholarship;
}

double Student::getSalary() const
{
	Scholarship scholarship = getScholarship();
	double nScholarshipSum;

	if (scholarship == Scholarship::Default)
	{
		nScholarshipSum = 2000;
	}
	else if (scholarship == Scholarship::Increased)
	{
		nScholarshipSum = 2550;
	}
	else
	{
		nScholarshipSum = 0;
	}

	return nScholarshipSum;
}

ostream& operator << (ostream& os, const Student& a_student)
{
	os << "ϲ� ��������: " << a_student.getName() << endl
		<< "���� ����������: " << a_student.getBirthday() << " (��: " << a_student.getAge() << ')' << endl
		<< "����� ��������� �����: " << a_student.getGroupName() << endl
		<< "������� ����������� ���: " << a_student.getGradePointAverage() << endl
		<< "��������: " << a_student.getScholarship() << endl
		<< "̳������ ��������: " << a_student.getSalary() << " ���.";

	return os;
}

//istream& operator >> (istream& is, Student& a_student)
//{
//	string sName;
//	TDate dtBirthday;
//	string sGroupName;
//	double dbGradePointAverage;
//
//	cout << "������ ��'� ��������: ";
//	is >> sGroupName;
//
//	cout << "������ ���� ���������� ��������: ";
//	is >> dtBirthday;
//
//	cout << "������ ����� ��������� ����� ��������: ";
//	is >> sGroupName;
//
//	cout << "������ ������� ����������� ��� ��������: ";
//	is >> dbGradePointAverage;
//
//	a_student = Student(sName, dtBirthday, sGroupName, dbGradePointAverage);
//
//	return is;
//}

Student::Student()
{
	string rgGroupPrefixes[8] = {
		"��", "��", "��", "��", "��", "��", "��", "��"
	};

	
	m_sGroupName = rgGroupPrefixes[rand() % 8] + '-' + to_string(11 + rand() % 5);
	m_dbGradePointAverage = static_cast<double>(6000 + rand() % 4001) / 100;
}