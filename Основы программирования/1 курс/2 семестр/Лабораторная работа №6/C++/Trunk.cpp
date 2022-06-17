#include "Trunk.h"

Trunk::Trunk(Trunk* prev, string str)
	:m_prev{ prev },
	m_str{ str }
{
}

ostream& operator << (ostream& os, const Trunk& trunk)
{
	if (trunk.m_prev)
	{
		os << *trunk.m_prev;
	}
	return os << trunk.m_str;
}
