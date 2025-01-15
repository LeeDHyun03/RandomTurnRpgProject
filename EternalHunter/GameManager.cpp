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
		Sleep(1000);
		DealDamage(player, monster);
		Sleep(1000);
		if (isDieCheck(monster)) return;
		DealDamage(monster, player);
		Sleep(1000);
		if (isDieCheck(monster)) return;
		UsingItemWithProbability(70, player);
		//system("cls");
		monster->showInfo();
	}
}

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
	Sleep(1000);
	cout << "Xp�� " << xp << "��ŭ ȹ���߽��ϴ�" << endl;
	player->modifyGold(gold);
	Sleep(1000);
	cout << "��带 " << gold << "��ŭ ȹ���߽��ϴ�" << endl;
	Sleep(1000);
	player->showStatus();
}

void GameManager::DealDamage(Character* attacker, Character* victim)
{
	int damage = attacker->getDamage();
	//ũ��Ƽ�� Ȯ��
	if (ProbabilityCheck(10))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0 << 4);
		cout << attacker->getName() << "��(��) " << victim->getName() << "���� ������ ������ �����մϴ�!!!" << endl;
		Sleep(1000);
		damage *= 2;
	}
	//�ݻ�
	if (ProbabilityCheck(1))
	{
		cout << victim->getName() << "��(��) " << attacker->getName() << "�� ������ �ݻ��߽��ϴ�!!!!!!!!!" << endl;
		Sleep(1000);
		cout << victim->getName() << "��(��) " << attacker->getName() << "���� " << damage << "��ŭ �������� �������ϴ�!!!!!!" << endl;
		cout << "����ϱ���!!!\n";
		attacker->takeDamage(damage);
		return;
	}
	else
	{
		//������� ȸ��
		if (ProbabilityCheck(10))
		{
			cout << victim->getName() << "��(��) " << attacker->getName() << "�� ������ ���߽��ϴ�!!" << endl;
		}
		else
		{
			//�ݰ�
			if (ProbabilityCheck(10))
			{
				cout << victim->getName() << "��(��) " << attacker->getName() << "�� ������ ���ܳ������ϴ�!!" << endl;
				damage /= 2;
			}
			victim->takeDamage(damage);
			cout << attacker->getName() << "��(��) " << victim->getName() << "���� " << damage << "��ŭ �������� �������ϴ�!!" << endl;
		}
	}
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