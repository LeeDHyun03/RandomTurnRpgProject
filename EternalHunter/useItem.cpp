#include "character.h"
#include "useItem.h"


UseItem::UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn)
	: Item(name, price), healthAmount(healthAmount), damageAmount(damageAmount), isActivate(isActivate), activateTurn(activateTurn) {
}

int UseItem::getHealthAmount()		//ü�� ����
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
}								//ü�� ����


int UseItem::getDamageAmount()	//������
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
}							//������

HealthPotion::HealthPotion() //ü��ȸ���� �⺻����
	: UseItem("Health Potion", 10, 50, 0, false, 0) {
}

DamageBoost::DamageBoost() //������ �⺻����
	: UseItem("Damage Boost", 15, 0, 10, true, 1) {
}

void HealthPotion::itemUse(Character* character)
{
	if (character->getHealth() == character->getMaxHealth()) return;
	character->modifyHealth(healthAmount);
	isUsed = true;
}
void HealthPotion::DeactivateItem(Character* character) {}
void DamageBoost::itemUse(Character* character)
{
	if (!character->getIsDamageBoost())
	{
		character->modifyDamage(damageAmount);
		character->setIsDamageBoost(true);
		isUsed = true;
	}
}
void DamageBoost::DeactivateItem(Character* character)
{
	cout << "asdf";
	character->modifyDamage(-damageAmount);
	character->setIsDamageBoost(false);
}