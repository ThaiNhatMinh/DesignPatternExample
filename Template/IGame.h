#pragma once


class IGame
{
public:
	virtual ~IGame() = default;

	void Run();

protected:
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual bool CanRun() = 0;
};