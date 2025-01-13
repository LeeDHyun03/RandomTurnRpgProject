#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
protected:
    string name;
    int price;
    int healthAmount;
    int damageAmount;

public:
    Item();
    Item(string name, int price, int healthAmount, int damageAmount);

    string getName();
    int getPrice();
    int getHealthAmount();
    int getDamageAmount();
};

class HealthPotion : public Item
{
public:
    HealthPotion();
};

class DamageBoost : public Item
{
public:
    DamageBoost();
};

#endif 