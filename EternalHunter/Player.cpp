#include "Player.h"
#include<iostream>

using namespace std;

Player::Player() :Character("Player", 200, 200, 30, {}), level(1), xp(0), gold(0), inventory() {}  // 인벤토리 초기화

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

void Player::showStatus() //캐릭터 스팩
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "캐릭터 상태: " << endl;
	cout << "이름: " << this->getName() << ", 레벨: " << this->getLevel() << ", 체력: " << this->getHealth() << "/" << this->getMaxHealth()
		<< ", 공격력: " << this->getDamage() << ", 경험치: " << this->getXp() << ", 골드: " << this->getGold() << endl;
	cout << "-----------------------------------------------------------------------" << endl;
}

void Player::addItemToInventory(Item* item) {
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

Weapon* Player::getWeapon() { return myWeapon; }

void Player::applyDamage()
{
	modifyDamage(myWeapon->getDamageAmount());
}