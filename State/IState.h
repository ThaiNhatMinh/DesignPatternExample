#pragma once

template <class Actor>
class State
{
public:
	virtual void Enter(Actor*) = 0;
	virtual void Execute(Actor*) = 0;
	virtual void Exit(Actor*) = 0;

	virtual ~State() = default;
};