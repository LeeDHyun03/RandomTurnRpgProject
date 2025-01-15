#pragma once
#include "Character.h"
#include "Weapon.H"
#include "item.h"
#include "Inventory.h"

using namespace std;

class Player : public Character
{
private:
	const int maxLevel = 10;
	int level;
	int xp;
	const int maxXp = 100;
	int gold;
	Inventory inventory;
	Weapon* myWeapon = new Weapon();
public:
	Player();

	~Player();

	void gainXP(int amount);
	void levelUP();

	int getLevel();
	int getXp();

	int getGold();
	void setGold(int gold);
	void modifyGold(int gold);

	void showStatus();

	Weapon* getWeapon();

	void applyDamage();


};