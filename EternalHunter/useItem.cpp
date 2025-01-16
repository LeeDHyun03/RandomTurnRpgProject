#include "character.h"
#include "useItem.h"

// UseItem ������ ����
UseItem::UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn)
    : Item(name, price), healthAmount(healthAmount), damageAmount(damageAmount), isActivate(isActivate), activateTurn(activateTurn) {
}

// ü�� ���� �޼���
int UseItem::getHealthAmount() {
    return this->healthAmount;
}

void UseItem::setHealthAmount(int healthAmount) {
    this->healthAmount = healthAmount;
}

void UseItem::modifyHealthAmount(int amount) {
    this->healthAmount += amount;
}

// ������ ���� �޼���
int UseItem::getDamageAmount() {
    return this->damageAmount;
}

void UseItem::setDamageAmount(int damageAmount) {
    this->damageAmount = damageAmount;
}

void UseItem::modifyDamageAmount(int amount) {
    this->damageAmount += amount;
}

// HealthPotion �⺻ ������
HealthPotion::HealthPotion() : UseItem("Health Potion", 10, 50, 0, false, 0) {
}

void HealthPotion::itemUse(Character* character) {
    if (character->getHealth() == character->getMaxHealth()) return;
    character->modifyHealth(healthAmount);
    isUsed = true;
}

void HealthPotion::DeactivateItem(Character* character) {}

void HealthPotion::PoolItem() {
    isUsed = false;
    isActivate = false;
    currentActivateTurn = 0;
}

// DamageBoost �⺻ ������
DamageBoost::DamageBoost() : UseItem("Damage Boost", 15, 0, 10, true, 1) {
}

void DamageBoost::itemUse(Character* character) {
    if (!character->getIsDamageBoost()) {
        character->modifyDamage(damageAmount);
        character->setIsDamageBoost(true);
        isUsed = true;
    }
}

void DamageBoost::DeactivateItem(Character* character) {
    character->modifyDamage(-damageAmount);
    character->setIsDamageBoost(false);
}

void DamageBoost::PoolItem() {
    isUsed = false;
    isActivate = false;
    currentActivateTurn = 0;
}

WorldMostWeapon::WorldMostWeapon()
    : UseItem("���ְŴ��Ѽҵ�5��", 50, 0, 200, true, 1) {  // ���� ��ȣ ������ 
}

// ������ ���
void WorldMostWeapon::itemUse(Character* character) {
    if (!isUsed) {
        // ���� ���ݷ¿� damageAmount(200)�� �����ش�.
        character->modifyDamage(damageAmount);  // ���� ���ݷ¿� 200 ����
        isUsed = true;  // ��� ���·� ����
    }
}


void WorldMostWeapon::DeactivateItem(Character* character) {
    
}

void WorldMostWeapon::PoolItem() {
    
}


MiddleWeapon::MiddleWeapon()
    : UseItem("���ְŴ��Ѽҵ�10��", 100, 1, 500, true, 1) {  // ���� ��ȣ, ������ 500
}

// ������ ���
void MiddleWeapon::itemUse(Character* character) {
    if (!isUsed) {
        // ���� ���ݷ¿� damageAmount(500)�� �����ش�.
        character->modifyDamage(damageAmount);  // ���� ���ݷ¿� 500 ����
        isUsed = true;  // ��� ���·� ����
    }
}

void MiddleWeapon::DeactivateItem(Character* character) {
    
}

void MiddleWeapon::PoolItem() {

}




