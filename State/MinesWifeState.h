#pragma once
#include "IState.h"
#include "Singleton.h"
class MinersWife;

class WifesGlobalState : public State<MinersWife>, public Singleton<WifesGlobalState>
{
private:



public:

	WifesGlobalState() {}
	

	virtual void Enter(MinersWife* wife) override{}

	virtual void Execute(MinersWife* wife)override;

	virtual void Exit(MinersWife* wife)override {}
	virtual bool OnMessage(MinersWife*, const Telegram& msg)override;
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class DoHouseWork : public State<MinersWife>, public Singleton<DoHouseWork>
{

private:

public:



	DoHouseWork() {}

	virtual void Enter(MinersWife* wife)override;

	virtual void Execute(MinersWife* wife)override;

	virtual void Exit(MinersWife* wife)override;
	virtual bool OnMessage(MinersWife*, const Telegram& msg)override {return 0;}

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class VisitBathroom : public State<MinersWife>, public Singleton<VisitBathroom>
{
private:



public:

	VisitBathroom() {}
	virtual void Enter(MinersWife* wife)override;

	virtual void Execute(MinersWife* wife)override;

	virtual void Exit(MinersWife* wife)override;
	virtual bool OnMessage(MinersWife*, const Telegram& msg)override {return 0;}

};

class CookStew : public State<MinersWife>, public Singleton<CookStew>
{
public:
	CookStew() = default;
	virtual void Enter(MinersWife* wife)override;

	virtual void Execute(MinersWife* wife)override;

	virtual void Exit(MinersWife* wife)override;
	bool OnMessage(MinersWife* wife, const Telegram& msg)override;
};
