#include "character.h"

Character::Character() : name("Unnamed"), sound("undefined"), health(100), maxHealth(100), damage(10), criticalProb(20), evasionProb(10), halfEvasionProb(10) {}
Character::Character(string name, int health, int maxHealth, int damage, int criticalProb, int evasionProb, int halfEvasionProb) 
	: name(name), health(health), maxHealth(maxHealth), damage(damage), criticalProb(criticalProb), evasionProb(evasionProb), halfEvasionProb(halfEvasionProb) {}
Character::~Character() {}
string Character::getName() { return this->name; }
void Character::setName(string name) { this->name = name; }
string Character::getSound() { return this->sound; }
void Character::setSound(string sound) { this->sound = sound; }
string Character::getlastWord() { return this-> lastWord; }
void Character::setlastWord(string lastWord) { this->lastWord = lastWord; }

int Character::getHealth() { return this->health; }
int Character::getMaxHealth() { return this->maxHealth; }
void Character::setHealth(int health) { this->health = health; }
void Character::setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; }
void Character::modifyHealth(int amount) { this->health += amount; }

int Character::getDamage() { return this->damage; }
void Character::setDamage(int damage) { this->damage = damage; }
void Character::modifyDamage(int amount) { this->damage += amount; }
void Character::takeDamage(int damage) { modifyHealth(-damage); }
int Character::getWeaponDamage() { return this->weaponDamage; }
void Character::setWeaponDamage(int damage) { this->weaponDamage = damage; }
int Character::getCharacterDamage() { return this->damage + this->weaponDamage; }

void Character::showInfo()
{
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "몬스터 " << this->getName() << " 등장!" << endl;
	cout << "체력: " << this->getHealth() << ", 공격력: " << this->getDamage() << endl << endl;

}
bool Character::getIsDamageBoost() { return isDamageBoost; }
void Character::setIsDamageBoost(bool isDamageBoost) {	this->isDamageBoost = isDamageBoost;  }

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