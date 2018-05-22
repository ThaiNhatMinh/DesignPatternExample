#pragma once
#include "GameObject.h"
#include "Location.h"
#include "StateMachine.h"
#include "MinesWifeState.h"

class MinersWife : public GameObject
{
private:

	//an instance of the state machine class
	StateMachine<MinersWife>  m_StateMachine;

	location              m_Location;
	bool m_bIsCooking;
	GameObject* m_pHusband;
public:

	MinersWife(const std::string& name) :GameObject(name),
		m_Location(shack),m_StateMachine(this)

	{
		

		m_StateMachine.SetCurrentState(DoHouseWork::Get());

		m_StateMachine.SetGlobalState(WifesGlobalState::Get());
	}

	~MinersWife() { }


	void Update();

	StateMachine<MinersWife>*  GetFSM() { return &m_StateMachine; }

	//----------------------------------------------------accessors
	location Location()const { return m_Location; }
	void          ChangeLocation(const location loc) { m_Location = loc; }

	virtual bool HandleMessage(const Telegram& telegram) { return m_StateMachine.HandleMessage(telegram); }
	bool isCooking() { return m_bIsCooking; }
	void SetCooking(bool cook) { m_bIsCooking = cook; }

	GameObject* GetHusband() { return m_pHusband; }
	void SetHusband(GameObject* obj) { m_pHusband = obj; }
};