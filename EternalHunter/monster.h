#include "character.h"
using namespace std;

class Monster : public Character
{
public:
	Monster(string name, int level, vector<Item*> itemList) : Character(name, level* randomInRange(20, 30), level* randomInRange(20, 30), level* randomInRange(5, 10), itemList) {}

	void showInfo() {

		cout << "-----------------------------------------------------------------------" << endl;
		cout << "몬스터 " << this->getName() << " 등장!" << endl;
		cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
	}
};

class Goblin : public Monster
{
public:
	Goblin(int level) : Monster("Goblin", level, {new HealthPotion}) {}
};

class Orc : public Monster
{
public:
	Orc(int level) : Monster("Orc", level, {}) {}
};

class Troll : public Monster
{
public:
	Troll(int level) : Monster("Troll", level, {}) {}
};

class Slime : public Monster
{
public:
	Slime(int level) : Monster("Slime", level, {}) {}
};

class BossMonster : public Character
{
public:
	BossMonster(string name, int level, vector<Item*> itemList) : Character(name, level* randomInRange(20, 30* 1.5f), level* randomInRange(20, 30* 1.5f), level* randomInRange(5, 10* 1.5f), itemList) {}
};