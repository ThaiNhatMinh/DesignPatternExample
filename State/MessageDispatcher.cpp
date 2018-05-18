#include "stdafx.h"
#include "MessageDispatcher.h"
#include "EnityManager.h"
#include <ctime>
#include <iostream>
using std::cout;
void MessageDispatcher::Dispatche(GameObject * pReceiver, const Telegram & msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
		//telegram could not be handled
		cout << "Message not handled";
	}
}
MessageDispatcher::MessageDispatcher(EnityManager* enitymgr):m_pEnityMgr(enitymgr)
{
}


MessageDispatcher::~MessageDispatcher()
{
}

void MessageDispatcher::DispatchMessage(float delay, int sender, int receiver, int msg, void * extra_info)
{
	GameObject* pReceiver = m_pEnityMgr->GetEnity(receiver);

	Telegram telegram; 
	telegram.DispatchTime = 0;
	telegram.Sender = sender;
	telegram.Receiver = receiver;
	telegram.Msg = msg;
	telegram.ExtraInfo = extra_info;


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
		GameObject* pReceiver = m_pEnityMgr->GetEnity(telegram.Receiver);
		Dispatche(pReceiver, telegram);
		PriorityQ.erase(PriorityQ.begin());

	}

}
