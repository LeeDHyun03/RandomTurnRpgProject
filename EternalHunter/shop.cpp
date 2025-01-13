#include "shop.h"


Shop::Shop() {}
Shop::Shop(string name, vector<Item*> itemlist) : shopName(name), itemList(itemlist) {}

//Push ready
void Shop::Shopping(Player* player)
{
	cout << shopName << "�� �湮�߽��ϴ�." << endl;
	while (true)
	{
		int index = 0;
		cin >> index;
		switch (index)
		{
		case 1:
			cout << "�Ǹ� ��� Ȯ��" << endl;
			ShowItemlist();
			break;
		case 2:
			cout << "������ ������ �ε����� �Է����ּ���" << endl;
			cin >> index;
			BuyItem(player, index);
			break;
		case 3:
			ShowPlayerItemList(player);
			cout << "�Ǹ��� ������ �ε����� �Է����ּ���" << endl;
			cin >> index;
			SellItem(player, index);
			break;
		case 4:
			cout << "����" << endl;
			return;
		default:
			cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�." << endl;
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
	cout << "�÷��̾� ������ ���" << endl;
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