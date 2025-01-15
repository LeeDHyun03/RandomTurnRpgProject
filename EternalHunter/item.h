#pragma once
#include <string>
using namespace std;
class Character;
class Item
{
protected:
	string name;
	int price;
public:
	Item();
	Item(string name, int price);
	//이름
	string getName();
	void setName(string name);
	//가격
	int getPrice();



};
