#pragma once

#include "IState.h"

template<class Actor>
class StateMachine
{
private:
	Actor * m_pOwner;
	State<Actor>* m_pCurrentState, *m_pPrevState, *m_pGlobalState;


public:
	StateMachine(Actor* pActor) :m_pOwner(pActor), m_pCurrentState(nullptr), m_pGlobalState(nullptr), m_pPrevState(nullptr) {}


	void SetCurrentState(State<Actor>* pState) { m_pCurrentState = pState; }
	void SetGlobalState(State<Actor>* pState) { m_pGlobalState = pState; }
	void SetPrevState(State<Actor>* pState) { m_pPrevState = pState; }
	State<Actor>* GetCurrentState()const { return m_pCurrentState; }
	State<Actor>* GetGlobalState()const { return m_pGlobalState; }
	State<Actor>* GetPrevState()const { return m_pPrevState; }
	void Update() const
	{
		if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);

		if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
	}


	void ChangeState(State<Actor>* pState)
	{
		m_pPrevState = m_pCurrentState;
		m_pCurrentState->Exit(m_pOwner);


		m_pCurrentState = pState;

		m_pCurrentState->Enter(m_pOwner);
	}

	bool HandleMessage(const Telegram& msg)const
	{
		if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
		{
			return 1;
		}
		if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
		{
			return 1;
		}
		return 0;
	}

	void RevertToPreviousState()
	{
		ChangeState(m_pPrevState);
	}
};