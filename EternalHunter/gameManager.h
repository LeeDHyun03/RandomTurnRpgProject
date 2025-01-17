#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Shop.h"
#include "customlib.h"
#include "useItem.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

class GameManager {
private:
    string input = string();
public:
    vector<Monster*> monsters;
    vector<Shop*> shops = { new NormalShop({new HealthPotion(), new DamageBoost(), new StunGun}),
                            new HiddenShop({ new WorldMostWeapon(), new MiddleWeapon() }) };
    vector<UseItem*> activateItems;
    Player* player;
    bool isBattle = true;

    GameManager();
    ~GameManager();

    void SetMonsters(int level);

	void UsingItemWithProbability(int probability, Character* playerChar, Character* monster);
	void IsPlayerWinAtCombat();
	bool isDieCheck(Monster* monster);
	void  SetResultAfterCombat(Monster* monster);

    bool DealDamage(Character* attacker, Character* victim, Monster* monster);
    void VisitAtShop();

	void DeactivateItem(Monster* monster);

    void Defeat();

    void StartGame();

    bool KillDragon(Monster* monster);


    void EndGame();
};