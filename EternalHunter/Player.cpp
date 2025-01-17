#include "Player.h"
#include<iostream>

using namespace std;

Player::Player() :Character("Player", 1000000, 1000000, 3, 20, 10, 10), level(1), xp(0), gold(10000) {}  // 인벤토리 초기화

Player::~Player() {}

void Player::gainXP(int amount) //경험치 획득 100넘으면 레벨업
{
	xp += amount;
	if (xp >= maxXp)
	{
		xp -= maxXp;
		levelUP();
	}
}

void Player::levelUP() //레벨업
{
	if (level < maxLevel)
	{
		setMaxHealth(getMaxHealth() + level * 20);
		setHealth(getMaxHealth());
		setDamage(getDamage() + level * 5);
		cout << "\nLevel Up!!! 성장하셨습니다!!\n";
		cout << "최대 HP: " << getMaxHealth() << "   " << "공격력: " << getDamage() << endl;
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

void Player::showInfo() //캐릭터 스팩
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "캐릭터 상태: " << endl;
	cout << "이름: " << this->getName() << ", 레벨: " << this->getLevel() << ", 체력: " << this->getHealth() << "/" << this->getMaxHealth()
		<< ", 공격력: " << this->getDamage()+this->getWeaponDamage() << ", 경험치: " << this->getXp() << ", 골드: " << this->getGold() << endl;
	cout << "-----------------------------------------------------------------------" << endl;
}

void Player::showInfoBattle()
{
	cout << "캐릭터 상태: " << endl;
	cout <<  " 체력: " << this->getHealth() << "/" << this->getMaxHealth()
		<< " 공격력: " << this->getDamage()+this->getWeaponDamage() << endl;
}

Weapon* Player::getWeapon() { return &myWeapon; }

void Player::applyDamage()
{
	setWeaponDamage(myWeapon.getDamageAmount());
}


void Player::addItemToInventory(UseItem* item) {
	inventory.addItem(item);  // 인벤토리에 아이템 추가
}

void Player::removeItemFromInventory(int index) {
	inventory.removeItem(index);  // 인벤토리에서 아이템 제거
}

void Player::showInventory() const {
	inventory.showItems();  // 인벤토리 아이템 목록 출력
}

const Inventory& Player::getInventory() const {
	return inventory;  // 읽기 전용 인벤토리 반환
}

