#include "stdafx.h"
#include "EnityManager.h"

EnityManager * EnityManager::Get()
{
	return Instance;
}

void EnityManager::RegisterEnity(GameObject * obj)
{
	m_GameObjects.insert({obj->GetID(), obj});
}

void EnityManager::RemoveEnity(GameObject * obj)
{
	for (auto itr = m_GameObjects.begin(); itr != m_GameObjects.end(); itr++)
	{
		if (itr->second->GetID() == obj->GetID())
		{
			m_GameObjects.erase(itr);
		}
	}
}

GameObject * EnityManager::GetEnity(int id)
{
	for (auto itr = m_GameObjects.begin(); itr != m_GameObjects.end(); itr++)
		if (itr->second->GetID() == id) return itr->second;

	return nullptr;
}
