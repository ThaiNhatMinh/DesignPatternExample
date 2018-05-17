#pragma once

struct Telegram;
class GameObject
{
private:
	int m_ID;

	static int m_iNextID;

public:
	GameObject(int id) :m_ID(id) {}

	virtual ~GameObject() = default;

	virtual bool HandleMessage(const Telegram& telegram) = 0;
	int GetID() { return m_ID; }
};