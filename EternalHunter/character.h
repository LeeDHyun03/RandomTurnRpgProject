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
	string sound;
	string lastWord;
	int health;
	int maxHealth;
	int damage;
	int weaponDamage = 0;
	bool isDamageBoost = false;
	int criticalProb;
	int evasionProb;
	int halfEvasionProb;

public:
	Character();
	Character(string name, int health, int maxHealth, int damage, int criticalProb, int evasionProb, int halfEvasionProb);
	virtual ~Character();
	string getName();
	void setName(string name);

	string getSound();
	void setSound(string sound);
	string getlastWord();
	void setlastWord(string lastWord);

	int getHealth();
	int getMaxHealth();
	void setHealth(int health);
	void setMaxHealth(int maxHealth);
	void modifyHealth(int amount);

	int getDamage();
	void setDamage(int damage);
	void modifyDamage(int amount);
	void takeDamage(int damage);
	int getWeaponDamage();
	void setWeaponDamage(int damage);

	int getCharacterDamage();

	
	bool getIsDamageBoost();
	void setIsDamageBoost(bool isDamageBoost);

	virtual void firstShowInfo();
	virtual void showInfo();
	virtual void showInfoBattle();

};
