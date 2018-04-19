#include "stdafx.h"

Tank::Tank(const std::string & name,int hp,int damage):m_Name(name),HP(hp),Damage(damage)
{

}

void Tank::TakeDamage(int damage)
{
	if (HP <= 0) return;
	HP -= Damage;
}

bool Tank::IsDeath()
{
	return HP>0;
}

int Tank::GetHP()
{
	return HP;
}

int Tank::GetDamage()
{
	return Damage;
}

const std::string & Tank::GetName()
{
	return m_Name;
}
