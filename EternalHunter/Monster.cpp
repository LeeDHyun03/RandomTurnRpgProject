#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int level, int criticalProb, int evasionProb, int halfEvasionProb) //몬스터 기본 생성자
	: Character(name, level* randomInRange(20, 30), level* randomInRange(20, 30), level* randomInRange(5, 10), criticalProb, evasionProb, halfEvasionProb) { }

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
	: Monster("Goblin", level, 10, 60, 40)
{
	setSound("Hehehe!!");
	setlastWord("You'll regret this, big guy!");
}

Orc::Orc(int level) 
	: Monster("Orc", level, 60, 10, 0)
{
	setSound("Grrrrrrrr!!");
	setlastWord("I' ll... be back!");
}

Troll::Troll(int level) 
	: Monster("Troll", level, 60, 20, 10)
{
	setSound("Raaaaagh!!!");
	setlastWord("Trolls never die...!");
}

Slime::Slime(int level) 
	: Monster("Slime", level, 0, 40, 100)
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

