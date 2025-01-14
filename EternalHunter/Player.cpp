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

void Player::levelUP() //setmaxHealth->setMaxHealth로 변경
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
	cout << "캐릭터 상태: " << endl;
	cout << "이름: " << this->getName() << ", 레벨: " << this->getLevel() << ", 체력: " << this->getHealth() << "/" << this->getMaxHealth()
		<< ", 공격력: " << this->getDamage() << ", 경험치: " << this->getXp() << ", 골드: " << this->getGold() << endl;
	cout << "-----------------------------------------------------------------------" << endl;
}