#pragma once

#include <string>

using namespace std;

class Item
{
protected:
	string name;
	int price;

	int healthAmount;
	int damageAmount;
public:
	Item():name("unnamed"),price(0),healthAmount(0),damageAmount(0) {}
	Item(string name, int price, int healthAmount, int damageAmount) : name(name),price(price), healthAmount(healthAmount), damageAmount(damageAmount) {}

	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
	int getPrice() { return this->price;  }

	int getHealthAmount() { return this->healthAmount; }
	void setHealthAmount(int healthAmount) { this->healthAmount = healthAmount; }
	void modifyHealthAmount(int amount) { this->healthAmount += amount; }

	int getDamageAmount() { return this->damageAmount; }
	void setDamageAmount(int damageAmount) { this->damageAmount = damageAmount; }
	void modifyDamageAmount(int amount) { this->damageAmount += amount; }
};

class HealthPotion : public Item
{
public:
	HealthPotion() : Item("Health Potion", 10, 50, 0){}
};
class DamageBoost : public Item
{
public:
	DamageBoost() : Item("Damage Boost", 15, 0, 10){}
};