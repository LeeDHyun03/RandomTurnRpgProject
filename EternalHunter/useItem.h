#pragma once
#include "item.h"
//UseItem ���� �߰�
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
	// ���� ���� �Լ� (�߻� Ŭ����)
	virtual void itemUse(Character* character) = 0;

	// ���� ���� �Լ� �߰� (�߻� �Լ�)
	virtual UseItem* clone() const = 0;
	UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn);
	virtual void DeactivateItem(Character* character) = 0;

	//ü��
	int getHealthAmount();
	void setHealthAmount(int healthAmount);
	void modifyHealthAmount(int amount);
	//������
	int getDamageAmount();
	void setDamageAmount(int damageAmount);
	void modifyDamageAmount(int amount);
	//Bool üũ
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
	return new HealthPotion(*this);  // ���� ��ü�� ���纻 ��ȯ
}
	HealthPotion();
	virtual void itemUse(Character* character);
	virtual void DeactivateItem(Character* character);
};
class DamageBoost : public UseItem
{
public:
	virtual UseItem* clone() const override {
	return new DamageBoost(*this);  // ���� ��ü�� ���纻 ��ȯ
}
	DamageBoost();
	virtual void itemUse(Character* character);
	virtual void DeactivateItem(Character* character);
};