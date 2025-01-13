#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>  // max() �Լ��� ����ϱ� ���� �ʿ�
#include "Player.h"
#include "Monster.h"
#include "Shop.h"
#include "Item.h"

using namespace std;

class GameManager {
public:
    static void battle(Player& player, Monster& monster) {
        bool playerTurn = true;

        while (player.health > 0 && monster.health > 0) {
            if (playerTurn) {
                // �÷��̾� ����
                int damage = max(0, player.damage - (monster.damage / 2)); // ���� �� ����� ���ݷ�
                monster.health -= damage;
                cout << player.name << "��(��) " << monster.name << "��(��) �����մϴ�! "
                    << monster.name << " ü��: " << monster.health << endl;
            }
            else {
                // ���� ����
                int damage = max(0, monster.damage - (player.damage / 2)); // ĳ���� �� ����� ���ݷ�
                player.health -= damage;
                cout << monster.name << "��(��) " << player.name << "��(��) �����մϴ�! "
                    << player.name << " ü��: " << player.health << endl;
            }

            playerTurn = !playerTurn; // �� ����
        }

        if (player.health <= 0) {
            cout << player.name << "��(��) ����߽��ϴ�. ���� ����!" << endl;
        }
        else {
            cout << monster.name << "�� óġ�߽��ϴ�!" << endl;
            int exp = 50;
            int gold = rand() % 11 + 10; // 10~20 ���� ���
            player.gainExperienceAndGold(exp, gold);

            // ������ ȹ�� Ȯ�� (30%)
            if (rand() % 10 < 3) {
                Item item;
                item.use(player);
            }
        }
    }

    static void startGame() {
        srand(static_cast<unsigned int>(time(0)));

        string playerName;
        cout << "ĳ���� �̸��� �Է��ϼ���: ";
        cin >> playerName;

        // �̸��� ������ ���Ե� ��� �ٽ� �Է� �ޱ�
        while (playerName.find(' ') != string::npos) {
            cout << "�̸��� ������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���: ";
            cin >> playerName;
        }

        Player player(playerName);
        cout << "ĳ���� " << playerName << " ���� �Ϸ�! ����: " << player.level << ", ü��: " << player.health << ", ���ݷ�: " << player.damage << endl;

        while (true) {
            Monster monster(player.level);
            monster.showInfo();

            battle(player, monster);

            player.showStatus();

            if (player.health <= 0 || player.level == 10) {
                cout << "���� ����!" << endl;
                break;
            }

            char choice;
            bool validChoice = false;

            while (!validChoice) {  // ��ȿ�� �Է��� ���� ������ �ݺ�
                cout << "������ �̿��Ͻðڽ��ϱ�? (y/n): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    Shop::shopMenu(player); // ���� �湮
                    validChoice = true; // ��ȿ�� �Է��� �޾����Ƿ� ���� ����
                }
                else if (choice == 'n' || choice == 'N') {
                    // ���� �̿� �� ��, ������ ���ư���
                    validChoice = true; // ��ȿ�� �Է��� �޾����Ƿ� ���� ����
                    continue;  // ������ ���ư��ϴ�.
                }
                else {
                    // �߸��� �Է�
                    cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���." << endl;
                }
            }
        }
    }
};

#endif