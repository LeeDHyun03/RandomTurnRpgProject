#pragma once
#include "Item.h"
#include "customlib.h"
#include <iostream>
#include <string>

using namespace std;

class Weapon : public Item
{
private: 
	int stack;
	int enforceProbability = 90;

public:
	Weapon();
	Weapon(string name, int price, int healthAmount, int damageAmount, int stack);

	void enforce(int amount);
	
	bool tryToEnforce(int amount);
	
	int getStack();
};