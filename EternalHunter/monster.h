#include "Character.h"
#include "Item.h"
using namespace std;

class Monster : public Character
{
public:
	Monster(string name, int level, int criticalProb, int evasionProb, int halfEvasionProb);
	void firstShowInfo() override;
	void showInfo() override;
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

class Dragon : public Monster
{
public:
	Dragon(int level);
};