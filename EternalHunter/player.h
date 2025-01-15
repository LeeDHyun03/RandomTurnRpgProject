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

	void showInfo() override;
	void showInfoBattle() override;

	Weapon* getWeapon();

	void applyDamage();

	// 인벤토리 관련 메소드
	void addItemToInventory(Item* item);
	void removeItemFromInventory(int index);
	void showInventory() const;

	const Inventory& getInventory() const;

};