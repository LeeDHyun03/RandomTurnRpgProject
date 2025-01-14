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
	cout << shopName << "�� �湮�߽��ϴ�.\n";
	while (true)
	{
		int index = 0;

		cout << "-----------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------\n\n";
		cout << "1�� : ������ �����ϱ�\n";
		cout << "2�� : ������ �Ǹ��ϱ�\n";
		cout << "3�� : ���� ��ȭ�ϱ�\n";
		cout << "4�� : ���� ������\n";
		cin >> index;
		switch (index)
		{
		case 1:
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			cout << "�Ǹ� ��� Ȯ��\n";
			ShowItemlist();
			cout << "-----------------------------------------------------------------------\n";
			cout << "\n";
			while (true)
			{
				cout << "������ ������ �ε����� �Է����ּ���:  ";
				cin >> index;
				if (index < itemList.size())
				{
					BuyItem(player, index);
					break;
				}
				else
				{
					cout << "\n��Ͽ� �ִ� �Ÿ� ���ּ���\n";
				}
			}
			break;
		case 2:
			while (true)
			{
				cout << "\n-----------------------------------------------------------------------\n";
				cout << "-----------------------------------------------------------------------\n";
				ShowPlayerItemList(player);
				cout << "�Ǹ��� ������ �ε����� �Է����ּ���\n";
				cin >> index;
				if (index < player->getInventory().size())
				{
					SellItem(player, index);
					break;
				}
				else
				{
					cout << "���� �� ���� ������\n";
					break;
				}
			}
			break;
		case 3:
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			cout << "���⸦ ��ȭ�մϴ�." << endl;

			break;
		case 4:
			cout << "\n";
			cout << "������ ���Խ��ϴ�.." << endl;
			cout << "-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			return;
		default:
			cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�.\n";
			break;
		}
	}
}

void Shop::ShowItemlist()
{
	for (int i = 0; i < itemList.size(); i++)
	{
		cout << i << ":" << itemList[i]->getName() << "              ���� : " << itemList[i]->getPrice() << endl;
	}
}

Item* Shop::BuyItem(Player* player, int index)
{
	if (player->getGold() > itemList[index]->getPrice())
	{
		cout << "\n" << itemList[index]->getName() << "��(��) �����߽��ϴ�." << endl;
		player->modifyGold(-itemList[index]->getPrice());
		cout << "���� �ܾ� : " << player->getGold() << "���" << endl;
		return itemList[index];
	}
	else
	{
		cout << "���� ���ڶ�" << endl;
		return nullptr;
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
	cout << player->getInventory().at(index)->getName() << "�� �Ȱ� " << player->getInventory().at(index)->getPrice() << "��带 ������ϴ�." << endl;
	player->modifyGold(player->getInventory().at(index)->getPrice());
	player->removeItemFromPlayerInventory(index);
}