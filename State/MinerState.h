#pragma once


#include "IState.h"
#include "Singleton.h"

class Miner;

class EnterMineAndDigForNugget : public State<Miner>,public Singleton<EnterMineAndDigForNugget>
{

	
public:
	EnterMineAndDigForNugget() = default;
	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
	virtual bool OnMessage(Miner*, const Telegram& msg)override {return 1;}
};

class VisitBankAndDepositGold : public State<Miner>, public Singleton<VisitBankAndDepositGold>
{
private:

	

public:
	VisitBankAndDepositGold() {}
	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
	virtual bool OnMessage(Miner*, const Telegram& msg)override {return 1;}
};

class GoHomeAndSleepTilRested : public State<Miner>,public Singleton<GoHomeAndSleepTilRested>
{


public:

	GoHomeAndSleepTilRested() {}
	virtual bool OnMessage(Miner*, const Telegram& msg)override {return 1;}
	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};


//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
class QuenchThirst : public State<Miner>,public Singleton<QuenchThirst>
{
private:



public:
	QuenchThirst() {}
	virtual bool OnMessage(Miner*, const Telegram& msg)override {return 1;}
	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};

