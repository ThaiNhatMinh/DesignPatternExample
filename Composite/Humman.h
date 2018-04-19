#pragma once



class Humman : public GameObject
{
public:
	Humman(const std::string& name,unsigned age);

	unsigned int GetAge();
private:
	unsigned int m_iAge;
};