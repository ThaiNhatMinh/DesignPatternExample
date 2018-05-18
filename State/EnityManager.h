#pragma once

#include <map>
#include "GameObject.h"
#include "Singleton.h"
class EnityManager: public Singleton<EnityManager>
{
private:
	typedef std::map<int, GameObject*> GameObjectMap;

private:

	GameObjectMap m_GameObjects;

public:




	void RegisterEnity(GameObject* obj);
	void RemoveEnity(GameObject* obj);
	GameObject* GetEnity(int id);

};

#define EnityMgr EnityManager::Get()