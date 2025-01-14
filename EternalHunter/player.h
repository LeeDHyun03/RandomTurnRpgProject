#pragma once
#include "Character.h"
using namespace std;

class Player : public Character
{
private:
	const int maxLevel = 10;
	int level;
	int xp;
	const int maxXp = 100;
	int gold;
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
};