#include "Weapon.h"


Weapon::Weapon() //무기 기본생성자
	:stack(0), Item()
{
	this->setDamageAmount(10);
}

Weapon::Weapon(string name, int price, int healthAmount, int damageAmount, int stack) 
	: stack(stack), Item(name, price, healthAmount, damageAmount) {} //무기 기본 정보

void Weapon::enforce(int amount) //무기 강화
{
	stack += amount; //강화 수치
	this->setDamageAmount(this->getDamageAmount() * 1.5f * amount); //성공시 증가량
}

bool Weapon::tryToEnforce(int amount) //강화 로직?
{
	if (ProbabilityCheck(enforceProbability))
	{
		enforce(amount);
		if (enforceProbability < 6) enforceProbability -= 5;
		cout << "강화 성공!! 현재 강화 수치 : " << this->stack << endl;
		return true;
	}
	else
	{
		cout << "강화에 실패하여 장비가 파괴되었습니다." << endl;
		this->setName("무기였던 것");  // 강화 실패 시 무기 이름 변경
		this->setDamageAmount(1);  // 강화 실패 시 데미지 1로 설정
		cout << "무기 이름 : " << this->getName() << "       데미지 : " << this->getDamageAmount() << endl;
		return false;
	}
}