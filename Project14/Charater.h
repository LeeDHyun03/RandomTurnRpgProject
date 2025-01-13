#pragma once
#ifndef CHARATER_H
#define CHARATER_H
#include <iostream>
#include <string>
#include "Charater.h"
using namespace std;

class Character {
public:
    string name;
    int level;
    int health;
    int maxHealth;
    int damage;
    int experience;
    int gold;

    // ������ ����
    Character(string name);

    // ���� Ȯ�� �޼��� ����
    void showStatus();

    // ������ ó�� �޼��� ����
    void levelUp();

    // ����ġ�� ��� �߰� �޼��� ����
    void gainExperienceAndGold(int exp, int g);
   


};

Character::Character(string name) {
    this->name = name;
    this->level = 1;
    this->health = 200;
    this->maxHealth = 200;
    this->damage = 30;
    this->experience = 0;
    this->gold = 0;
}

void Character::showStatus() {
    cout << "ĳ���� ����: " << endl;
    cout << "�̸�: " << name << ", ����: " << level << ", ü��: " << health << "/" << maxHealth
        << ", ���ݷ�: " << damage << ", ����ġ: " << experience << ", ���: " << gold << endl;
}

// ������ ó��
void Character::levelUp() {
    while (experience >= 100 && level < 10) {
        experience -= 100;
        level++;
        health = maxHealth = health + (level * 20); // ������ �� ü�� ����
        damage = damage + (level * 5); // ������ �� ���ݷ� ����
        cout << name << "�� ������! ���� ����: " << level << endl;
        cout << "ü��: " << health << ", ���ݷ�: " << damage << endl;
    }
}

// ����ġ�� ��� �߰�
void Character::gainExperienceAndGold(int exp, int g) {
    experience += exp;
    gold += g;
    cout << name << "�� " << exp << " ����ġ�� " << g << " ��带 ȹ���߽��ϴ�." << endl;
    levelUp(); // ����ġ�� 100 �̻��̸� �ڵ����� ������
};


#endif