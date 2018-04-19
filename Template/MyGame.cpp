#include "stdafx.h"

MyGame::MyGame(const std::string & name):m_GameName(name)
{
}

void MyGame::Init()
{
	/* initialize random seed: */
	srand(time(NULL));

	{
		int hp = rand() % 100;
		int damage = rand() % 20 + 15;
		m_Tank[0] = std::make_unique<Tank>("TankA TR2-04", hp, damage);
	}
	{
		int hp = rand() % 100;
		int damage = rand() % 20 + 15;
		m_Tank[1] = std::make_unique<Tank>("TankB TR9-02", hp, damage);
	}
	
	m_Turn = rand() % 2;
	std::cout << "Game Begin!!!" << std::endl;
}

void MyGame::Shutdown()
{

	std::cout << "Game over!!!" << std::endl;
	char winner = 0;
	if (m_Tank[0]->IsDeath()) winner = 0;
	else winner = 1;

	std::cout << m_Tank[winner]->GetName() << " is Winner!" << std::endl;

	
}

void MyGame::Update(float dt)
{
}

void MyGame::Render()
{
	int damage = m_Tank[m_Turn]->GetDamage();

	char other = (m_Turn + 1) % 2;
	m_Tank[other]->TakeDamage(damage);
	std::cout << m_Tank[m_Turn]->GetName() << " Attack " << m_Tank[other]->GetName() << " with " << damage << " damage!" << std::endl;
	m_Turn = other;
}

bool MyGame::CanRun()
{
	bool result = (m_Tank[0]->IsDeath()||m_Tank[1]->IsDeath());
	return result;
}
