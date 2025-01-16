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
	if (player->getLevel() == 10) {
		this->monsters = { new Dragon(level) };
	}
	else
	{
		this->monsters = { new Goblin(level), new Orc(level), new Troll(level), new Slime(level) };
	}
}

void GameManager::UsingItemWithProbability(int probability, Character* playerChar, Character* monster)
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
		for (int j = 0; j < i; j++)
		{
			if (activateItems.empty()) break;
			if (randomItem->getName() == activateItems[j]->getName())
			{
				activateItems[j]->modifyAcitvateTurn(activateItems[j]->getActivateTurn());
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 0 << 4);
				cout << randomItem->getName() << "������ ����!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
				player->removeItemFromInventory(index);
				return;
			}
		}
		if(randomItem->getPlayerTarget())randomItem->itemUse(playerChar);
		else randomItem->itemUse(monster);
		if (randomItem->getIsActivate())
			activateItems.push_back(randomItem->clone());

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 0 << 4);
		cout << "������" << randomItem->getName() << "���!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);

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
		DeactivateItem(monster);
		monster->showInfo();
		player->showInfoBattle();
		Sleep(10);
		if(DealDamage(player, monster, monster)) return;
		Sleep(10);
		if(DealDamage(monster, player, monster)) return;
		Sleep(10);
		UsingItemWithProbability(100, player, monster);
	}
}

bool GameManager::KillDragon(Monster* monster)
{
	if (dynamic_cast<Dragon*>(monster) != nullptr && monster->getHealth() <= 0)
	{
		cout << "�ٿ�������!!!!!" << endl;
		cout << "�巡���� ���� �������� ���︲�� �Ͼ�ϴ�." << endl;
		cout << "�����մϴ�!! ��� ���͸� óġ�Ͽ� " << player->getName() << "��(��) �ڽ��� ���� ������ ������ ���޾ҽ��ϴ�!" << endl;

		EndGame();
		
		return true;

	}
	return false;
}



bool GameManager::isDieCheck(Monster* monster)
{
	if (monster->getHealth() <= 0)
	{
		if (dynamic_cast<Dragon*>(monster) != nullptr)
		{
			if (KillDragon(monster))
			{
				return true;
			}
		}
		else
		{
			cout << monster->getName() << "��(��) " << "�����߷Ƚ��ϴ�!!" << endl << endl;
			SetResultAfterCombat(monster);
			return true;
		}
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
	DeactivateItem(monster);
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

bool GameManager::DealDamage(Character* attacker, Character* victim, Monster* monster)
{
	if (attacker->getIsStun())
	{
		cout << "���� �����Դϴ�..\n";
		return false;
	}
	int damage = attacker->getCharacterDamage();
	//ũ��Ƽ�� Ȯ��
	if (ProbabilityCheck(attacker->getCriticalProb()))
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
		return false;
	}
	else
	{
		//������� ȸ��
		if (ProbabilityCheck(victim->getEvasionProb()))
		{
			cout << victim->getName() << "��(��) " << attacker->getName() << "�� ������ ���߽��ϴ�!!" << endl;
		}
		else
		{
			//�ݰ�
			if (ProbabilityCheck(victim->getHalfEvasionProb()))
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
	return isDieCheck(monster);
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

void GameManager::DeactivateItem(Monster* monster)
{
	if (activateItems.empty()) return;
	for (int i = 0; i < activateItems.size(); i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | 0 << 4);
		cout << "\n������: " << activateItems[i]->getName()
			<< " ���� ��: " << activateItems[i]->getActivateTurn()
			<< " || ���� ���ӵ� ��: " << activateItems[i]->getCurrentctivateTurn() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		if (activateItems[i]->getActivateTurn() <= activateItems[i]->getCurrentctivateTurn() || !isBattle)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | 0 << 4);
			cout << activateItems[i]->getName() << "�� ��� ȿ���� �������ϴ�..\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);

			if (activateItems[i]->getPlayerTarget())
				activateItems[i]->DeactivateItem(player);
			else
				activateItems[i]->DeactivateItem(monster);

			// ������ Ǯ�� �������� ���Ϳ��� ����
			activateItems[i]->PoolItem();
			activateItems.erase(activateItems.begin() + i);
			i--;
		}
		else
		{
			activateItems[i]->modifyCurrentActivateTurn(1);
		}
	}
}

void GameManager::Defeat()
{
	cout << "����� �й��߽��ϴ�..." << endl;
}

void GameManager::EndGame()
{
	cout << "������ �����մϴ�." << endl;
}

//�����
void GameManager::PlaySimpleSound()
{
#define bgm "C:\\Users\\KimJH\\RandomTurnRpgProject\\EternalHunter\\Sound\\player.wav"
	
	PlaySound(TEXT(bgm), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

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

