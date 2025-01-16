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
		if (player->getInventory().getSize() == 0)
		{
			return;
		}
		int i = player->getInventory().getSize();
		int index = randomInRange(0, i - 1);
		UseItem* randomItem = player->getInventory().getItem(index);
		randomItem->itemUse(character);
		if (randomItem->getIsActivate()) activateItems.push_back(randomItem->clone());
		cout << "������" << randomItem->getName() << "���!" << endl;

		player->removeItemFromInventory(index);

	}
}

void GameManager::IsPlayerWinAtCombat()
{
	isBattle = true;
	SetMonsters(player->getLevel());
	Monster* monster = RandomItemFromVector(monsters);
	monster->firstShowInfo();
	while (true)
	{
		DeactivateItem();
		Sleep(1000);
		DealDamage(player, monster);
		Sleep(1000);
		if (isDieCheck(monster)) return;
		DealDamage(monster, player);
		Sleep(1000);
		if (isDieCheck(monster)) return;
		UsingItemWithProbability(100, player);
		monster->showInfo();
		player->showInfoBattle();
	}
}

bool GameManager::isDieCheck(Monster* monster)
{
	if (monster->getHealth() <= 0)
	{
		cout << "\n" << monster->getlastWord() << "\n" << endl;
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
	isBattle = false;
	DeactivateItem();
	int xp = 50;
	int gold = randomInRange(10, 20);
	player->modifyGold(gold);
	player->gainXP(xp);
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | 0 << 4);
	cout << "Xp�� " << xp << "��ŭ ȹ���߽��ϴ�" << endl;
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 0 << 4);
	cout << "��带 " << gold << "��ŭ ȹ���߽��ϴ�" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
	Sleep(1000);
	player->showInfo();
}

void GameManager::DealDamage(Character* attacker, Character* victim)
{
	int damage = attacker->getCharacterDamage();
	//ũ��Ƽ�� Ȯ��
	if (ProbabilityCheck(10))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0 << 4);
		cout << attacker->getName() << "��(��) " << victim->getName() << "���� ������ ������ �����մϴ�!!!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		Sleep(1000);
		damage *= 2;
	}
	//�ݻ�
	if (ProbabilityCheck(1))
	{
		cout << victim->getName() << "��(��) " << attacker->getName() << "�� ������ �ݻ��߽��ϴ�!!!!!!!!!" << endl;
		Sleep(1000);
		cout << victim->getName() << "��(��) " << attacker->getName() << "���� ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0 << 4);
		cout << damage;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		cout << "��ŭ �������� �������ϴ�!!" << endl;
		cout << "����ϱ���!!!\n\n";
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
			cout << attacker->getName() << "��(��) " << victim->getName() << "���� "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0 << 4);
			cout << damage;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
			cout << "��ŭ �������� �������ϴ�!!\n" << endl;
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

void GameManager::DeactivateItem()
{
	if (activateItems.empty()) return;
	for (int i = 0; i < activateItems.size(); i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | 0 << 4);
		cout << "\n������ ������: " << activateItems[i]->getActivateTurn() << "|| ���ӵ� ��: " << activateItems[i]->getCurrentctivateTurn() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		if (activateItems[i]->getActivateTurn() <= activateItems[i]->getCurrentctivateTurn() || !isBattle)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | 0 << 4);
			cout << activateItems[i]->getName() << "�� ��� ȿ���� �������ϴ�..\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
			activateItems[i]->DeactivateItem(player);
			activateItems[i]->PoolItem();
			activateItems.erase(activateItems.begin() + i);
			return;
		}
		activateItems[i]->modifyActivateTurn(1);
	}
}



void GameManager::Defeat()
{
	cout << "����� �й��߽��ϴ�..." << endl;
}

void GameManager::StartGame()
{
	srand(static_cast<unsigned int>(time(0)));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
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