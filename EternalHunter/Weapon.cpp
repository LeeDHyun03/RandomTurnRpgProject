#include "Weapon.h"
#include "math.h"

Weapon::Weapon() //���� �⺻������
	:stack(0), Item()
{
	this->setDamageAmount(10);
}

Weapon::Weapon(string name, int price, int damageAmount, int stack) 
	: stack(stack), damageAmount(damageAmount), Item(name, price) {} //���� �⺻ ����

void Weapon::enforce(int amount) //���� ��ȭ
{
	stack += amount; //��ȭ ��ġ
	this->setDamageAmount(this->getDamageAmount() * 1.5f * amount); //������ ������
}

void Weapon::breakWeapon()
{
	this->setDamageAmount(ceil(this->getDamageAmount() / pow(1.5f, getStack())));
}

bool Weapon::tryToEnforce(int amount) //��ȭ ����?
{
	if (ProbabilityCheck(enforceProbability))
	{

		return true;
	}
	else
	{

		return false;
	}
}
int Weapon::getStack() { return stack; }

