#include "stdafx.h"

Humman::Humman(const std::string & name, unsigned age):GameObject(name),m_iAge(age)
{
}

unsigned int Humman::GetAge()
{
	return m_iAge;
}
