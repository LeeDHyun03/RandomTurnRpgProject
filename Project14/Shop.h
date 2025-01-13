#ifndef SHOP_H
#define SHOP_H

#include "Item.h"
#include <iostream>

class Shop {
public:
    static void shopMenu(Character& player) {
        cout << "=== 상점 ===" << endl;
        cout << "1. 체력 회복 아이템 (50 골드) [체력 +50]" << endl;
        cout << "2. 공격력 증가 아이템 (70 골드) [공격력 +10]" << endl;
        cout << "현재 골드: " << player.gold << endl;

        int choice;
        cout << "구매할 아이템 번호를 입력하세요 (1 또는 2, 0은 취소): ";
        cin >> choice;

        if (choice == 1) {
            if (player.gold >= 50) {
                player.gold -= 50;
                Item item;
                item.use(player);
            }
            else {
                cout << "골드가 부족합니다!" << endl;
            }
        }
        else if (choice == 2) {
            if (player.gold >= 70) {
                player.gold -= 70;
                Item item;
                item.use(player);
            }
            else {
                cout << "골드가 부족합니다!" << endl;
            }
        }
        else if (choice == 0) {
            cout << "상점 이용을 취소합니다." << endl;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
        }
    }
};

#endif