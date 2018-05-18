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

	virtual bool HandleMessage(const Telegram& telegram) { return 1; }

};