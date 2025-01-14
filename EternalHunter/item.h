#pragma once
#include <string>
using namespace std;
class Item
{
protected:
	string name;
	int price;
	int healthAmount;
	int damageAmount;
public:
	Item();
	Item(string name, int price, int healthAmount, int damageAmount);
	//�̸�
	string getName();
	void setName(string name);
	//����
	int getPrice();
	//ü��
	int getHealthAmount();
	void setHealthAmount(int healthAmount);
	void modifyHealthAmount(int amount);
	//������
	int getDamageAmount();
	void setDamageAmount(int damageAmount);
	void modifyDamageAmount(int amount);
};
class HealthPotion : public Item
{
public:
	HealthPotion();
};
class DamageBoost : public Item
{
public:
	DamageBoost();
};