#pragma once
#include "item.h"
#include "customlib.h"
#include <iostream>
using namespace std;
class weapon : public Item
{
private:
	int stack;

public:
	weapon() : stack(0), Item() { this->setDamageAmount(10); }
	weapon(string name, int price, int healthAmount, int damageAmount,int stack) : stack(stack), Item(name, price, healthAmount, damageAmount) {}
		
	void enforce(int amount)
	{
		stack += amount;
		this->setDamageAmount(this->getDamageAmount() * 1.5f *amount);
	}

	bool tryToEnforce(int amount)
	{
		if (ProbabilityCheck(90))
		{
			enforce(amount);
			cout << "��ȭ ����!!! ���� ��ȭ ��ġ : " << this->stack << endl;
		}
		else
		{
			cout << "��ȭ�� �����Ͽ� ��� �ı��Ǿ����ϴ�." << endl;
			this->setName("���⿴�� ��");
			this->setDamageAmount(1);
			cout << "���� �̸� : " << this->getName() << "       ������ : " << this->getDamageAmount() << endl;
		}
	}
};