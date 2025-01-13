#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>  // max() 함수를 사용하기 위해 필요
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
                // 플레이어 공격
                int damage = max(0, player.damage - (monster.damage / 2)); // 몬스터 방어를 고려한 공격력
                monster.health -= damage;
                cout << player.name << "이(가) " << monster.name << "을(를) 공격합니다! "
                    << monster.name << " 체력: " << monster.health << endl;
            }
            else {
                // 몬스터 공격
                int damage = max(0, monster.damage - (player.damage / 2)); // 캐릭터 방어를 고려한 공격력
                player.health -= damage;
                cout << monster.name << "이(가) " << player.name << "을(를) 공격합니다! "
                    << player.name << " 체력: " << player.health << endl;
            }

            playerTurn = !playerTurn; // 턴 변경
        }

        if (player.health <= 0) {
            cout << player.name << "이(가) 사망했습니다. 게임 오버!" << endl;
        }
        else {
            cout << monster.name << "을 처치했습니다!" << endl;
            int exp = 50;
            int gold = rand() % 11 + 10; // 10~20 랜덤 골드
            player.gainExperienceAndGold(exp, gold);

            // 아이템 획득 확률 (30%)
            if (rand() % 10 < 3) {
                Item item;
                item.use(player);
            }
        }
    }

    static void startGame() {
        srand(static_cast<unsigned int>(time(0)));

        string playerName;
        cout << "캐릭터 이름을 입력하세요: ";
        cin >> playerName;

        // 이름에 공백이 포함된 경우 다시 입력 받기
        while (playerName.find(' ') != string::npos) {
            cout << "이름에 공백을 포함할 수 없습니다. 다시 입력해 주세요: ";
            cin >> playerName;
        }

        Player player(playerName);
        cout << "캐릭터 " << playerName << " 생성 완료! 레벨: " << player.level << ", 체력: " << player.health << ", 공격력: " << player.damage << endl;

        while (true) {
            Monster monster(player.level);
            monster.showInfo();

            battle(player, monster);

            player.showStatus();

            if (player.health <= 0 || player.level == 10) {
                cout << "게임 종료!" << endl;
                break;
            }

            char choice;
            bool validChoice = false;

            while (!validChoice) {  // 유효한 입력을 받을 때까지 반복
                cout << "상점을 이용하시겠습니까? (y/n): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    Shop::shopMenu(player); // 상점 방문
                    validChoice = true; // 유효한 입력을 받았으므로 루프 종료
                }
                else if (choice == 'n' || choice == 'N') {
                    // 상점 이용 안 함, 전투로 돌아가기
                    validChoice = true; // 유효한 입력을 받았으므로 루프 종료
                    continue;  // 전투로 돌아갑니다.
                }
                else {
                    // 잘못된 입력
                    cout << "잘못된 입력입니다. 다시 선택해 주세요." << endl;
                }
            }
        }
    }
};

#endif