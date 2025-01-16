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
	int damageAmount;
public:
	Weapon();
	Weapon(string name, int price, int damageAmount, int stack);


	int getDamageAmount() { return damageAmount; }
	void setDamageAmount(int damageAmount) { this->damageAmount = damageAmount; }
	void enforce(int amount);

	void breakWeapon();
	
	bool tryToEnforce(int amount);
	
	int getStack();
};