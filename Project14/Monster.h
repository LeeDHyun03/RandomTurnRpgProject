#ifndef MONSTER_H
#define MONSTER_H


#include "Charater.h"

class Monster : public Character {
public:
    Monster(int level) : Character("Monster") {
        health = rand() % (level * 30 - level * 20 + 1) + (level * 20);
        damage = rand() % (level * 10 - level * 5 + 1) + (level * 5);
    }

    // 몬스터 전용 메서드
    void showInfo() {
        cout << "몬스터 " << name << " 등장!" << endl;
        cout << "체력: " << health << ", 공격력: " << damage << endl;
    }

    bool isAlive() {
        return health > 0;
    }
};

#endif