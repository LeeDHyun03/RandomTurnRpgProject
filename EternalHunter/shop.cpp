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
	
	cout << shopName << "에 방문했습니다.\n";
	Sleep(500);

	system("cls");
	while (true)
	{
		int index = 0;
		player->showInfo();
		Sleep(300);
		cout << "\n-----------------------------------------------------------------------\n";
		cout << shopName << "에 방문했습니다.\n";
		cout << "-----------------------------------------------------------------------\n\n";
		Sleep(300);
		cout << "1번 : 아이템 구매하기\n";
		Sleep(300);
		cout << "2번 : 아이템 판매하기\n";
		Sleep(300);
		cout << "3번 : 무기 강화하기\n";
		Sleep(300);
		cout << "4번 : 상점 나가기\n";
		Sleep(300);
		cout << "번호: ";
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
			cout << "판매 목록 확인\n";
			Sleep(300);
			ShowItemlist();
			cout << "-----------------------------------------------------------------------\n";
			cout << "\n";
			while (true)
			{
				cout << "구매할 아이템 번호를 입력해주세요. 구매할 아이템이 없으신 경우 아무키를 눌러 상점화면으로 돌아가실 수 있습니다.\n";
				cout << "아이템 번호: ";
				cin >> index;
				if (index - 1 < itemList.size())
				{
					BuyItem(player, index - 1);
					break;
				}
				else
				{
					cout << "\n상점으로 돌아갑니다.\n";
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
				cout << "소지 아이템 목록 확인\n";
				ShowPlayerItemList(player);
				cout << "-----------------------------------------------------------------------\n";
				cout << "판매할 아이템 번호를 입력해주세요. 판매할 아이템이 없으신 경우 아무키를 눌러 상점화면으로 돌아가실 수 있습니다.\n";
				cout << "아이템 번호: ";
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
					cout << "\n상점으로 돌아갑니다.\n";
					break;
				}
			}
			break;
		case 3:
			system("cls");
			player->showInfo();
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			cout << "무기를 강화합니다." << endl;
			cout << "\n-----------------------------------------------------------------------\n";
			cout << "1 ~ 5 까지의 숫자를 눌러주세요.";
			succesProb = randomInRange(1, 5);
			destroyProb = randomInRange(1, 5);
			while (true)
			{
				cin >> choice;
				if (!cin || choice > 5 || choice < 1)
				{
					cout << "1 ~ 5 사이의 숫자만 입력해주세요\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				else break;
			}
			if (succesProb == destroyProb || succesProb == choice)
			{
				player->getWeapon()->enforce(1);
				cout << "강화 성공!! 현재 강화 수치 : " << player->getWeapon()->getStack() << endl;
				player->applyDamage();
				cout << "\n무기 데미지" << player->getWeaponDamage() << endl;
			}
			else if (destroyProb == choice)
			{
				cout << "강화에 실패하여 장비가 파괴되었습니다." << endl;
				player->getWeapon()->setName("무기였던 것");  // 강화 실패 시 무기 이름 변경
				player->getWeapon()->breakWeapon();  // 강화 실패 시 무기 데미지 0으로 설정
				cout << "무기 이름 : " << player->getWeapon()->getName() << "       무기 데미지 : " << player->getWeapon()->getDamageAmount() << endl;
				player->applyDamage();
			}
			else
			{
				cout << "\n강화에 실패하였습니다.\n";
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
			cout << "상점을 나왔습니다.." << endl;
			cout << "-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			this_thread::sleep_for(chrono::milliseconds(1200));
			system("cls");
			player->showInfo();
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
		cout << i + 1 << ":" << itemList[i]->getName() << "              가격 : " << itemList[i]->getPrice() << endl;
	}
}
void Shop::ShowPlayerItemList(Player* player) {
	cout << "플레이어 아이템 목록" << endl;
	player->showInventory();  // 플레이어의 인벤토리 아이템 목록을 보여줌
}

void Shop::BuyItem(Player* player, int index)
{
	// 아이템 구매가 가능한지 확인
	if (player->getGold() >= itemList[index]->getPrice())
	{
		UseItem* item = itemList[index];
		Sleep(300);
		cout << "\n" << item->getName() << "을(를) 구매했습니다.\n";
		player->modifyGold(-item->getPrice());  // 골드 차감
		Sleep(300);
		cout << "현재 잔액: " << player->getGold() << " 골드\n";
		// 아이템을 플레이어 인벤토리에 추가
		player->addItemToInventory(item);
		Sleep(300);
	}
	else
	{
		Sleep(300);
		cout << "돈이 모자라서 구매할 수 없습니다.\n";
		Sleep(300);
	}
}


void Shop::SellItem(Player* player, int index)
{
	if (index >= 0 && index < player->getInventory().getSize()) {
		Item* itemToSell = player->getInventory().getItem(index);
		// 아이템의 원래 가격을 가져와서 60%로 계산
		int sellPrice = itemToSell->getPrice() * 0.6;
		cout << itemToSell->getName() << "을(를) 팔고 " << sellPrice << "골드를 얻었습니다.\n";
		player->modifyGold(sellPrice);  // 골드 증가
		player->removeItemFromInventory(index);  // 아이템 판매 후 인벤토리에서 제거
		cout << "현재 잔액: " << player->getGold() << " 골드\n";
	}
	else {
		cout << "잘못된 아이템 인덱스입니다.\n";
	}
}

HiddenShop::HiddenShop(vector<UseItem*> itemList) : Shop("Hidden Shop", itemList) {}

void HiddenShop::ShowHiddenShop(Player* player) {
	int index;
	cout << "숨겨진 상점에서 판매하는 아이템:" << endl;
	ShowItemlist();  // 히든 상점의 아이템 목록을 출력합니다.

	cout << "구매할 아이템 번호를 입력하세요: ";
	cin >> index;

	if (index > 0 && index <= itemList.size()) {
		BuyItem(player, index - 1);
	}
	else {
		cout << "잘못된 아이템 번호입니다." << endl;
	}
}