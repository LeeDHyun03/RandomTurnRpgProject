#ifndef MONSTER_H
#define MONSTER_H


#include "Charater.h"

class Monster : public Character {
public:
    Monster(int level) : Character("Monster") {
        health = rand() % (level * 30 - level * 20 + 1) + (level * 20);
        damage = rand() % (level * 10 - level * 5 + 1) + (level * 5);
    }

    // ���� ���� �޼���
    void showInfo() {
        cout << "���� " << name << " ����!" << endl;
        cout << "ü��: " << health << ", ���ݷ�: " << damage << endl;
    }

    bool isAlive() {
        return health > 0;
    }
};

#endif