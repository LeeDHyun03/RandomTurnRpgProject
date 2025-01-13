#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "Charater.h"

using namespace std;

class Item {
public:
    string name;
    int effect;

    Item() {
        if (rand() % 2 == 0) {
            name = "ü�� ȸ�� ������";
            effect = 50; // ü�� ȸ��
        }
        else {
            name = "���ݷ� ���� ������";
            effect = 10; // ���ݷ� ����
        }
    }

    void use(Character& player) {
        if (name == "ü�� ȸ�� ������") {
            player.health += effect;
            if (player.health > player.maxHealth) player.health = player.maxHealth;
            cout << player.name << "��(��) ü�� ȸ�� �������� ����Ͽ� ü���� " << effect << "��ŭ ȸ���Ǿ����ϴ�." << endl;
        }
        else if (name == "���ݷ� ���� ������") {
            player.damage += effect;
            std::cout << player.name << "��(��) ���ݷ� ���� �������� ����Ͽ� ���ݷ��� " << effect << "��ŭ �����߽��ϴ�." << std::endl;
        }
    }
};

#endif