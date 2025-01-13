#ifndef PLAYER_H
#define PLAYER_H

#include "Monster.h" 
#include "Charater.h" 
class Player : public Character {
public:
    // 생성자에서 Character 클래스의 생성자 호출
    Player(string name) : Character(name) {}

    // 플레이어 전용 메서드
    void attackMonster(Monster& monster) {
        int damage = max(0, damage - (monster.damage / 2)); // 몬스터 방어를 고려한 공격력
        monster.health -= damage;  // 몬스터의 체력 감소
        cout << name << "이(가) " << monster.name << "을(를) 공격합니다! "
            << monster.name << " 체력: " << monster.health << endl;
    }

    void levelUp() {
        // Player 클래스에서 특별한 레벨업 처리 로직을 추가할 수 있습니다.
        Character::levelUp();  // 기본 레벨업 로직을 호출
    }
};

#endif // PLAYER_H