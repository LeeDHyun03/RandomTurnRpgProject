#pragma once
#include "shop.h"
#include <thread>
#include <chrono>
Shop::Shop() {}
Shop::Shop(string name, vector<UseItem*> itemlist) : shopName(name), itemList(itemlist) {}
vector<UseItem*> itemList = { new HealthPotion, new DamageBoost, new StunGun };
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
	Sleep(1000);
	cout << ".\n" << endl;
	Sleep(1000);
	cout << ".\n" << endl;
	Sleep(1000);
	this_thread::sleep_for(chrono::milliseconds(1200));
	
	cout << shopName << "�� �湮�߽��ϴ�.\n";
	Sleep(500);

	system("cls");
	while (true)
	{
		int index = 0;
		player->showInfo();
		Sleep(300);
		cout << "\n-----------------------------------------------------------------------\n";
		cout << shopName << "�� �湮�߽��ϴ�.\n";
		cout << "-----------------------------------------------------------------------\n\n";
		Sleep(300);
		cout << "1�� : ������ �����ϱ�\n";
		Sleep(300);
		cout << "2�� : ������ �Ǹ��ϱ�\n";
		Sleep(300);
		cout << "3�� : ���� ��ȭ�ϱ�\n";
		Sleep(300);
		cout << "4�� : ���� ������\n";
		Sleep(300);
		cout << "��ȣ: ";
		cin >> index;
		if (!cin)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		switch (index)
		{
		case 1:
			system("cls");
			player->showInfo();
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			cout << "�Ǹ� ��� Ȯ��\n";
			Sleep(300);
			ShowItemlist();
			cout << "-----------------------------------------------------------------------\n";
			cout << "\n";
			while (true)
			{
				cout << "������ ������ ��ȣ�� �Է����ּ���. ������ �������� ������ ��� �ƹ�Ű�� ���� ����ȭ������ ���ư��� �� �ֽ��ϴ�.\n";
				cout << "������ ��ȣ: ";
				cin >> index;
				if (index - 1 < itemList.size())
				{
					BuyItem(player, index - 1);
					break;
				}
				else
				{
					cout << "\n�������� ���ư��ϴ�.\n";
					break;
				}
			}
			break;
		case 2:
			system("cls");
			player->showInfo();
			while (true)
			{
				cout << "\n-----------------------------------------------------------------------\n";
				cout << "-----------------------------------------------------------------------\n";
				cout << "���� ������ ��� Ȯ��\n";
				ShowPlayerItemList(player);
				cout << "-----------------------------------------------------------------------\n";
				cout << "�Ǹ��� ������ ��ȣ�� �Է����ּ���. �Ǹ��� �������� ������ ��� �ƹ�Ű�� ���� ����ȭ������ ���ư��� �� �ֽ��ϴ�.\n";
				cout << "������ ��ȣ: ";
				cin >> index;
				if (index - 1 < player->getInventory().getSize())
				{
					SellItem(player, index - 1);
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "\n�������� ���ư��ϴ�.\n";
					break;
				}
			}
			break;
		case 3:
			system("cls");
			player->showInfo();
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
				cout << "\n���� ������" << player->getWeaponDamage() << endl;
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
			Sleep(1000);
			cout << ".\n" << endl;
			Sleep(1000);
			cout << ".\n" << endl;
			Sleep(1000);
			this_thread::sleep_for(chrono::milliseconds(1200));
			cout << "������ ���Խ��ϴ�.." << endl;
			cout << "-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			this_thread::sleep_for(chrono::milliseconds(1200));
			system("cls");
			player->showInfo();
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
		cout << i + 1 << ":" << itemList[i]->getName() << "              ���� : " << itemList[i]->getPrice() << endl;
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
		Sleep(300);
		cout << "\n" << item->getName() << "��(��) �����߽��ϴ�.\n";
		player->modifyGold(-item->getPrice());  // ��� ����
		Sleep(300);
		cout << "���� �ܾ�: " << player->getGold() << " ���\n";
		// �������� �÷��̾� �κ��丮�� �߰�
		player->addItemToInventory(item);
		Sleep(300);
	}
	else
	{
		Sleep(300);
		cout << "���� ���ڶ� ������ �� �����ϴ�.\n";
		Sleep(300);
	}
}


void Shop::SellItem(Player* player, int index)
{
	if (index >= 0 && index < player->getInventory().getSize()) {
		Item* itemToSell = player->getInventory().getItem(index);
		// �������� ���� ������ �����ͼ� 60%�� ���
		int sellPrice = itemToSell->getPrice() * 0.6;
		cout << itemToSell->getName() << "��(��) �Ȱ� " << sellPrice << "��带 ������ϴ�.\n";
		player->modifyGold(sellPrice);  // ��� ����
		player->removeItemFromInventory(index);  // ������ �Ǹ� �� �κ��丮���� ����
		cout << "���� �ܾ�: " << player->getGold() << " ���\n";
	}
	else {
		cout << "�߸��� ������ �ε����Դϴ�.\n";
	}
}

HiddenShop::HiddenShop(vector<UseItem*> itemList) : Shop("Hidden Shop", itemList) {}

void HiddenShop::ShowHiddenShop(Player* player) {
	int index;
	cout << "������ �������� �Ǹ��ϴ� ������:" << endl;
	ShowItemlist();  // ���� ������ ������ ����� ����մϴ�.

	cout << "������ ������ ��ȣ�� �Է��ϼ���: ";
	cin >> index;

	if (index > 0 && index <= itemList.size()) {
		BuyItem(player, index - 1);
	}
	else {
		cout << "�߸��� ������ ��ȣ�Դϴ�." << endl;
	}
}