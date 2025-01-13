#include "Item.h"

// Item class definitions
Item::Item() : name("unnamed"), price(0), healthAmount(0), damageAmount(0) {}

Item::Item(string name, int price, int healthAmount, int damageAmount)
    : name(name), price(price), healthAmount(healthAmount), damageAmount(damageAmount) {
}

string Item::getName() { return this->name; }
int Item::getPrice() { return this->price; }
int Item::getHealthAmount() { return this->healthAmount; }
int Item::getDamageAmount() { return this->damageAmount; }

// HealthPotion class definitions
HealthPotion::HealthPotion() : Item("Health Potion", 10, 50, 0) {}

// DamageBoost class definitions
DamageBoost::DamageBoost() : Item("Damage Boost", 15, 0, 10) {}