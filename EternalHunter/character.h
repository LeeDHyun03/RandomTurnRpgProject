#pragma once
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "item.h"
using namespace std;

/// <summary>
/// Random Number in range(Start, End)
/// </summary>
/// <param name="start">: Start Number</param>
/// <param name="end">: End numberis included</param>
/// <returns></returns>
int randomInRange(int start, int end)
{
	srand(time(NULL));
	return rand() % (end - start + 1) + start;
}
float randomInRange(int start, float end)
{
	srand(time(NULL));
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}
float randomInRange(float start, int end)
{
	srand(time(NULL));
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}
float randomInRange(float start, float end)
{
	srand(time(NULL));
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}


class Character
{
private:
	string name;
	int health;
	int maxHealth;
	int damage;
	vector<Item*> itemList = {};
public:
	Character() : name("Unnamed"), health(100), maxHealth(100), damage(10) {}
	Character(string name, int health, int maxHealth, int damage, vector<Item*> itemlist) : name(name), health(health), maxHealth(maxHealth), damage(damage),itemList(itemlist) {}
	virtual ~Character()
	{
		for (int i = 0; i < itemList.size(); i++)
		{
			delete itemList[i];
		}
	}
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }

	int getHealth() { return this->health; }
	int getMaxHealth() { return this->maxHealth; }
	void setHealth(int health) { this->health = health; }
	void setmaxHealth(int maxHealth) { this->maxHealth = maxHealth; }
	void modifyHealth(int amount) { this->health += amount; }

	int getDamage() { return this->damage; }
	void setDamage(int damage) { this->damage = damage; }
	void modifyDamage(int amount) { this->damage += amount; }
	void takeDamage(int damage) { modifyHealth(-damage); }

	vector<Item*> getInventory(){return this->itemList;}

	void useItem(Item* item)
	{
		modifyHealth(item->getHealthAmount());
		modifyDamage(item->getDamageAmount());
	}

	void addItemToInventory(Item* item)
	{
		this->getInventory().push_back(item);
	}

	void removeItemFromPlayerInventory(int index)
	{
		this->getInventory().erase(getInventory().begin() + index);
	}
};
