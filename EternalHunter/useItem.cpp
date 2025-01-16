#include "character.h"
#include "useItem.h"


UseItem::UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn, bool playerTarget)
	: Item(name, price), healthAmount(healthAmount), damageAmount(damageAmount), isActivate(isActivate), activateTurn(activateTurn), playerTarget(playerTarget) {
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
	if (character->getHealth() > character->getMaxHealth()) character->setHealth(character->getMaxHealth());
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


WorldMostWeapon::WorldMostWeapon()
    : UseItem("아주거대한소드5강", 50, 0, 200, true, 1, true) {  // 가격 번호 데미지 
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


MiddleWeapon::MiddleWeapon()
    : UseItem("아주거대한소드10강", 100, 1, 500, true, 1, true) {  // 가격 번호, 데미지 500
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



