#pragma once
#include "shop.h"

Shop::Shop() {}
Shop::Shop(string name, vector<Item*> itemlist) : shopName(name), itemList(itemlist) {}
vector<Item*> itemList = { new HealthPotion, new DamageBoost };
Shop::~Shop()
{
	for (int i = 0; i < itemList.size(); i++)
	{
		delete itemList[i];
	}
}
string Shop::getShopName() { return this->shopName; }

void Shop::Shopping(Player* player)
{
	cout << shopName << "에 방문했습니다.\n";
	while (true)
	{
		int index = 0;

		cout << "-----------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------\n\n";
		cout << "1번 : 아이템 구매하기\n";
		cout << "2번 : 아이템 판매하기\n";
		cout << "3번 : 무기 강화하기\n";
		cout << "4번 : 상점 나가기\n";
		cin >> index;
		switch (index)
		{
		case 1:
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			cout << "판매 목록 확인\n";
			ShowItemlist();
			cout << "-----------------------------------------------------------------------\n";
			cout << "\n";
			while (true)
			{
				cout << "구매할 아이템 인덱스를 입력해주세요:  ";
				cin >> index;
				if (index < itemList.size())
				{
					BuyItem(player, index);
					break;
				}
				else
				{
					cout << "\n목록에 있는 거만 사주세요\n";
				}
			}
			break;
		case 2:
			while (true)
			{
				cout << "\n-----------------------------------------------------------------------\n";
				cout << "-----------------------------------------------------------------------\n";
				ShowPlayerItemList(player);
				cout << "판매할 아이템 인덱스를 입력해주세요\n";
				cin >> index;
				if (index < player->getInventory().size())
				{
					SellItem(player, index);
					break;
				}
				else
				{
					cout << "없는 거 팔지 마세요\n";
					break;
				}
			}
			break;
		case 3:
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			cout << "무기를 강화합니다." << endl;

			break;
		case 4:
			cout << "\n";
			cout << "상점을 나왔습니다.." << endl;
			cout << "-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			return;
		default:
			cout << "숫자를 잘못 입력하셨습니다.\n";
			break;
		}
	}
}

void Shop::ShowItemlist()
{
	for (int i = 0; i < itemList.size(); i++)
	{
		cout << i << ":" << itemList[i]->getName() << "              가격 : " << itemList[i]->getPrice() << endl;
	}
}

Item* Shop::BuyItem(Player* player, int index)
{
	if (player->getGold() > itemList[index]->getPrice())
	{
		cout << "\n" << itemList[index]->getName() << "을(를) 구매했습니다." << endl;
		player->modifyGold(-itemList[index]->getPrice());
		cout << "현재 잔액 : " << player->getGold() << "골드" << endl;
		return itemList[index];
	}
	else
	{
		cout << "돈이 모자라" << endl;
		return nullptr;
	}
}

void Shop::ShowPlayerItemList(Player* player)
{
	cout << "플레이어 아이템 목록" << endl;
	for (int i = 0; i < player->getInventory().size(); i++)
	{
		cout << player->getInventory()[i] << endl;
	}
}

void Shop::SellItem(Player* player, int index)
{
	cout << player->getInventory().at(index)->getName() << "를 팔고 " << player->getInventory().at(index)->getPrice() << "골드를 얻었습니다." << endl;
	player->modifyGold(player->getInventory().at(index)->getPrice());
	player->removeItemFromPlayerInventory(index);
}