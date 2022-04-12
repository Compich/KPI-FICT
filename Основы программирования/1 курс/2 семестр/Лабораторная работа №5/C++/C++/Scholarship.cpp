#include "Scholarship.h"

ostream& operator << (ostream& os, const Scholarship& a_scholarship)
{
	if (a_scholarship == Scholarship::Increased)
	{
		os << "ϳ�������";
	}
	else if (a_scholarship == Scholarship::Default)
	{
		os << "��������";
	}
	else
	{
		os << "³������";
	}

	return os;
}