#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int level) //몬스터 기본 생성자
	: Character(name, level* randomInRange(20, 30), level* randomInRange(20, 30), level* randomInRange(5, 10)) {}

void Monster::firstShowInfo() //몬스터 등장 정보
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << this->getSound() << endl;
	cout << "몬스터 " << this->getName() << " 등장!" << endl;
	cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
}

void Monster::showInfo() //몬스터 정보
{
	cout << "\n";
	cout << "몬스터: " << this->getName() << endl;
	cout << "남은 체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
}

Goblin::Goblin(int level)
	: Monster("Goblin", level)
{
	setSound("Hehehe!!");
	setlastWord("You'll regret this, big guy!");
}

Orc::Orc(int level) 
	: Monster("Orc", level)
{
	setSound("Grrrrrrrr!!");
	setlastWord("I' ll... be back!");
}

Troll::Troll(int level) 
	: Monster("Troll", level)
{
	setSound("Raaaaagh!!!");
	setlastWord("Trolls never die...!");
}

Slime::Slime(int level) 
	: Monster("Slime", level)
{
	setSound("Blub blub....");
	setlastWord("Glorp... glorp...");
}

Dragon::Dragon(int level)
	: Monster("Dragon", level){}

//void Dragon::firstShowInfo()
//{
//	cout << "-----------------------------------------------------------------------" << endl;
//	cout << "강력한 몬스터 " << this->getName() << " 등장!" << endl;
//	cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
//}
//
//void Dragon::showInfo()
//{
//	cout << "\n";
//	cout << "몬스터: " << this->getName() << endl;
//	cout << "남은 체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
//
//}

