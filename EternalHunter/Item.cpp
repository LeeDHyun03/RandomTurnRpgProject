#include "Item.h"
#include "character.h"
#include <iostream>
using namespace std;

Item::Item()
	:name("unnamed"), price(0) {}

Item::Item(string name, int price)
	: name(name), price(price) {}

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