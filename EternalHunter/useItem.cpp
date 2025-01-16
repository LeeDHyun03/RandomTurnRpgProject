#include "character.h"
#include "useItem.h"

// UseItem 생성자 정의
UseItem::UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn)
    : Item(name, price), healthAmount(healthAmount), damageAmount(damageAmount), isActivate(isActivate), activateTurn(activateTurn) {
}

// 체력 관련 메서드
int UseItem::getHealthAmount() {
    return this->healthAmount;
}

void UseItem::setHealthAmount(int healthAmount) {
    this->healthAmount = healthAmount;
}

void UseItem::modifyHealthAmount(int amount) {
    this->healthAmount += amount;
}

// 데미지 관련 메서드
int UseItem::getDamageAmount() {
    return this->damageAmount;
}

void UseItem::setDamageAmount(int damageAmount) {
    this->damageAmount = damageAmount;
}

void UseItem::modifyDamageAmount(int amount) {
    this->damageAmount += amount;
}

// HealthPotion 기본 생성자
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

// DamageBoost 기본 생성자
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
    : UseItem("아주거대한소드5강", 50, 0, 200, true, 1) {  // 가격 번호 데미지 
}

// 아이템 사용
void WorldMostWeapon::itemUse(Character* character) {
    if (!isUsed) {
        // 현재 공격력에 damageAmount(200)를 더해준다.
        character->modifyDamage(damageAmount);  // 현재 공격력에 200 증가
        isUsed = true;  // 사용 상태로 변경
    }
}


void WorldMostWeapon::DeactivateItem(Character* character) {
    
}

void WorldMostWeapon::PoolItem() {
    
}


MiddleWeapon::MiddleWeapon()
    : UseItem("아주거대한소드10강", 100, 1, 500, true, 1) {  // 가격 번호, 데미지 500
}

// 아이템 사용
void MiddleWeapon::itemUse(Character* character) {
    if (!isUsed) {
        // 현재 공격력에 damageAmount(500)를 더해준다.
        character->modifyDamage(damageAmount);  // 현재 공격력에 500 증가
        isUsed = true;  // 사용 상태로 변경
    }
}

void MiddleWeapon::DeactivateItem(Character* character) {
    
}

void MiddleWeapon::PoolItem() {

}




