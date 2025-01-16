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
				if (index < player->getInventory().getSize())
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
				cout << "무기 데미지" << player->getWeaponDamage();
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
			cout << ".\n" << endl;
			cout << ".\n" << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
			cout << "상점을 나왔습니다.." << endl;
			cout << "-----------------------------------------------------------------------\n";
			cout << "-----------------------------------------------------------------------\n";
			this_thread::sleep_for(chrono::milliseconds(1200));
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
		cout << item->getName() << "을(를) 구매했습니다.\n";
		player->modifyGold(-item->getPrice());  // 골드 차감
		cout << "현재 잔액: " << player->getGold() << " 골드\n";
		// 아이템을 플레이어 인벤토리에 추가
		player->addItemToInventory(item);
	}
	else
	{
		cout << "돈이 모자라서 구매할 수 없습니다.\n";
	}
}



void Shop::SellItem(Player* player, int index)
{
	if (index >= 0 && index < player->getInventory().getSize()) {
		Item* itemToSell = player->getInventory().getItem(index);
		cout << itemToSell->getName() << "을(를) 팔고 " << itemToSell->getPrice() << "골드를 얻었습니다.\n";
		// 골드 증가
		player->modifyGold(itemToSell->getPrice());  
		// 아이템 판매 후 인벤토리에서 제거
		player->removeItemFromInventory(index);  
	}
	else {
		cout << "잘못된 아이템 인덱스입니다.\n";
	}
}