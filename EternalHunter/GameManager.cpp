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
		for (int j = 0; j < activateItems.size(); j++)
		{
			if (activateItems.empty()) break;
			if (randomItem->getName() == activateItems[j]->getName())
			{
				activateItems[j]->modifyAcitvateTurn(1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 0 << 4);
				cout << randomItem->getName() << "지속턴 증가!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
				player->removeItemFromInventory(index);
				return;
			}
		}
		if(randomItem->getPlayerTarget())randomItem->itemUse(playerChar);
		else randomItem->itemUse(monster);
		if (randomItem->getIsActivate())
			activateItems.push_back(randomItem->clone());
		
		Sleep(1000);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 0 << 4);
		cout << "아이템" << randomItem->getName() << "사용!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		Sleep(1000);

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
		cout  << endl;
		Sleep(300);
		cout << "\n" << player->getName() << "의 차례!" << endl;
		if(DealDamage(player, monster, monster)) return;
		Sleep(300);
		cout << "\n" << monster->getName() << "의 차례!" << endl;
		if(DealDamage(monster, player, monster)) return;
		Sleep(300);
		cout << endl;
		UsingItemWithProbability(100, player, monster);
		cout << "아무 버튼이나 눌러 전투를 진행하세요!";
		cin >> input;
		system("cls");
	}
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
			cout << monster->getName() << "을(를) " << "쓰러뜨렸습니다!!" << endl << endl;
			SetResultAfterCombat(monster);
			return true;
		}
	}
	if (player->getHealth() <= 0)
	{
		cout << monster->getName() << "에게 사망했습니다..." << endl;
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
	cout << "Xp을 " << xp << "만큼 획득했습니다" << endl;
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 0 << 4);
	cout << "골드를 " << gold << "만큼 획득했습니다" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
	Sleep(1000);
	player->showInfo();
}
bool GameManager::DealDamage(Character* attacker, Character* victim, Monster* monster)
{
	if (attacker->getIsStun())
	{
		cout << attacker->getName() << "은 기절 상태입니다..\n";
		return false;
	}
	int damage = attacker->getCharacterDamage();
	//크리티컬
	if (ProbabilityCheck(attacker->getCriticalProb()))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0 << 4);
		cout << attacker->getName() << "이(가) " << victim->getName() << "에게 강력한 공격을 선사합니다!!!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		Sleep(1000);
		damage *= 2;
	}
	//반사
	if (ProbabilityCheck(1))
	{
		cout << victim->getName() << "이(가) " << attacker->getName() << "의 공격을 반사했습니다!!!!!!!!!" << endl;
		Sleep(1000);
		cout << victim->getName() << "이(가) " << attacker->getName() << "에게 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0 << 4);
		cout << damage;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		cout << "만큼 데미지를 입혔습니다!!" << endl;
		cout << "대단하군요!!!\n\n";
		Sleep(1000);
		attacker->takeDamage(damage);
		return false;
	}
	else
	{
		//회피
		if (ProbabilityCheck(victim->getEvasionProb()))
		{
			cout << victim->getName() << "이(가) " << attacker->getName() << "의 공격을 피했습니다!!" << endl;
			Sleep(1000);
		}
		else
		{
			//반감
			if (ProbabilityCheck(victim->getHalfEvasionProb()))
			{
				cout << victim->getName() << "이(가) " << attacker->getName() << "의 공격을 빗겨나갔습니다!!" << endl;
				Sleep(1000);
				damage /= 2;
			}
			victim->takeDamage(damage);
			cout << attacker->getName() << "이(가) " << victim->getName() << "에게 ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0 << 4);
			cout << damage;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
			cout << "만큼 데미지를 입혔습니다!!\n" << endl;
			Sleep(1000);
		}
	}
	return isDieCheck(monster);
}


void GameManager::VisitAtShop()
{
	if (ProbabilityCheck(10))
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
		cout << "\n아이템: " << activateItems[i]->getName()
			<< " 지속 턴: " << activateItems[i]->getActivateTurn()
			<< " || 현재 지속된 턴: " << activateItems[i]->getCurrentctivateTurn() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
		if (activateItems[i]->getActivateTurn() <= activateItems[i]->getCurrentctivateTurn() || !isBattle)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | 0 << 4);
			cout << activateItems[i]->getName() << "의 사용 효과가 끝났습니다..\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);

			if (activateItems[i]->getPlayerTarget())
				activateItems[i]->DeactivateItem(player);
			else
				activateItems[i]->DeactivateItem(monster);

			// 아이템 풀로 돌려놓고 벡터에서 제거
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

bool GameManager::KillDragon(Monster* monster)
{
	if (monster->getHealth() <= 0)
	{
		cout << "꾸웨웨웽엑!!!!!" << endl;
		cout << "드래곤이 땅에 떨어지며 땅울림이 일어납니다." << endl;
		cout << "축하합니다!! 모든 몬스터를 처치하여 " << player->getName() << "은(는) 자신의 운이 나쁘지 않음을 깨달았습니다!" << endl;

		EndGame();

		return true;

	}
	return false;
}

void GameManager::EndGame()
{
	cout << "게임 끝!\n";
}

void GameManager::Defeat()
{
	cout << "당신은 패배했습니다..." << endl;
}

void GameManager::StartGame()
{
	srand(static_cast<unsigned int>(time(0)));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0 << 4);
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
		IsPlayerWinAtCombat();
		if (player->getHealth() <= 0)
		{
			break;
		}
		else
		{
			VisitAtShop();
		}
	}
}