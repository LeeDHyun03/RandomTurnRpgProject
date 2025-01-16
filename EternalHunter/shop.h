#pragma once
#include "player.h"
#include "item.h"
#include "customlib.h"
#include <windows.h>

class UseItem;
using namespace std;
class Shop
{
private:
	string shopName;
public:
	Shop();
	Shop(string name, vector<UseItem*> itemlist);
	vector<UseItem*> itemList = {new HealthPotion, new DamageBoost, new StunGun };
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


class HiddenShop : public Shop {
public:
	HiddenShop(vector<UseItem*> itemList);  // 생성자에 아이템 리스트 전달
	void ShowHiddenShop(Player* player);  // 히든 상점 아이템 구매
};