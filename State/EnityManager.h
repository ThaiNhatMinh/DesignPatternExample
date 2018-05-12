#pragma once

#include <map>
#include "GameObject.h"
class EnityManager
{
private:
	typedef std::map<int, GameObject*> GameObjectMap;

private:

	GameObjectMap * m_GameObjects;

	EnityManager() = default;
	EnityManager(const EnityManager& other) = delete;
	EnityManager& operator=(const EnityManager&) = delete;
	static EnityManager* Instance;
public:

	static EnityManager* Get();


	void RegisterEnity(GameObject* obj);
	void RemoveEnity(GameObject* obj);
	GameObject* GetEnity(int id);

};

#define EnityMgr EnityManager::Get()