#pragma once

class MyGame : public IGame
{
public:
	MyGame(const std::string& name);

protected:
	virtual void Init();
	virtual void Shutdown();
	virtual void Update(float dt);
	virtual void Render();
	virtual bool CanRun();
private:
	std::string m_GameName;

	std::unique_ptr<Tank> m_Tank[2];
	char m_Turn;
};