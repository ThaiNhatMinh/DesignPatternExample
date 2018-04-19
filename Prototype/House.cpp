#include "stdafx.h"

House::House(int maxHumman, int houseCost, const std::string & name):MaxHumman(maxHumman),HouseCost(houseCost),Name(name)
{

}

void House::AddHumman(Humman * pHumman)
{
	m_Hummans.push_back(pHumman);
}

const std::string & House::GetHouseName()
{
	return Name;
}

void House::SetHouseName(const std::string & name)
{
	Name = name;
}

void House::SetHouseCost(int cost)
{
	HouseCost = cost;
}

void House::RemoveChild(const std::string & name)
{
	for (auto el = m_Hummans.begin(); el != m_Hummans.end(); el++)
		if ((*el)->GetName() == name)
		{
			m_Hummans.erase(el);
			return;
		}
}

void House::PrintData()
{
	std::cout << "House: " << Name << ", Cost: " << HouseCost << std::endl;

	for (auto& el : m_Hummans)
	{
		std::cout << "Member: " << el->GetName() << std::endl;
	}
}

ICloneable * House::CloneObject()
{
	House* pHouse = nullptr;
#if (CLONE_TYPE==DEEP_CLONE)
	pHouse = new House(MaxHumman,HouseCost,Name);
	for (size_t i = 0; i < m_Hummans.size(); i++)
	{
		pHouse->m_Hummans.push_back(new Humman(*m_Hummans[i]));
	}
#elif (CLONE_TYPE==SHALLOW_CLONE)
	pHouse = new House(*this);
#endif
	return pHouse;
}
