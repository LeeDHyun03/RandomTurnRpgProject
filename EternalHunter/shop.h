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
	virtual ~Shop()
	{
		for (int i = 0; i < itemList.size(); i++)
		{
			delete itemList[i];
		}
	}
	string getShopName(){return this->shopName;	}

	void Shopping(Player* player)
	{
		cout << shopName << "에 방문했습니다." << endl;
		while (true)
		{
			int index = 0;

			cout << "1번 : 아이템 구매하기" << endl;
			cout << "2번 : 아이템 판매하기" << endl;
			cout << "3번 : 상점 나가기" << endl;
			cin >> index;
			switch (index)
			{
			case 1:

				cout << "판매 목록 확인" << endl;
				ShowItemlist();

				cout << "-----------------------------------------------------------------------" << endl;

				cout << "구매할 아이템 인덱스를 입력해주세요" << endl;
				cin >> index;
				BuyItem(player, index);
				break;
			case 2:
				ShowPlayerItemList(player);
				cout << "판매할 아이템 인덱스를 입력해주세요" << endl;
				cin >> index;
				SellItem(player, index);
				break;
			case 3:
				cout << "상점을 나왔습니다.." << endl;
				cout << "-----------------------------------------------------------------------" << endl;
				return;
			default:
				cout << "숫자를 잘못 입력하셨습니다." << endl;
				break;
			}
		}
	}

	void ShowItemlist()
	{
		for (int i = 0; i < itemList.size(); i++)
		{
			cout << i << ":" << itemList[i]->getName() << endl;
		}
	}

	Item* BuyItem(Player* player, int index)
	{
		if (player->getGold() > itemList[index]->getPrice())
		{
			cout << itemList[index]->getName() << "을(를) 구매했습니다." << endl;
			player->modifyGold(-itemList[index]->getPrice());
			cout << "현재 잔액 : " << player->getGold() << "골드" << endl;
			return itemList[index];
		}
		else
		{
			cout << "돈이 모자라" << endl;
		}
	}

	void ShowPlayerItemList(Player* player)
	{
		cout << "플레이어 아이템 목록" << endl;
		for (int i = 0; i < player->getInventory().size(); i++)
		{
			cout << player->getInventory()[i] << endl;
		}
	}

	void SellItem(Player* player,int index)
	{
		cout << player->getInventory().at(index)->getName() << "를 팔고 " << player->getInventory().at(index)->getPrice() << "골드를 얻었습니다." << endl;
		player->modifyGold(player->getInventory().at(index)->getPrice());
		player->removeItemFromPlayerInventory(index);
	}
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