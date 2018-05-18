#include "stdafx.h"
#include "Miner.h"

void Miner::Update()
{
	m_iThirst += 1;
	m_StateMachine.Update();

}

void Miner::AddToGoldCarried(const int val)
{
	m_iGoldCarried += val;
	if (m_iGoldCarried < 0) m_iGoldCarried = 0;
}

bool Miner::Fatigued() const
{
	return m_iFatigue>TirednessThreshold;
}

void Miner::AddToWealth(const int val)
{
	m_iMoneyInBank += val;
	if (m_iMoneyInBank < 0) m_iMoneyInBank = 0;
}

bool Miner::Thirsty() const
{
	return m_iThirst>= ThirstLevel;
}
