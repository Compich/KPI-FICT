#pragma once
#include <iostream>

using std::ostream;
using std::istream;
using std::endl;

struct TPoint
{
	TPoint(double x = 0, double y = 0, double z = 0) :pX{ x }, pY{ y }, pZ{ z } {}
	double pX, pY, pZ;
};

ostream& operator << (ostream& os, const TPoint& a_p);
istream& operator >> (istream& is, TPoint& a_p);