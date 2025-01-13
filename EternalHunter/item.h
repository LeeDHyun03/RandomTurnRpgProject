class Item
{
protected:
	string name;
	int price;

	int healthAmount;
	int damageAmount;
public:
	Item():name("unnamed"),price(0),healthAmount(0),damageAmount(0) {}
	Item(string name, int price, int healthAmount, int damageAmount) : name(name),price(price), healthAmount(healthAmount), damageAmount(damageAmount) {}

	string getName() { return this->name; }
	int getPrice() { return this->price;  }

	int getHealthAmount() { return this->healthAmount; }
	int getDamageAmount() { return this->damageAmount; }
};

class HealthPotion : public Item
{
public:
	HealthPotion() : Item("Health Potion", 10, 50, 0){}
};
class DamageBoost : public Item
{
public:
	DamageBoost() : Item("Damage Boost", 15, 0, 10){}
};