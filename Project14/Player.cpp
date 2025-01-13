#include "Player.h"
#include <iostream>

Player::Player()
    : Character("Player", 200, 200, 30, {}), level(1), xp(0), gold(0) {
}

Player::~Player() {}

void Player::gainXP(int amount)
{
    xp += amount;
    if (xp >= 100)
    {
        xp -= 100;
        levelUP();
    }
}

void Player::levelUP()
{
    if (level < 10)
    {
        setmaxHealth(getMaxHealth() + level * 20);
        setHealth(getMaxHealth());
        setDamage(getDamage() + level * 5);
        level++;
    }
}

int Player::getGold() const
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

void Player::addItemToPlayerInventory(Item* item)
{
    this->getInventory().push_back(item);
}

void Player::removeItemFromPlayerInventory(int index)
{
    this->getInventory().erase(getInventory().begin() + index);
}