#include "stdafx.h"
#include "MinesWifeState.h"

#include <ctime>
#include <stdlib.h>
#include "MinersWife.h"
#include "Telegram.h"
#include "MessageType.h"
#include "MessageDispatcher.h"
#include <iostream>

using std::cout;
float RandFloat()
{
	srand(time(nullptr));

	float r = (rand() % 10) / 10;
	return r;
}

int RandInt(int min, int max)
{
	srand(time(nullptr));
	int r = (rand() % (max - min) + min);
	return r;
}
void WifesGlobalState::Execute(MinersWife* wife)
{
	//1 in 10 chance of needing the bathroom
	if (RandFloat() < 0.1 && !wife->GetFSM()->isInState(*VisitBathroom::Get()))
	{
		wife->GetFSM()->ChangeState(VisitBathroom::Get());
	}
}

bool WifesGlobalState::OnMessage(MinersWife *wife, const Telegram & msg)
{
	switch (msg.Msg)
	{
	case MsgType::Msg_HiHoneyImHome:
	{
		cout << "\n" << wife->GetName() <<
			": Hi honey. Let me make you some of mah fine country stew";

		wife->GetFSM()->ChangeState(CookStew::Get());
		return true;
	}
	default:
		return false;
	}

	return false;

}



void DoHouseWork::Enter(MinersWife* wife)
{
}


void DoHouseWork::Execute(MinersWife* wife)
{
	switch (RandInt(0, 2))
	{
	case 0:

		cout << "\n" << wife->GetName() << ": Moppin' the floor";

		break;

	case 1:

		cout << "\n" << wife->GetName() << ": Washin' the dishes";

		break;

	case 2:

		cout << "\n" << wife->GetName() << ": Makin' the bed";

		break;
	}
}

void DoHouseWork::Exit(MinersWife* wife)
{
}




void VisitBathroom::Enter(MinersWife* wife)
{
	cout << "\n" << wife->GetName() << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
}


void VisitBathroom::Execute(MinersWife* wife)
{
	cout << "\n" << wife->GetName() << ": Ahhhhhh! Sweet relief!";

	wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* wife)
{
	cout << "\n" << wife->GetName() << ": Leavin' the Jon";
}

void CookStew::Enter(MinersWife* wife)
{
	//if not already cooking put the stew in the oven
	if (!wife->isCooking())
	{
		cout << "\n" << wife->GetName() << ": Putting the stew in the oven";

		//send a delayed message myself so that I know when to take the stew
		//out of the oven
		MessageDispatcher::Get()->DispatchMessage(1.5,                  //time delay
			wife->GetID(),           //sender ID
			wife->GetID(),           //receiver ID
			Msg_StewReady,        //msg
			nullptr);

		wife->SetCooking(true);
	}
}


void CookStew::Execute(MinersWife* wife)
{
	cout << "\n" << wife->GetName() << ": Fussin' over food";
}

void CookStew::Exit(MinersWife* wife)
{
	

	cout << "\n" << wife->GetName() << ": Puttin' the stew on the table";
}


bool CookStew::OnMessage(MinersWife* wife, const Telegram& msg)
{
	

	switch (msg.Msg)
	{
	case Msg_StewReady:
	{
		
		cout << "\n" << wife->GetName() << ": StewReady! Lets eat";

		//let hubby know the stew is ready
		MessageDispatcher::Get()->DispatchMessage(0,
			wife->GetID(),
			wife->GetHusband()->GetID(),
			Msg_StewReady,
			nullptr);

		wife->SetCooking(false);

		wife->GetFSM()->ChangeState(DoHouseWork::Get());
	}

	return true;

	}//end switch

	return false;
}