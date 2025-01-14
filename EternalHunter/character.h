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
int randomInRange(int start, int end);
float randomInRange(int start, float end);
float randomInRange(float start, int end);
float randomInRange(float start, float end);


class Character
{
private:
	string name;
	int health;
	int maxHealth;
	int damage;
	vector<Item*> itemList = {};
public:
	Character();
	Character(string name, int health, int maxHealth, int damage, vector<Item*> itemlist);
	virtual ~Character();
	string getName();
	void setName(string name);

	int getHealth();
	int getMaxHealth();
	void setHealth(int health);
	void setmaxHealth(int maxHealth);
	void modifyHealth(int amount);

	int getDamage();
	void setDamage(int damage);
	void modifyDamage(int amount);
	void takeDamage(int damage);

	vector<Item*> getInventory();

	void useItem(Item* item);

	void addItemToInventory(Item* item);

	void removeItemFromPlayerInventory(int index);
};