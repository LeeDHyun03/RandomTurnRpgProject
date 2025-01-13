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

    // 생성자 선언
    Character(string name);

    // 상태 확인 메서드 선언
    void showStatus();

    // 레벨업 처리 메서드 선언
    void levelUp();

    // 경험치와 골드 추가 메서드 선언
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
    cout << "캐릭터 상태: " << endl;
    cout << "이름: " << name << ", 레벨: " << level << ", 체력: " << health << "/" << maxHealth
        << ", 공격력: " << damage << ", 경험치: " << experience << ", 골드: " << gold << endl;
}

// 레벨업 처리
void Character::levelUp() {
    while (experience >= 100 && level < 10) {
        experience -= 100;
        level++;
        health = maxHealth = health + (level * 20); // 레벨업 시 체력 증가
        damage = damage + (level * 5); // 레벨업 시 공격력 증가
        cout << name << "가 레벨업! 현재 레벨: " << level << endl;
        cout << "체력: " << health << ", 공격력: " << damage << endl;
    }
}

// 경험치와 골드 추가
void Character::gainExperienceAndGold(int exp, int g) {
    experience += exp;
    gold += g;
    cout << name << "이 " << exp << " 경험치와 " << g << " 골드를 획득했습니다." << endl;
    levelUp(); // 경험치가 100 이상이면 자동으로 레벨업
};


#endif