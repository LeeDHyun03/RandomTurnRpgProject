#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int level, vector<Item*> itemList) //몬스터 기본 생성자
	: Character(name, level* randomInRange(20, 30), level* randomInRange(20, 30), level* randomInRange(5, 10), itemList) {}

void Monster::showInfo() //몬스터 정보
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "몬스터 " << this->getName() << " 등장!" << endl;
	cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
}

Goblin::Goblin(int level) 
	: Monster("Goblin", level, { new HealthPotion }) {}

Orc::Orc(int level) 
	: Monster("Orc", level, {}) {}

Troll::Troll(int level) 
	: Monster("Troll", level, {}) {}

Slime::Slime(int level) 
	: Monster("Slime", level, {}) {}

BossMonster::BossMonster(string name, int level, vector<Item*> itemList) //보스몬스터
	: Character(name, level* randomInRange(20, 30 * 1.5f), level* randomInRange(20, 30 * 1.5f), level* randomInRange(5, 10 * 1.5f), itemList) {}
