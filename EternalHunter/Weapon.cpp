#include "Weapon.h"


Weapon::Weapon() //무기 기본생성자
	:stack(0), Item()
{
	this->setDamageAmount(10);
}

Weapon::Weapon(string name, int price, int damageAmount, int stack) 
	: stack(stack), damageAmount(damageAmount), Item(name, price) {} //무기 기본 정보

void Weapon::enforce(int amount) //무기 강화
{
	stack += amount; //강화 수치
	this->setDamageAmount(this->getDamageAmount() * 1.5f * amount); //성공시 증가량
}

bool Weapon::tryToEnforce(int amount) //강화 로직?
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

