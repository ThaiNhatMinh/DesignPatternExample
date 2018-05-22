#include "stdafx.h"
#include "MinerState.h"
#include "Miner.h"
#include "MessageDispatcher.h"
#include "MessageType.h"
#include <iostream>

using std::cout;

void EnterMineAndDigForNugget::Enter(Miner * pMiner)
{
	if (pMiner->Location() != goldmine)
	{
		cout << "\n" << pMiner->GetName() << ": " << "Walking to the goldmine";

		pMiner->ChangeLocation(goldmine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner * miner)
{
	miner->AddToGoldCarried(1);
	miner->IncreaseFatigue();
	cout << "\n" << miner->GetName() << ": " << "Pickin' up a nugget";

	if (miner->PocketsFull())
	{
		miner->GetFSM().ChangeState(VisitBankAndDepositGold::Get());
	}

	if (miner->Thirsty())
	{
		miner->GetFSM().ChangeState(QuenchThirst::Get());
	}

}

void EnterMineAndDigForNugget::Exit(Miner * miner)
{
	cout << "\n" << miner->GetName() << ": "
		<< "I am leaving the goldmine with max pockets full of sweet gold";
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{
	
	if (pMiner->Location() != bank)
	{
		cout << "\n" << pMiner->GetName() << ": " << "Going to the bank. Yes siree";

		pMiner->ChangeLocation(bank);
	}
}

void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
	pMiner->AddToWealth(pMiner->GoldCarried());

	pMiner->SetGoldCarried(0);

	cout << "\n" << pMiner->GetName() << ": "
		<< "Depositing gold. Total savings now: " << pMiner->Wealth();

	if (pMiner->Wealth() >= ComfortLevel)
	{
		cout << "\n" << pMiner->GetName() << ": "
			<< "WooHoo! Rich enough for now. Back home to mah li'lle lady";

		pMiner->GetFSM().ChangeState(GoHomeAndSleepTilRested::Get());
	}

	else
	{
		pMiner->GetFSM().ChangeState(EnterMineAndDigForNugget::Get());
	}

}


void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
	cout << "\n" << pMiner->GetName() << ": " << "Leaving the bank";
}


bool GoHomeAndSleepTilRested::OnMessage(Miner *pMiner, const Telegram & msg)
{
	switch (msg.Msg)
	{
	case MsgType::Msg_StewReady:
	{
		cout << "\n" <<pMiner->GetName()
			<< ": Okay Hun, ahm a comin'!";

		pMiner->GetFSM().ChangeState(EatStew::Get());
		return true;

	}
	default:
		return false;
	}

	return false;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
	if (pMiner->Location() != shack)
	{
		cout << "\n" << pMiner->GetName() << ": " << "Walking home";

		pMiner->ChangeLocation(shack);
	}
	
	MessageDispatcher::Get()->DispatchMessage(0, pMiner->GetID(), pMiner->GetWife()->GetID(), MsgType::Msg_HiHoneyImHome, nullptr);
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{
	if (!pMiner->Fatigued())
	{
		cout << "\n" << pMiner->GetName() << ": "
			<< "What a God darn fantastic nap! Time to find more gold";

		pMiner->GetFSM().ChangeState(EnterMineAndDigForNugget::Get());
	}

	else
	{
		//sleep
		pMiner->DecreaseFatigue();

		cout << "\n" << pMiner->GetName() << ": " << "ZZZZ... ";
	}
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{
	cout << "\n" << pMiner->GetName() << ": " << "Leaving the house";
}


void QuenchThirst::Enter(Miner* pMiner)
{
	if (pMiner->Location() != saloon)
	{
		pMiner->ChangeLocation(saloon);

		cout << "\n" <<pMiner->GetName() << ": " << "Boy, ah sure is thusty! Walking to the saloon";
	}
}

void QuenchThirst::Execute(Miner* pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();

		cout << "\n" <<pMiner->GetName() << ": " << "That's mighty fine sippin' liquer";

		pMiner->GetFSM().ChangeState(EnterMineAndDigForNugget::Get());
	}

	else
	{
		cout << "\nERROR!\nERROR!\nERROR!";
	}
}

void QuenchThirst::Exit(Miner* pMiner)
{
	cout << "\n" <<pMiner->GetName() << ": " << "Leaving the saloon, feelin' good";
}

void EatStew::Enter(Miner* pMiner)
{
	cout << "\n" << pMiner->GetName() << ": " << "Smells Reaaal goood Elsa!";
}

void EatStew::Execute(Miner* pMiner)
{
	cout << "\n" << pMiner->GetName() << ": " << "Tastes real good too!";

	pMiner->GetFSM().RevertToPreviousState();
}

void EatStew::Exit(Miner* pMiner)
{
	cout << "\n" << pMiner->GetName() << ": " << "Thankya li'lle lady. Ah better get back to whatever ah wuz doin'";
}
