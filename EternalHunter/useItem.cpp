#include "character.h"
#include "useItem.h"


UseItem::UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn, bool playerTarget)
	: Item(name, price), healthAmount(healthAmount), damageAmount(damageAmount), isActivate(isActivate), activateTurn(activateTurn), playerTarget(playerTarget) {
}

int UseItem::getHealthAmount()		//체력 관련
{
	return this->healthAmount;
}

void UseItem::setHealthAmount(int healthAmount)
{
	this->healthAmount = healthAmount;
}

void UseItem::modifyHealthAmount(int amount)
{
	this->healthAmount += amount;
}								//체력 관련


int UseItem::getDamageAmount()	//데미지
{
	return this->damageAmount;
}
void UseItem::setDamageAmount(int damageAmount)
{
	this->damageAmount = damageAmount;
}
void UseItem::modifyDamageAmount(int amount)
{
	this->damageAmount += amount;
}							//데미지
void UseItem::PoolItem()
{
	currentActivateTurn = 0;
	activateTurn = 1;
	isUsed = false;
}
HealthPotion::HealthPotion() //체력회복제 기본생성
	: UseItem("Health Potion", 10, 50, 0, false, 0, true) {
}

DamageBoost::DamageBoost() //도핑제 기본생성
	: UseItem("Damage Boost", 5, 0, 10, true, 1, true) {
}
StunGun::StunGun()
	: UseItem("StunGun", 5, 0, 0, true, 1, false) {
}

void HealthPotion::itemUse(Character* character)
{
	if (character->getHealth() == character->getMaxHealth()) return;
	character->modifyHealth(healthAmount);
}
void HealthPotion::DeactivateItem(Character* character) {}

void DamageBoost::itemUse(Character* character)
{
	if (isUsed) return;
	{
		character->modifyDamage(damageAmount);
		isUsed = true;
	}
}
void DamageBoost::DeactivateItem(Character* character)
{
	character->modifyDamage(-damageAmount);
}

void StunGun::itemUse(Character* character)
{
	if (isUsed) return;
	
	character->setIsStun(true);
	isUsed = true;
}

void StunGun::DeactivateItem(Character* character)
{
	character->setIsStun(false);
}


