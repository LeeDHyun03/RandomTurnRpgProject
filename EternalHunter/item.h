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
	//�̸�
	string getName();
	void setName(string name);
	//����
	int getPrice();



};
