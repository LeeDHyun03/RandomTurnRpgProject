#include "Item.h"
using namespace std;

Item::Item()
	:name("unnamed"), price(0), healthAmount(0), damageAmount(0) {}

Item::Item(string name, int price, int healthAmount, int damageAmount)
	: name(name), price(price), healthAmount(healthAmount), damageAmount(damageAmount) {}

string Item::getName()				//이름
{
	return this->name;
}

void Item::setName(string name)		//이름
{
	this->name = name;
}


int Item::getPrice()			//가격
{
	return this->price;
}


int Item::getHealthAmount()		//체력 관련
{
	 return this->healthAmount;
}

void Item::setHealthAmount(int healthAmount)
{
	this->healthAmount = healthAmount;
}

void Item::modifyHealthAmount(int amount)
{
	this->healthAmount += amount;
}								//체력 관련


int Item::getDamageAmount()	//데미지
{ 
	return this->damageAmount;
}
void Item::setDamageAmount(int damageAmount) 
{ 
	this->damageAmount = damageAmount; 
}
void Item::modifyDamageAmount(int amount) 
{ 
	this->damageAmount += amount; 
}							//데미지


HealthPotion::HealthPotion() //체력회복제 기본생성
	: Item("Health Potion", 10, 50, 0) {}

DamageBoost::DamageBoost() //도핑제 기본생성
	: Item("Damage Boost", 15, 0, 10) {}