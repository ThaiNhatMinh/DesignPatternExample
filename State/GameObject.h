#pragma once


class GameObject
{
private:
	int m_ID;

	static int m_iNextID;

public:
	GameObject(int id) :m_ID(id) {}

	virtual ~GameObject() = default;

	int GetID() { return m_ID; }
};