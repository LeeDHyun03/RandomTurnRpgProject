#include "item.h"
#include "monster.h"
#include "player.h"
#include "Shop.h"
#include <vector>

using namespace std;

template <typename T>
T RandomItemFromVector(const std::vector<T>& vec)
{
	if (vec.empty())
	{
		throw std::runtime_error("Vector is empty.");
	}
	srand(time(NULL));
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
	Player player;
	GameManager() {}
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
	}
	
	void UsingItemWithProbability(int probability, vector<Item*> playerItems, Character* character)
	{
		if (ProbabilityCheck(50))
		{
			cout << "������" << RandomItemFromVector(playerItems)->getName() << "���!" << endl;
			RandomItemFromVector(playerItems)->use(character);
		}
	}

	bool isPlayerWinAtCombat() 
	{
		Monster monster = *RandomItemFromVector(monsters);
		while (true)
		{
			DealDamage(player, monster);
			if (monster.getHealth() <= 0)
			{
				cout << monster.getName() << "�� " << "�����߷Ƚ��ϴ�!!" << endl;
				return true;
			}
			DealDamage(monster, player);
			if (player.getHealth() <= 0)
			{
				cout << monster.getName() << "���� ����߽��ϴ�..." << endl;
				return false;
			}
			else
			{
				UsingItemWithProbability(70, player.getInventory(), &player);
			}
		}
	}

	void GetItemWithProbability(int Probability, Monster* monster)
	{
		if (ProbabilityCheck(30))
		{
			player.getInventory().push_back(RandomItemFromVector(monster->getInventory()));
		}
	}

	void  SetResultAfterCombat()
	{
		if (isPlayerWinAtCombat())
		{
			int xp = 50;
			int gold = randomInRange(10, 20);
			player.gainXP(xp);
			cout << "Xp�� " << xp << "��ŭ ȹ���߽��ϴ�" << endl;
			player.modifyGold(gold);
			cout << "��带 " << gold << "��ŭ ȹ���߽��ϴ�" << endl;
			VisitAtShop();
		}
		else
		{
			Defeat();
		}
	}
	
	void DealDamage(Character attacker, Character victim)
	{
		victim.takeDamage(attacker.getDamage());
		cout << attacker.getName() << "��(��) " << victim.getName() << "����" << attacker.getDamage() << "��ŭ �������� �������ϴ�!!" << endl;
	}

	void VisitAtShop()
	{
		if (ProbabilityCheck(30))
		{
			shops[1]->Shopping(&player);
			
		}
		else
		{
			shops[0]->Shopping(&player);
		}
	}

	

	void Defeat()
	{
		cout << "����� �й��߽��ϴ�..." << endl;
	}
};