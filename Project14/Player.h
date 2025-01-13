#ifndef PLAYER_H
#define PLAYER_H

#include "Monster.h" 
#include "Charater.h" 
class Player : public Character {
public:
    // �����ڿ��� Character Ŭ������ ������ ȣ��
    Player(string name) : Character(name) {}

    // �÷��̾� ���� �޼���
    void attackMonster(Monster& monster) {
        int damage = max(0, damage - (monster.damage / 2)); // ���� �� ����� ���ݷ�
        monster.health -= damage;  // ������ ü�� ����
        cout << name << "��(��) " << monster.name << "��(��) �����մϴ�! "
            << monster.name << " ü��: " << monster.health << endl;
    }

    void levelUp() {
        // Player Ŭ�������� Ư���� ������ ó�� ������ �߰��� �� �ֽ��ϴ�.
        Character::levelUp();  // �⺻ ������ ������ ȣ��
    }
};

#endif // PLAYER_H