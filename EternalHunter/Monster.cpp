#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int level, int criticalProb, int evasionProb, int halfEvasionProb) //���� �⺻ ������
	: Character(name, level* randomInRange(20, 30), level* randomInRange(20, 30), level* randomInRange(5, 10), criticalProb, evasionProb, halfEvasionProb) { }

void Monster::firstShowInfo() //���� ���� ����
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << this->getSound() << endl;
	cout << "���� " << this->getName() << " ����!" << endl;
	cout << "ü��: " << this->getHealth() << ", ���ݷ�: " << this->getDamage() << endl << endl;
}

void Monster::showInfo() //���� ����
{
	cout << "\n";
	cout << "����: " << this->getName() << endl;
	cout << "���� ü��: " << this->getHealth() << ", ���ݷ�: " << this->getDamage() << endl << endl;
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
//	cout << "������ ���� " << this->getName() << " ����!" << endl;
//	cout << "ü��: " << this->getHealth() << ", ���ݷ�: " << this->getDamage() << endl << endl;
//}
//
//void Dragon::showInfo()
//{
//	cout << "\n";
//	cout << "����: " << this->getName() << endl;
//	cout << "���� ü��: " << this->getHealth() << ", ���ݷ�: " << this->getDamage() << endl << endl;
//
//}

