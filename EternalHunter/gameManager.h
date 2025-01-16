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



class GameManager
{
private:
	string input = string();
public:
	vector<Monster*> monsters;
	vector<Shop*> shops = { new NormalShop({new HealthPotion, new DamageBoost}), new HiddenShop({new HealthPotion, new DamageBoost}) };
	vector<UseItem*> activateItems;
	Player* player;
	bool isBattle = true;
	GameManager();
	~GameManager();

	void SetMonsters(int level);

	void UsingItemWithProbability(int probability, Character* character);
	void IsPlayerWinAtCombat();
	bool isDieCheck(Monster* monster);
	void  SetResultAfterCombat();

	bool DealDamage(Character* attacker, Character* victim, Monster* monster);
	void VisitAtShop();

	void DeactivateItem();

	void Defeat();

	void StartGame();
};