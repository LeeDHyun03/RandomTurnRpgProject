#include "item.h"
#include "monster.h"
#include "player.h"
#include "Shop.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

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

bool ProbabilityCheck(int probability)
{
	srand(time(NULL));
	if (rand() % 100 <= probability)
	{
		return true;
	}
	else
	{
		return false;
	}
}


class GameManager
{
public:
	vector<Monster*> monsters;
	vector<Shop*> shops = { new NormalShop({new HealthPotion, new DamageBoost}), new HiddenShop({new HealthPotion, new DamageBoost}) };
	Player* player;
	GameManager() { monsters = {}; player = new Player; }
	~GameManager()
	{
		for (int i = 0; i < monsters.size(); i++)
		{
			delete monsters[i];
		}

		for (int i = 0; i < shops.size(); i++)
		{
			delete shops[i];
		}
		delete player;
	}

	void SetMonsters(int level)
	{
		this->monsters = { new Goblin(level), new Orc(level), new Troll(level), new Slime(level) };
	}

	void UsingItemWithProbability(int probability, vector<Item*> playerItems, Character* character)
	{
		if (ProbabilityCheck(50))
		{
			cout << "아이템" << RandomItemFromVector(playerItems)->getName() << "사용!" << endl;
			player->useItem(RandomItemFromVector(playerItems));
		}
	}

	void isPlayerWinAtCombat()
	{
		SetMonsters(player->getLevel());
		Monster* monster = RandomItemFromVector(monsters);
		while (true)
		{
			monster->showInfo();

			DealDamage(player, monster);
			if (monster->getHealth() <= 0)
			{
				cout << monster->getName() << "을(를) " << "쓰러뜨렸습니다!!" << endl << endl;
				SetResultAfterCombat(monster);
				break;
			}

			DealDamage(monster, player);
			if (player->getHealth() <= 0)
			{
				cout << monster->getName() << "에게 사망했습니다..." << endl;
				Defeat();
				break;
			}
			else
			{
				UsingItemWithProbability(70, player->getInventory(), player);
			}
		}
	}

	void  SetResultAfterCombat(Monster* monster)
	{
		int xp = 50;
		int gold = randomInRange(10, 20);
		player->gainXP(xp);
		cout << "Xp을 " << xp << "만큼 획득했습니다" << endl;
		player->modifyGold(gold);
		cout << "골드를 " << gold << "만큼 획득했습니다" << endl;

		player->showStatus();

		VisitAtShop();
	}

	void DealDamage(Character* attacker, Character* victim)
	{
		victim->takeDamage(attacker->getDamage());
		cout << attacker->getName() << "이(가) " << victim->getName() << "에게 " << attacker->getDamage() << "만큼 데미지를 입혔습니다!!" << endl;
	}

	void VisitAtShop()
	{
		if (ProbabilityCheck(30))
		{
			shops[1]->Shopping(player);

		}
		else
		{
			shops[0]->Shopping(player);
		}
	}



	void Defeat()
	{
		cout << "당신은 패배했습니다..." << endl;
	}

	void startGame()
	{
		srand(static_cast<unsigned int>(time(0)));

		string playerName;

		while (true)
		{
			cout << "캐릭터 이름을 입력하세요: ";
			getline(cin, playerName);
			if (playerName.find(' ') != string::npos)
			{
				cout << "이름에 공백을 포함할 수 없습니다. 다시 입력해 주세요: ";
			}
			else
			{
				break;
			}
		}
		this->player->setName(playerName);

		cout << "캐릭터 " << this->player->getName() << " 생성 완료! 레벨: " << this->player->getLevel() << ", 체력: " << player->getHealth() << ", 공격력: " << player->getDamage() << endl << endl;

		while (true) {
			isPlayerWinAtCombat();
			if (player->getHealth() < 0)
			{
				break;
			}
		}
	}
};