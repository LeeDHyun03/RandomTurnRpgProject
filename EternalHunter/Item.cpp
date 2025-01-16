#include "Item.h"
#include "character.h"
#include <iostream>
using namespace std;

Item::Item()
	:name("unnamed"), price(0) {}

Item::Item(string name, int price)
	: name(name), price(price) {}

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