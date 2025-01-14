#pragma once
#include "character.h"

using namespace std;

class Player : public Character
{
private:
	int level;
	int xp;
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