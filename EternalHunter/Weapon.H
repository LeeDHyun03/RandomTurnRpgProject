#pragma once
#include "item.h"
#include "customlib.h"
#include <iostream>
using namespace std;
class Weapon : public Item
{
private:
	int stack;

public:
	Weapon() : stack(0), Item() { this->setDamageAmount(10); }
	Weapon(string name, int price, int healthAmount, int damageAmount, int stack) : stack(stack), Item(name, price, healthAmount, damageAmount) {}

	void enforce(int amount)
	{
		stack += amount;
		this->setDamageAmount(this->getDamageAmount() * 1.5f * amount);
	}

	bool tryToEnforce(int amount)
	{
		if (ProbabilityCheck(90))
		{
			enforce(amount);
			cout << "강화 성공!!! 현재 강화 수치 : " << this->stack << endl;
		}
		else
		{
			cout << "강화에 실패하여 장비가 파괴되었습니다." << endl;
			this->setName("무기였던 것");
			this->setDamageAmount(1);
			cout << "무기 이름 : " << this->getName() << "       데미지 : " << this->getDamageAmount() << endl;
		}
	}
};