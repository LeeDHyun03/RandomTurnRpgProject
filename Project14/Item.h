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
            name = "체력 회복 아이템";
            effect = 50; // 체력 회복
        }
        else {
            name = "공격력 증가 아이템";
            effect = 10; // 공격력 증가
        }
    }

    void use(Character& player) {
        if (name == "체력 회복 아이템") {
            player.health += effect;
            if (player.health > player.maxHealth) player.health = player.maxHealth;
            cout << player.name << "이(가) 체력 회복 아이템을 사용하여 체력이 " << effect << "만큼 회복되었습니다." << endl;
        }
        else if (name == "공격력 증가 아이템") {
            player.damage += effect;
            std::cout << player.name << "이(가) 공격력 증가 아이템을 사용하여 공격력이 " << effect << "만큼 증가했습니다." << std::endl;
        }
    }
};

#endif