#include "character.h"

Character::Character() : name("Unnamed"), health(100), maxHealth(100), damage(10) {}
Character::Character(string name, int health, int maxHealth, int damage, vector<Item*> itemlist) : name(name), health(health), maxHealth(maxHealth), damage(damage), itemList(itemlist) {}
Character::~Character()
{
	for (int i = 0; i < itemList.size(); i++)
	{
		delete itemList[i];
	}
}
string Character::getName() { return this->name; }
void Character::setName(string name) { this->name = name; }

int Character::getHealth() { return this->health; }
int Character::getMaxHealth() { return this->maxHealth; }
void Character::setHealth(int health) { this->health = health; }
void Character::setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; }
void Character::modifyHealth(int amount) { this->health += amount; }

int Character::getDamage() { return this->damage; }
void Character::setDamage(int damage) { this->damage = damage; }
void Character::modifyDamage(int amount) { this->damage += amount; }
void Character::takeDamage(int damage) { modifyHealth(-damage); }

vector<Item*>& Character::getInventory() { return this->itemList; }

void Character::useItem(Item* item)
{
	modifyHealth(item->getHealthAmount());
	modifyDamage(item->getDamageAmount());
}

void Character::addItemToInventory(Item* item)
{
	this->getInventory().push_back(item);
}

void Character::removeItemFromPlayerInventory(int index)
{
	this->getInventory().erase(getInventory().begin() + index);
}

void Character::showInfo()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "몬스터 " << this->getName() << " 등장!" << endl;
	cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;

}

void Character::firstShowInfo()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "몬스터 " << this->getName() << " 등장!" << endl;
	cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
}

void Character::showInfoBattle()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "몬스터 " << this->getName() << " 등장!" << endl;
	cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;
}