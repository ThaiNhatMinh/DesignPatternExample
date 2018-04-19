#include "stdafx.h"
#include "City.h"

City::City(const std::string name):GameObject(name)
{
}

void City::AddChild(GameObject * obj)
{
	m_Hummans.push_back(std::unique_ptr<GameObject>(obj));
}

void City::RemoveChild(unsigned int id)
{
	for (auto el  = m_Hummans.begin(); el != m_Hummans.end(); el++)
	{
		if ((*el)->GetID() == id) m_Hummans.erase(el);
	}
}

GameObject * City::GetChild(unsigned int id)
{
	for (auto el = m_Hummans.begin(); el != m_Hummans.end(); el++)
	{
		if ((*el)->GetID() == id) return (*el).get();
	}

	return nullptr;
}

void City::PrintData()
{
	std::cout << "City: " << GetName() << "Population: " << m_Hummans.size() << std::endl;
	for (auto& el : m_Hummans)
	{
		std::cout << " Name: " << el->GetName() << std::endl;
	}

}
