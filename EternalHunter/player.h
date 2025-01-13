#pragma once
#include "character.h"

using namespace std;

class Player : public Character
{
private:
	int level = 1;
	int xp = 0;
	int gold = 0;

public:
	Player() : Character("Player", 200, 200, 30, {}), level(1), xp(0), gold(0) {}
	~Player(){}

	void gainXP(int amount)
	{
		xp += amount;
		if (xp >= 100)
		{
			xp -= 100;
			levelUP();
		}
	}

	void levelUP()
	{
		if (level < 10)
		{
			setmaxHealth(getMaxHealth() + level * 20);
			setHealth(getMaxHealth());
			setDamage(getDamage() + level * 5);
			level++;
		}
	}

	int getLevel() { return this->level; }
	int getXp() { return this->xp; }

	int getGold() { return this->gold; }
	void setGold(int gold) { this->gold = gold; }
	void modifyGold(int gold) { this->gold += gold; }

	void showStatus()
	{
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "ĳ���� ����: " << endl;
		cout << "�̸�: " << this->getName() << ", ����: " << this->getLevel() << ", ü��: " << this->getHealth() << "/" << this->getMaxHealth()
			<< ", ���ݷ�: " << this->getDamage() << ", ����ġ: " << this->getXp() << ", ���: " << this->getGold() << endl;
		cout << "-----------------------------------------------------------------------" << endl;
	}
};