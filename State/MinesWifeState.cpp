#include "stdafx.h"
#include "MinesWifeState.h"

#include <ctime>
#include <stdlib.h>
#include "MinersWife.h"
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
	if (RandFloat() < 0.1)
	{
		wife->GetFSM()->ChangeState(VisitBathroom::Get());
	}
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
