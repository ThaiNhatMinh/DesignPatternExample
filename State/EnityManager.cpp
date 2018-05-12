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
