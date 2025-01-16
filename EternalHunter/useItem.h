#pragma once
#include "item.h"
//UseItem 파일 추가
class Character;
class UseItem : public Item
{
protected:
	int healthAmount;
	int damageAmount;
	int currentActivateTurn = 0;
	int activateTurn;
	bool isActivate = false;
	bool playerTarget;
	bool isUsed = false;
public:
	// 순수 가상 함수 (추상 클래스)
	virtual void itemUse(Character* character) = 0;

	// 가상 복제 함수 추가 (추상 함수)
	virtual UseItem* clone() const = 0;
	UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn, bool playerTarget);
	virtual void DeactivateItem(Character* character) = 0;

	//체력
	int getHealthAmount();
	void setHealthAmount(int healthAmount);
	void modifyHealthAmount(int amount);
	//데미지
	int getDamageAmount();
	void setDamageAmount(int damageAmount);
	void modifyDamageAmount(int amount);
	//Bool 체크
	bool getIsActivate() { return isActivate; }
	bool setIsUsed(bool isUsed) { this->isUsed = isUsed; }
	bool getIsUsed() { return isUsed; }
	//activateTurn
	int getActivateTurn() { return activateTurn; }
	void modifyAcitvateTurn(int amount) { this->activateTurn += amount; }
	int getCurrentctivateTurn() { return currentActivateTurn; }
	void modifyCurrentActivateTurn(int amount) { this->currentActivateTurn += amount; }
	void PoolItem();

	bool getPlayerTarget() { return playerTarget; }
};

class HealthPotion : public UseItem
{
public:
	virtual UseItem* clone() const override {
	return new HealthPotion(*this);  // 현재 객체의 복사본 반환
}
	HealthPotion();
	virtual void itemUse(Character* character);
	virtual void DeactivateItem(Character* character);
};
class DamageBoost : public UseItem
{
public:
	virtual UseItem* clone() const override {
	return new DamageBoost(*this);  // 현재 객체의 복사본 반환
}
	DamageBoost();
	virtual void itemUse(Character* character);
	virtual void DeactivateItem(Character* character);
};
class StunGun : public UseItem
{
public:
	virtual UseItem* clone() const override {
		return new StunGun(*this);  // 현재 객체의 복사본 반환
	}
	StunGun();
	virtual void itemUse(Character* character);
	virtual void DeactivateItem(Character* character);
};



class WorldMostWeapon : public UseItem
{
public:
	virtual UseItem* clone() const override {
		return new WorldMostWeapon(*this);  // 현재 객체의 복사본 반환
	}

	WorldMostWeapon();  // 생성자 선언

	virtual void itemUse(Character* character) ;  // 아이템 사용
	virtual void DeactivateItem(Character* character) ;  // 아이템 비활성화
};

class MiddleWeapon : public UseItem
{
public:
	virtual UseItem* clone() const override {
		return new MiddleWeapon(*this);  // 현재 객체의 복사본 반환
	}

	MiddleWeapon();  // 생성자 선언

	virtual void itemUse(Character* character) ;  // 아이템 사용
	virtual void DeactivateItem(Character* character) ;  // 아이템 비활성화
};