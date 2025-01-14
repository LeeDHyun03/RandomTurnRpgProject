#pragma once
#include "player.h"
#include "item.h"

using namespace std;
class Shop
{
private:
	string shopName;
public:
	Shop() {}
	Shop(string name, vector<Item*> itemlist) : shopName(name), itemList(itemlist) {}
	vector<Item*> itemList = {new HealthPotion, new DamageBoost };
	virtual ~Shop();
	string getShopName();

	void Shopping(Player* player);

	void ShowItemlist();

	Item* BuyItem(Player* player, int index);

	void ShowPlayerItemList(Player* player);

	void SellItem(Player* player, int index);
};

class NormalShop : public Shop
{
public:
	NormalShop(vector<Item*> itemlist) : Shop("NormalShop", itemlist) {}
	~NormalShop(){}
};

class HiddenShop : public Shop
{
public:
	HiddenShop(vector<Item*> itemlist) : Shop("HiddenShop", itemlist) {}
	~HiddenShop(){}
};