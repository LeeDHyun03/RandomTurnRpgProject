#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int level) //���� �⺻ ������
	: Character(name, level* randomInRange(20, 30), level* randomInRange(20, 30), level* randomInRange(5, 10)) {}

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

