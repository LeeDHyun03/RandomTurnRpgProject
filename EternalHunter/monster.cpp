#include<iostream>
#include<vector>
#include "Monster.h"
#include "Item.h"

using namespace std;

Monster::Monster(string name, int level, vector<Item*> itemList)
	: Character(name, level* randomInRange(20, 30), level* randomInRange(20, 30), level* randomInRange(5, 10), itemList) {
}

Goblin::Goblin(int level)
	:Monster("Goblin", level, { new HealthPotion }) {
}

Orc::Orc(int level)
	:Monster("Ork", level, {}) {
}

Troll::Troll(int level)
	:Monster("Troll", level, {}) {
}

Slime::Slime(int level)
	:Monster("Slime", level, {}) {
}

BossMonster::BossMonster(string name, int level, vector<Item*> itemList)
	:Character(name, level* randomInRange(20, 30 * 1.5f), level* randomInRange(20, 30 * 1.5f), level* randomInRange(5, 10 * 1.5f), itemList) {
}