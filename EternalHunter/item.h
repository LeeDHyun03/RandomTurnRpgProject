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
	//이름
	string getName();
	void setName(string name);
	//가격
	int getPrice();
	//체력
	int getHealthAmount();
	void setHealthAmount(int healthAmount);
	void modifyHealthAmount(int amount);
	//데미지
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