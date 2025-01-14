#include "Weapon.h"


Weapon::Weapon() //���� �⺻������
	:stack(0), Item()
{
	this->setDamageAmount(10);
}

Weapon::Weapon(string name, int price, int healthAmount, int damageAmount, int stack) 
	: stack(stack), Item(name, price, healthAmount, damageAmount) {} //���� �⺻ ����

void Weapon::enforce(int amount) //���� ��ȭ
{
	stack += amount; //��ȭ ��ġ
	this->setDamageAmount(this->getDamageAmount() * 1.5f * amount); //������ ������
}

bool Weapon::tryToEnforce(int amount) //��ȭ ����?
{
	if (ProbabilityCheck(enforceProbability))
	{
		enforce(amount);
		if (enforceProbability < 6) enforceProbability -= 5;
		cout << "��ȭ ����!! ���� ��ȭ ��ġ : " << this->stack << endl;
		return true;
	}
	else
	{
		cout << "��ȭ�� �����Ͽ� ��� �ı��Ǿ����ϴ�." << endl;
		this->setName("���⿴�� ��");  // ��ȭ ���� �� ���� �̸� ����
		this->setDamageAmount(1);  // ��ȭ ���� �� ������ 1�� ����
		cout << "���� �̸� : " << this->getName() << "       ������ : " << this->getDamageAmount() << endl;
		return false;
	}
}