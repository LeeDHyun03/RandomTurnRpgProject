#include "Character.h"
#include "Item.h"
using namespace std;

class Monster : public Character
{
public:
	Monster(string name, int level, vector<Item*> itemList);

	void showInfo();
};

class Goblin : public Monster
{
public:
	Goblin(int level);
};

class Orc : public Monster
{
public:
	Orc(int level);
};

class Troll : public Monster
{
public:
	Troll(int level);
};

class Slime : public Monster
{
public:
	Slime(int level);
};

class BossMonster : public Character
{
public:
	BossMonster(string name, int level, vector<Item*> itemList);
};