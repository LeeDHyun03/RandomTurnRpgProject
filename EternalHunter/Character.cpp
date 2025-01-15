#include "character.h"

Character::Character() : name("Unnamed"), health(100), maxHealth(100), damage(10) {}
Character::Character(string name, int health, int maxHealth, int damage) : name(name), health(health), maxHealth(maxHealth), damage(damage) {}
Character::~Character() {}
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

void Character::useItem(Item* item)
{
	modifyHealth(item->getHealthAmount());
	modifyDamage(item->getDamageAmount());
	if (getHealth() > getMaxHealth())
	{
		setHealth(getMaxHealth());
	}
}

void Character::showInfo()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "���� " << this->getName() << " ����!" << endl;
	cout << "ü��: " << this->getHealth() << ", ���ݷ�: " << this->getDamage() << endl << endl;

}

void Character::firstShowInfo()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "���� " << this->getName() << " ����!" << endl;
	cout << "ü��: " << this->getHealth() << ", ���ݷ�: " << this->getDamage() << endl << endl;
}

void Character::showInfoBattle()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "���� " << this->getName() << " ����!" << endl;
	cout << "ü��: " << this->getHealth() << ", ���ݷ�: " << this->getDamage() << endl << endl;
}