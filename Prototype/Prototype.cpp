// Prototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Type of clone is defined in ICloneable.h
// 

int main()
{
	auto father = std::make_unique<Humman>("Pa Pa");
	auto mother = std::make_unique<Humman>("Ma Ma");
	auto sister = std::make_unique<Humman>("XiXi");
	auto sister2 = std::make_unique<Humman>("ShaoXi");
	House myHouse(7, 100000, "Home");
	myHouse.AddHumman(father.get());
	myHouse.AddHumman(mother.get());
	myHouse.AddHumman(sister.get());
	myHouse.AddHumman(sister2.get());

	myHouse.PrintData();

	std::cout << "In Parallel Universes...\n";
	House* aCopy = myHouse.Clone<House>();
	aCopy->RemoveChild("Pa Pa");
	aCopy->SetHouseCost(10000);
	aCopy->PrintData();

	getc(stdin);

	delete aCopy;
    return 0;
}

