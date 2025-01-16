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
	bool isUsed = false;
	bool isActivate = false;
public:    
	// 순수 가상 함수 (추상 클래스)
	virtual void itemUse(Character* character) = 0;

	// 가상 복제 함수 추가 (추상 함수)
	virtual UseItem* clone() const = 0;
	UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn);
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
	bool setIsUsed(bool isUsed) { this->isUsed = isUsed; }
	bool getIsUsed() { return isUsed; }
	bool getIsActivate() { return isActivate; }
	//activateTurn
	int getActivateTurn() { return activateTurn; }
	int getCurrentctivateTurn() { return currentActivateTurn; }
	void modifyActivateTurn(int amount) { this->currentActivateTurn += amount; }
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