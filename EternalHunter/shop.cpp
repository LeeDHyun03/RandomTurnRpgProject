#pragma once
#include "shop.h"
#include <thread>
#include <chrono>
Shop::Shop() {}
Shop::Shop(string name, vector<UseItem*> itemlist) : shopName(name), itemList(itemlist) {}
vector<UseItem*> itemList = { new HealthPotion, new DamageBoost };
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
	int choice = 0;

	int succesProb = 0;
	int destroyProb = 0;

	this_thread::sleep_for(chrono::milliseconds(500));
	cout << ".\n" << endl;
	cout << ".\n" << endl;
	cout << ".\n" << endl;
	this_thread::sleep_for(chrono::milliseconds(1200));

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
		if (!cin)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
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
				if (index < player->getInventory().getSize())
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
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "1 ~ 5 ������ ���ڸ� �����ּ���.";
			succesProb = randomInRange(1, 5);
			destroyProb = randomInRange(1, 5);
			while (true)
			{
				cin >> choice;
				if (!cin || choice > 5 || choice < 1)
				{
					cout << "1 ~ 5 ������ ���ڸ� �Է����ּ���\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				else break;
			}
			if (succesProb == destroyProb || succesProb == choice)
			{
				player->getWeapon()->enforce(1);
				cout << "��ȭ ����!! ���� ��ȭ ��ġ : " << player->getWeapon()->getStack() << endl;
				player->applyDamage();
				cout << "���� ������" << player->getWeaponDamage();
			}
			else if (destroyProb == choice)
			{
				cout << "��ȭ�� �����Ͽ� ��� �ı��Ǿ����ϴ�." << endl;
				player->getWeapon()->setName("���⿴�� ��");  // ��ȭ ���� �� ���� �̸� ����
				player->getWeapon()->breakWeapon();  // ��ȭ ���� �� ���� ������ 0���� ����
				cout << "���� �̸� : " << player->getWeapon()->getName() << "       ���� ������ : " << player->getWeapon()->getDamageAmount() << endl;
				player->applyDamage();
			}
			else
			{
				cout << "\n��ȭ�� �����Ͽ����ϴ�.\n";
			}
			
			break;
		case 4:
			this_thread::sleep_for(chrono::milliseconds(500));
			cout << ".\n" << endl;
			cout << ".\n" << endl;
			cout << ".\n" << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
			cout << "������ ���Խ��ϴ�.." << endl;
			cout << "-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			this_thread::sleep_for(chrono::milliseconds(1200));
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
void Shop::ShowPlayerItemList(Player* player) {
	cout << "�÷��̾� ������ ���" << endl;
	player->showInventory();  // �÷��̾��� �κ��丮 ������ ����� ������
}

void Shop::BuyItem(Player* player, int index)
{
	// ������ ���Ű� �������� Ȯ��
	if (player->getGold() >= itemList[index]->getPrice())
	{
		UseItem* item = itemList[index];
		cout << item->getName() << "��(��) �����߽��ϴ�.\n";
		player->modifyGold(-item->getPrice());  // ��� ����
		cout << "���� �ܾ�: " << player->getGold() << " ���\n";
		// �������� �÷��̾� �κ��丮�� �߰�
		player->addItemToInventory(item);
	}
	else
	{
		cout << "���� ���ڶ� ������ �� �����ϴ�.\n";
	}
}



void Shop::SellItem(Player* player, int index)
{
	if (index >= 0 && index < player->getInventory().getSize()) {
		Item* itemToSell = player->getInventory().getItem(index);
		cout << itemToSell->getName() << "��(��) �Ȱ� " << itemToSell->getPrice() << "��带 ������ϴ�.\n";
		// ��� ����
		player->modifyGold(itemToSell->getPrice());  
		// ������ �Ǹ� �� �κ��丮���� ����
		player->removeItemFromInventory(index);  
	}
	else {
		cout << "�߸��� ������ �ε����Դϴ�.\n";
	}
}