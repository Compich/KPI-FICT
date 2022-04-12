#include "Person.h"
int Person::getAge() const
{
	TDate dtCurrent = TDate::getCurrentDate();

	int nYears;
	int aDaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	nYears = dtCurrent.year - m_dtBirthday.year;

	if (dtCurrent.month < m_dtBirthday.month || (dtCurrent.month == m_dtBirthday.month && dtCurrent.day < m_dtBirthday.day))
	{
		--nYears;
	}

	return nYears;
}

Person::Person()
{
	string rgLastNames[31]{
		"�����", "��������", "��������", "ó�������",
		"���������", "�������", "�������", "���������",
		"��������", "��������", "����", "���������",
		"�����", "����", "����������", "�������",
		"����", "�������", "�����", "����", "�������",
		"��������", "�������", "�����", "�������",
		"ѳ���", "���������", "�������", "������",
		"������", "������"
	};

	string rgFirstNames[16]{
		"�����", "����", "����", "����", "���������",
		"���������", "������", "������", "������",
		"������", "������", "������", "³����",
		"�����", "���", "����"
	};

	string rgPatronymics[20]{
		"�������������", "��������", "���������",
		"�������������", "����������", "����������",
		"�������", "³��������", "�����������",
		"���������", "���������", "��������",
		"����", "��������", "�������������",
		"������������", "���������",
		"�������������", "���������",
		"³��������"
	};

	m_sName = rgLastNames[rand() % 31] + ' ' + rgFirstNames[rand() % 16] + ' ' + rgPatronymics[rand() % 20];
	m_dtBirthday = TDate();
}