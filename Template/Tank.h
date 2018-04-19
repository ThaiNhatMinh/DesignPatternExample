#pragma once


class Tank
{
public:
	Tank(const std::string& name,int HP,int damage);

	void TakeDamage(int damage);
	bool IsDeath();


	int GetHP();
	int GetDamage();
	const std::string& GetName();
private:
	std::string m_Name;
	int HP;
	int Damage;
};