#include "gameManager.h"
#include <ctime>

GameManager::GameManager() { monsters = {}; player = new Player; }
GameManager::~GameManager()
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

void GameManager::SetMonsters(int level)
{
	this->monsters = { new Goblin(level), new Orc(level), new Troll(level), new Slime(level) };
}

void GameManager::UsingItemWithProbability(int probability, Character* character)
{
	if (ProbabilityCheck(probability))
	{
		if (player->getInventory().empty())
		{
			cout << "�κ��丮�� �� �������� ����� �� �����ϴ�..." << endl;
			return;
		}
		int i = player->getInventory().size();
		int index = randomInRange(0, i);
		Item* randomItem = player->getInventory()[index];
		cout << "������" << randomItem->getName() << "���!" << endl;
		player->useItem(randomItem);
		player->removeItemFromPlayerInventory(index);
	}
}

void GameManager::IsPlayerWinAtCombat()
{
	SetMonsters(player->getLevel());
	Monster* monster = RandomItemFromVector(monsters);
	monster->firstShowInfo();
	while (true)
	{
		monster->showInfo();

bool GameManager::isDieCheck(Monster* monster)
{
	if (monster->getHealth() <= 0)
	{
		cout << monster->getName() << "��(��) " << "�����߷Ƚ��ϴ�!!" << endl << endl;
		SetResultAfterCombat(monster);
		return true;
	}
	if (player->getHealth() <= 0)
	{
		cout << monster->getName() << "���� ����߽��ϴ�..." << endl;
		Defeat();
		return true;
	}
	return false;
}
void  GameManager::SetResultAfterCombat(Monster* monster)
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

void GameManager::DealDamage(Character* attacker, Character* victim)
{
	victim->takeDamage(attacker->getDamage());
	cout << attacker->getName() << "��(��) " << victim->getName() << "���� " << attacker->getDamage() << "��ŭ �������� �������ϴ�!!" << endl;
}

void GameManager::VisitAtShop()
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



void GameManager::Defeat()
{
	cout << "����� �й��߽��ϴ�..." << endl;
}

void GameManager::StartGame()
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
		IsPlayerWinAtCombat();
		if (player->getHealth() < 0)
		{
			break;
		}
		else
		{
			VisitAtShop();
		}
	}
}