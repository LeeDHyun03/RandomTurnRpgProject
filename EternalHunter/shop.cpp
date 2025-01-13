#include "shop.h"


Shop::Shop() {}
Shop::Shop(string name, vector<Item*> itemlist) : shopName(name), itemList(itemlist) {}

//Push ready
void Shop::Shopping(Player* player)
{
	cout << shopName << "에 방문했습니다." << endl;
	while (true)
	{
		int index = 0;
		cin >> index;
		switch (index)
		{
		case 1:
			cout << "판매 목록 확인" << endl;
			ShowItemlist();
			break;
		case 2:
			cout << "구매할 아이템 인덱스를 입력해주세요" << endl;
			cin >> index;
			BuyItem(player, index);
			break;
		case 3:
			ShowPlayerItemList(player);
			cout << "판매할 아이템 인덱스를 입력해주세요" << endl;
			cin >> index;
			SellItem(player, index);
			break;
		case 4:
			cout << "종료" << endl;
			return;
		default:
			cout << "숫자를 잘못 입력하셨습니다." << endl;
			break;
		}
	}
}
void Shop::ShowItemlist()
{
	for (int i = 0; i < itemList.size(); i++)
	{
		cout << i << ":" << itemList[i]->getName() << endl;
	}
}

Item* Shop::BuyItem(Player * player, int index)
{
	if (player->getGold() > itemList[index]->getPrice())
	{
		player->modifyGold(-itemList[index]->getPrice());
		return itemList[index];
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
	player->modifyGold(player->getInventory().at(index)->getPrice());
	player->removeItemFromPlayerInventory(index);
}