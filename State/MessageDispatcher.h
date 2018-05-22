#pragma once
#include <set>
#include "Telegram.h"
#include "Singleton.h"
class GameObject;
class EnityManager;
class MessageDispatcher: public Singleton<MessageDispatcher>
{
private:
	std::set<Telegram> PriorityQ;
	
	void Dispatche(GameObject* pReceiver, const Telegram& msg);
public:
	MessageDispatcher();
	~MessageDispatcher();

	void DispatchMessage(float delay, int sender, int receiver, int msg, void* extra_info);

	void DispatchDelayMsg();
};

