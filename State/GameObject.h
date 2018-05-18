#pragma once
#include <string>
struct Telegram;
class GameObject
{
private:
	int m_ID;
	std::string m_Name;
	static int m_iNextID;

public:
	GameObject(const std::string name) :m_ID(m_iNextID++),m_Name(name) {}

	virtual ~GameObject() = default;

	virtual bool HandleMessage(const Telegram& telegram) = 0;
	int GetID() { return m_ID; }

	const std::string& GetName() { return m_Name; }
};

