#include "item.h"
#include "monster.h"
#include "player.h"
#include "Shop.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "customlib.h"

using namespace std;

template <typename T>
T RandomItemFromVector(const std::vector<T>& vec)
{
	srand(time(NULL));
	if (vec.empty())
	{
		throw std::runtime_error("Vector is empty.");
	}
	size_t index = rand() % vec.size();
	return vec[index];
}

bool ProbabilityCheck(int probability);


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