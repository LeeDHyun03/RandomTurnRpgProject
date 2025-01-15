#pragma once
#include "player.h"
#include "item.h"
#include "useItem.h"
#include "customlib.h"

using namespace std;
class Shop
{
private:
	string shopName;
public:
	Shop();
	Shop(string name, vector<UseItem*> itemlist);
	vector<UseItem*> itemList = {new HealthPotion, new DamageBoost };
	virtual ~Shop();
	string getShopName();

	void Shopping(Player* player);

	void ShowItemlist();

	void BuyItem(Player* player, int index);

	void ShowPlayerItemList(Player* player);

	void SellItem(Player* player, int index);
};

class NormalShop : public Shop
{
public:
	NormalShop(vector<UseItem*> itemlist) : Shop("NormalShop", itemlist) {}
	~NormalShop(){}
};

class HiddenShop : public Shop
{
public:
	HiddenShop(vector<UseItem*> itemlist) : Shop("HiddenShop", itemlist) {}
	~HiddenShop(){}
};