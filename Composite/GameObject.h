#pragma once

class GameObject
{
public:
	GameObject();
	GameObject(const std::string& name);
	virtual ~GameObject()=default;
	
public:
	void SetName(const std::string& name);
	const std::string& GetName();

	unsigned int GetID();

private:
	static unsigned int s_Counter;
private:
	unsigned int m_ID;
	std::string m_Name;
};

