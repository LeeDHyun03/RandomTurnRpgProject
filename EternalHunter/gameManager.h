#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Shop.h"
#include "customlib.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;



class GameManager
{
public:
	vector<Monster*> monsters;
	vector<Shop*> shops = { new NormalShop({new HealthPotion, new DamageBoost}), new HiddenShop({new HealthPotion, new DamageBoost}) };
	Player* player;
	GameManager();
	~GameManager();

	void SetMonsters(int level);

	void UsingItemWithProbability(int probability, vector<Item*> playerItems, Character* character);
	void IsPlayerWinAtCombat();

	void  SetResultAfterCombat(Monster* monster);

	void DealDamage(Character* attacker, Character* victim);
	void VisitAtShop();



	void Defeat();

	void StartGame();
};