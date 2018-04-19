#pragma once


class City : public GameObject
{
public:
	City(const std::string name);

	void AddChild(GameObject* obj);
	void RemoveChild(unsigned int id);

	GameObject* GetChild(unsigned int id);

	void PrintData();
private:
	std::vector<std::unique_ptr<GameObject>> m_Hummans;
};