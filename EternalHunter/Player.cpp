#include "Player.h"
#include<iostream>

using namespace std;

Player::Player() :Character("Player", 200, 200, 30, {}), level(1), xp(0), gold(0), inventory() {}  // �κ��丮 �ʱ�ȭ

Player::~Player() {}

void Player::gainXP(int amount) //����ġ ȹ�� 100������ ������
{
	xp += amount;
	if (xp >= maxXp)
	{
		xp -= maxXp;
		levelUP();
	}
}

void Player::levelUP() //������
{
	if (level < maxLevel)
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

void Player::showInfo() //ĳ���� ����
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "ĳ���� ����: " << endl;
	cout << "�̸�: " << this->getName() << ", ����: " << this->getLevel() << ", ü��: " << this->getHealth() << "/" << this->getMaxHealth()
		<< ", ���ݷ�: " << this->getDamage() << ", ����ġ: " << this->getXp() << ", ���: " << this->getGold() << endl;
	cout << "-----------------------------------------------------------------------" << endl;
}

void Player::showInfoBattle()
{
	cout << "ĳ���� ����: " << endl;
	cout <<  " ü��: " << this->getHealth() << "/" << this->getMaxHealth()
		<< " ���ݷ�: " << this->getDamage() << endl;
}

Weapon* Player::getWeapon() { return myWeapon; }

void Player::applyDamage()
{
	modifyDamage(myWeapon->getDamageAmount());
}