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
	bool isActivate = false;
	bool playerTarget;
	bool isUsed = false;
public:
	// ���� ���� �Լ� (�߻� Ŭ����)
	virtual void itemUse(Character* character) = 0;

	// ���� ���� �Լ� �߰� (�߻� �Լ�)
	virtual UseItem* clone() const = 0;
	UseItem(string name, int price, int healthAmount, int damageAmount, bool isActivate, int activateTurn, bool playerTarget);
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
class StunGun : public UseItem
{
public:
	virtual UseItem* clone() const override {
		return new StunGun(*this);  // ���� ��ü�� ���纻 ��ȯ
	}
	StunGun();
	virtual void itemUse(Character* character);
	virtual void DeactivateItem(Character* character);
};



class WorldMostWeapon : public UseItem
{
public:
	virtual UseItem* clone() const override {
		return new WorldMostWeapon(*this);  // ���� ��ü�� ���纻 ��ȯ
	}

	WorldMostWeapon();  // ������ ����

	virtual void itemUse(Character* character) ;  // ������ ���
	virtual void DeactivateItem(Character* character) ;  // ������ ��Ȱ��ȭ
};

class MiddleWeapon : public UseItem
{
public:
	virtual UseItem* clone() const override {
		return new MiddleWeapon(*this);  // ���� ��ü�� ���纻 ��ȯ
	}

	MiddleWeapon();  // ������ ����

	virtual void itemUse(Character* character) ;  // ������ ���
	virtual void DeactivateItem(Character* character) ;  // ������ ��Ȱ��ȭ
};