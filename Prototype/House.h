#pragma once

// simple humman
class Humman
{
public:
	Humman(const std::string& name) :m_Name(name) {}

	const std::string& GetName() { return m_Name; }
private:
	std::string m_Name;
};

class House : public ICloneable
{
public:
	House(int maxHumman,	int houseCost,const	std::string& name);

	void AddHumman(Humman* pHumman);

	const std::string& GetHouseName();
	void SetHouseName(const std::string& name);
	void SetHouseCost(int cost);
	void RemoveChild(const std::string& name);
	void PrintData();
	virtual ICloneable* CloneObject();
private:
	std::vector<Humman*> m_Hummans;

	int MaxHumman;
	int HouseCost;
	std::string Name;
};