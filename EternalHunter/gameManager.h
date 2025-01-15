#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Shop.h"
#include "customlib.h"
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
	Player* player;
	GameManager();
	~GameManager();

	void SetMonsters(int level);

	void UsingItemWithProbability(int probability, Character* character);
	void IsPlayerWinAtCombat();
	bool isDieCheck(Monster* monster);
	void  SetResultAfterCombat(Monster* monster);

	void DealDamage(Character* attacker, Character* victim);
	void VisitAtShop();



	void Defeat();

	void StartGame();
};