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
			cout << "������" << RandomItemFromVector(playerItems)->getName() << "���!" << endl;
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
				cout << monster->getName() << "��(��) " << "�����߷Ƚ��ϴ�!!" << endl << endl;
				SetResultAfterCombat(monster);
				break;
			}

			DealDamage(monster, player);
			if (player->getHealth() <= 0)
			{
				cout << monster->getName() << "���� ����߽��ϴ�..." << endl;
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
		cout << "Xp�� " << xp << "��ŭ ȹ���߽��ϴ�" << endl;
		player->modifyGold(gold);
		cout << "��带 " << gold << "��ŭ ȹ���߽��ϴ�" << endl;

		player->showStatus();

		VisitAtShop();
	}

	void DealDamage(Character* attacker, Character* victim)
	{
		victim->takeDamage(attacker->getDamage());
		cout << attacker->getName() << "��(��) " << victim->getName() << "���� " << attacker->getDamage() << "��ŭ �������� �������ϴ�!!" << endl;
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
		cout << "����� �й��߽��ϴ�..." << endl;
	}

	void startGame()
	{
		srand(static_cast<unsigned int>(time(0)));

		string playerName;

		while (true)
		{
			cout << "ĳ���� �̸��� �Է��ϼ���: ";
			getline(cin, playerName);
			if (playerName.find(' ') != string::npos)
			{
				cout << "�̸��� ������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���: ";
			}
			else
			{
				break;
			}
		}
		this->player->setName(playerName);

		cout << "ĳ���� " << this->player->getName() << " ���� �Ϸ�! ����: " << this->player->getLevel() << ", ü��: " << player->getHealth() << ", ���ݷ�: " << player->getDamage() << endl << endl;

		while (true) {
			isPlayerWinAtCombat();
			if (player->getHealth() < 0)
			{
				break;
			}
		}
	}
};