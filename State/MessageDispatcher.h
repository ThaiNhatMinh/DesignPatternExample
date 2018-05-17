#pragma once
#include <set>
#include "Telegram.h"
class GameObject;
class EnityManager;
class MessageDispatcher
{
private:
	std::set<Telegram> PriorityQ;
	EnityManager* m_pEnityMgr;
	void Dispatche(GameObject* pReceiver, const Telegram& msg);
public:
	MessageDispatcher(EnityManager* enitymgr);
	~MessageDispatcher();

	void DispatchMessage(float delay, int sender, int receiver, int msg, void* extra_info);

	void DispatchDelayMsg();
};

