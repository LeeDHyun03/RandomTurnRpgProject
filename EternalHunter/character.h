#pragma once
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "item.h"
#include "customlib.h"
using namespace std;


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
	void setMaxHealth(int maxHealth);
	void modifyHealth(int amount);

	int getDamage();
	void setDamage(int damage);
	void modifyDamage(int amount);
	void takeDamage(int damage);


	vector<Item*>& getInventory();

	void useItem(Item* item);

	void addItemToInventory(Item* item);

	void removeItemFromPlayerInventory(int index);

	virtual void firstShowInfo();
	virtual void showInfo();
	virtual void showInfoBattle();

};
