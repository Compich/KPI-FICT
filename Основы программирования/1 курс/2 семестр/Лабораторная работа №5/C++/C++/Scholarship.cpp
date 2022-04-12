#include "Scholarship.h"

ostream& operator << (ostream& os, const Scholarship& a_scholarship)
{
	if (a_scholarship == Scholarship::Increased)
	{
		os << "Підвищена";
	}
	else if (a_scholarship == Scholarship::Default)
	{
		os << "Звичайна";
	}
	else
	{
		os << "Відсутня";
	}

	return os;
}