#include "stdafx.h"
#include "MessageDispatcher.h"
#include "EnityManager.h"
#include <ctime>
MessageDispatcher::MessageDispatcher(EnityManager* enitymgr):m_pEnityMgr(enitymgr)
{
}


MessageDispatcher::~MessageDispatcher()
{
}

void MessageDispatcher::DispatchMessage(float delay, int sender, int receiver, int msg, void * extra_info)
{
	GameObject* pReceiver = m_pEnityMgr->GetEnity(receiver);

	Telegram telegram{ 0,sender,receiver,msg,extra_info };
	if (delay <= 0)
	{
		Dispatche(pReceiver, telegram);
	}
	else
	{
		std::time_t result = time(nullptr);
		double t = result;
		telegram.DispatchTime = t + delay;
		PriorityQ.insert(telegram);

	}
}

void MessageDispatcher::DispatchDelayMsg()
{
	double t = (double)time(nullptr);

	while (PriorityQ.begin()->DispatchTime < t && PriorityQ.begin()->DispatchTime>0)
	{
		Telegram telegram = *PriorityQ.begin();
		GameObject* pReceiver = m_pEnityMgr->GetEnity(telegram.Reciever);
		Dispatche(pReceiver, telegram);
		PriorityQ.erase(PriorityQ.begin());

	}

}
