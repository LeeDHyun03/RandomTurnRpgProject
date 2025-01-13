#ifndef SHOP_H
#define SHOP_H

#include "Item.h"
#include <iostream>

class Shop {
public:
    static void shopMenu(Character& player) {
        cout << "=== ���� ===" << endl;
        cout << "1. ü�� ȸ�� ������ (50 ���) [ü�� +50]" << endl;
        cout << "2. ���ݷ� ���� ������ (70 ���) [���ݷ� +10]" << endl;
        cout << "���� ���: " << player.gold << endl;

        int choice;
        cout << "������ ������ ��ȣ�� �Է��ϼ��� (1 �Ǵ� 2, 0�� ���): ";
        cin >> choice;

        if (choice == 1) {
            if (player.gold >= 50) {
                player.gold -= 50;
                Item item;
                item.use(player);
            }
            else {
                cout << "��尡 �����մϴ�!" << endl;
            }
        }
        else if (choice == 2) {
            if (player.gold >= 70) {
                player.gold -= 70;
                Item item;
                item.use(player);
            }
            else {
                cout << "��尡 �����մϴ�!" << endl;
            }
        }
        else if (choice == 0) {
            cout << "���� �̿��� ����մϴ�." << endl;
        }
        else {
            cout << "�߸��� �Է��Դϴ�." << endl;
        }
    }
};

#endif