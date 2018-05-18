#pragma once
#include "GameObject.h"
#include "Location.h"
#include "StateMachine.h"
#include "MinerState.h"

const int ComfortLevel = 5;
const int MaxNuggets = 3;
const int ThirstLevel = 5;
const int TirednessThreshold = 5;

class Miner : public GameObject
{
private:
	StateMachine<Miner> m_StateMachine;

	location m_Location;
	int m_iGoldCarried;
	int m_iMoneyInBank;
	int m_iThirst;
	int m_iFatigue;

public:
	Miner(const std::string name) :GameObject(name),m_Location(location::shack), m_iGoldCarried(0), m_iFatigue(0), m_iMoneyInBank(0), m_iThirst(0),m_StateMachine(this)
	{
		m_StateMachine.SetCurrentState(GoHomeAndSleepTilRested::Get());
	}

	void Update();

	StateMachine<Miner>&  GetFSM() { return m_StateMachine; }


	location Location()const { return m_Location; }
	void          ChangeLocation(const location loc) { m_Location = loc; }

	int           GoldCarried()const { return m_iGoldCarried; }
	void          SetGoldCarried(const int val) { m_iGoldCarried = val; }
	void          AddToGoldCarried(const int val);
	bool          PocketsFull()const { return m_iGoldCarried >= MaxNuggets; }

	bool          Fatigued()const;
	void          DecreaseFatigue() { m_iFatigue -= 1; }
	void          IncreaseFatigue() { m_iFatigue += 1; }

	int           Wealth()const { return m_iMoneyInBank; }
	void          SetWealth(const int val) { m_iMoneyInBank = val; }
	void          AddToWealth(const int val);

	bool          Thirsty()const;
	void          BuyAndDrinkAWhiskey() { m_iThirst = 0; m_iMoneyInBank -= 2; }


	virtual bool HandleMessage(const Telegram& telegram) { return 1; }
};