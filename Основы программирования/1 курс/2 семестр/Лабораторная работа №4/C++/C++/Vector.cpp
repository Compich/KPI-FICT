#include "Vector.h"

Vector& Vector::operator +=(double a_dbAngle)
{
	m_dbPolar += a_dbAngle;

	return *this;
}

bool Vector::operator == (const Vector& a_v) const
{
	TPoint thisCartesian = toCartesian();
	TPoint secondCartesian = a_v.toCartesian();

	double dX = thisCartesian.pX / secondCartesian.pX;
	double dY = thisCartesian.pY / secondCartesian.pY;
	double dZ = thisCartesian.pZ / secondCartesian.pZ;

	return equalDouble(dX, dY) && equalDouble(dY, dZ);
}

bool Vector::operator != (const Vector& a_v) const
{
	return !(*this == a_v);
}

Vector::Vector(double a_dbR, double a_dbPolar, double a_dbAzimuthal)
{
	if (a_dbR < 0)
	{
		a_dbR = 0;
	}

	while (a_dbPolar < 0)
	{
		a_dbPolar = 180 + a_dbPolar;
	}
	while (180 < a_dbPolar)
	{
		a_dbPolar -= 180;
	}

	while (a_dbAzimuthal < 0)
	{
		a_dbAzimuthal = 360 + a_dbAzimuthal;
	}
	while (360 <= a_dbAzimuthal)
	{
		a_dbAzimuthal -= 360;
	}

	m_dbR = a_dbR;
	m_dbPolar = a_dbPolar;
	m_dbAzimuthal = a_dbAzimuthal;
}

Vector::Vector(const TPoint& point)
	:Vector(
		sqrt(pow(point.pX, 2) + pow(point.pY, 2) + pow(point.pZ, 2)),
		180.f / M_PI * acos(point.pZ / sqrt(pow(point.pX, 2) + pow(point.pY, 2) + pow(point.pZ, 2))),
		180.f / M_PI * atan(point.pY / point.pX)
	)
{
}

Vector::Vector()
	:m_dbR{ static_cast<double>(rand() % 1001) / 10.f }, 
	m_dbPolar{ static_cast<double>(rand() % 1801) / 10.f }, 
	m_dbAzimuthal{ static_cast<double>(rand() % 3600) / 10.f }
{
}

TPoint Vector::toCartesian() const {
	double x = m_dbR * sin(m_dbPolar * M_PI / 180) * cos(m_dbAzimuthal * M_PI / 180);
	double y = m_dbR * sin(m_dbPolar * M_PI / 180) * sin(m_dbAzimuthal * M_PI / 180);
	double z = m_dbR * cos(m_dbPolar * M_PI / 180);

	return TPoint(x, y, z);
}

bool equalDouble(double db1, double db2)
{
	return abs(db1 - db2) <= std::numeric_limits<double>::epsilon();
}

ostream& operator<<(ostream& os, const Vector& a_v)
{
	return os << "Декартові координати" << endl
		<< a_v.toCartesian() << endl
		<< "Полярні координати" << endl
		<< "(Радіус; полярний; азимутальний): (" << a_v.m_dbR << "; " << a_v.m_dbPolar << "°; " << a_v.m_dbPolar << "°)";
}