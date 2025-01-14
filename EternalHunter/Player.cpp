#include "Player.h"
#include<iostream>

using namespace std;

Player::Player():Character("Player",200,200,30,{}),level(1),xp(0),gold(0){}

Player::~Player(){}

void Player::gainXP(int amount)
{
	xp += amount;
	if (xp >= 100)
	{
		xp -= 100;
		levelUP();
	}
}

void Player::levelUP() //setmaxHealth->setMaxHealth�� ����
{
	if (level < 10)
	{
		setMaxHealth(getMaxHealth() + level * 20);
		setHealth(getMaxHealth());
		setDamage(getDamage() + level * 5);
		level++;
	}
}

int Player::getLevel()
{
	return this->level;
}

int Player::getXp()
{
	return this->xp;
}

int Player::getGold()
{
	return this->gold;
}

void Player::setGold(int gold)
{
	this->gold = gold;
}

void Player::modifyGold(int gold)
{
	this->gold += gold;
}

void Player::showStatus()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "ĳ���� ����: " << endl;
	cout << "�̸�: " << this->getName() << ", ����: " << this->getLevel() << ", ü��: " << this->getHealth() << "/" << this->getMaxHealth()
		<< ", ���ݷ�: " << this->getDamage() << ", ����ġ: " << this->getXp() << ", ���: " << this->getGold() << endl;
	cout << "-----------------------------------------------------------------------" << endl;
}