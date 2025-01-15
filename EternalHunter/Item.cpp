#include "Item.h"
using namespace std;

Item::Item()
	:name("unnamed"), price(0), healthAmount(0), damageAmount(0) {}

Item::Item(string name, int price, int healthAmount, int damageAmount)
	: name(name), price(price), healthAmount(healthAmount), damageAmount(damageAmount) {}

string Item::getName()				//�̸�
{
	return this->name;
}

void Item::setName(string name)		//�̸�
{
	this->name = name;
}


int Item::getPrice()			//����
{
	return this->price;
}


int Item::getHealthAmount()		//ü�� ����
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
}								//ü�� ����


int Item::getDamageAmount()	//������
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
}							//������


HealthPotion::HealthPotion() //ü��ȸ���� �⺻����
	: Item("Health Potion", 10, 50, 0) {}

DamageBoost::DamageBoost() //������ �⺻����
	: Item("Damage Boost", 15, 0, 10) {}