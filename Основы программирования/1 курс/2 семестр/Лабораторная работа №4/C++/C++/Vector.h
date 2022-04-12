#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include "TPoint.h"

class Vector
{
public:
	Vector(double a_dbR, double a_dbPolar, double a_dbAzimuthal);
	Vector(const TPoint& point);
	Vector();

	double getRadius() const { return m_dbR; }
	double getPolar() const { return m_dbPolar; }
	double getAzimuthal() const { return m_dbAzimuthal; }
	TPoint toCartesian() const;

	Vector& operator +=(double a_dbAngle);
	bool operator == (const Vector& a_v) const;
	bool operator != (const Vector& a_v) const;
private:
	double m_dbR;
	double m_dbPolar;
	double m_dbAzimuthal;
};

bool equalDouble(double db1, double db2);
ostream& operator << (ostream& os, const Vector& a_v);
