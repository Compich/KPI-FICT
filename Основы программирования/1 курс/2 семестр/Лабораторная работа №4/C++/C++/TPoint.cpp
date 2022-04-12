#include "TPoint.h"

ostream& operator << (ostream& os, const TPoint& a_p)
{
	return os << "(x; y; z): (" << a_p.pX << "; " << a_p.pY << "; " << a_p.pZ << ')';
}

istream& operator >> (istream& is, TPoint& a_p)
{
	char ch1, ch2;

	return is >> a_p.pX >> ch1 >> a_p.pY >> ch2 >> a_p.pZ;
}