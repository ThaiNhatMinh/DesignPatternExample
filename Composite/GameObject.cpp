#include "stdafx.h"

unsigned int GameObject::s_Counter = 0;
GameObject::GameObject():m_Name("Unknow")
{
	s_Counter++;
	m_ID = s_Counter;
}

GameObject::GameObject(const std::string& name) :m_Name(name)
{
	s_Counter++;
	m_ID = s_Counter;
}

void GameObject::SetName(const std::string & name)
{
	m_Name = name;
}

const std::string & GameObject::GetName()
{
	return m_Name;
}

unsigned int GameObject::GetID()
{
	return m_ID;
}
