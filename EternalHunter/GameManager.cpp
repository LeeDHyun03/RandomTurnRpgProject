#include "gameManager.h"

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

void GameManager::UsingItemWithProbability(int probability, vector<Item*> playerItems, Character* character)
{
	if (ProbabilityCheck(50))
	{
		if (player->getInventory().empty()) return;
		Item* randomItem = RandomItemFromVector(playerItems);
		cout << "아이템" << randomItem->getName() << "사용!" << endl;
		player->useItem(randomItem);
		delete randomItem;
	}
}

void GameManager::IsPlayerWinAtCombat()
{
	SetMonsters(player->getLevel());
	Monster* monster = RandomItemFromVector(monsters);
	monster->FirstShowInfo();
	while (true)
	{
		DealDamage(player, monster);
		if (isDieCheck(monster)) return;
		DealDamage(monster, player);
		if (isDieCheck(monster)) return;

		monster->showInfo();
	}
}
bool GameManager::isDieCheck(Monster* monster)
{
	if (monster->getHealth() <= 0)
	{
		cout << monster->getName() << "을(를) " << "쓰러뜨렸습니다!!" << endl << endl;
		SetResultAfterCombat(monster);
		return true;
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
	int xp = 50;
	int gold = randomInRange(10, 20);
	player->gainXP(xp);
	cout << "Xp을 " << xp << "만큼 획득했습니다" << endl;
	player->modifyGold(gold);
	cout << "골드를 " << gold << "만큼 획득했습니다" << endl;

	player->showStatus();
}

void GameManager::DealDamage(Character* attacker, Character* victim)
{
	int damage = attacker->getDamage();
	//크리티컬 확률
	if (ProbabilityCheck(10))
	{
		cout << attacker->getName() << "이(가) " << victim->getName() << "에게 강력한 공격을 선사합니다!!!" << endl;
		damage *= 2;
	}
	//반사
	if (ProbabilityCheck(1))
	{
		cout << victim->getName() << "이(가) " << attacker->getName() << "의 공격을 반사했습니다!!!!!!!!!" << endl;
		cout << victim->getName() << "이(가) " << attacker->getName() << "에게 " << damage << "만큼 데미지를 입혔습니다!!!!!!" << endl;
		cout << "대단하군요!!!\n";
		attacker->takeDamage(damage);
		return;
	}
	else
	{
		//방어자의 회피
		if (ProbabilityCheck(10))
		{
			cout << victim->getName() << "이(가) " << attacker->getName() << "의 공격을 피했습니다!!" << endl;
		}
		else
		{
			//반감
			if (ProbabilityCheck(10))
			{
				cout << victim->getName() << "이(가) " << attacker->getName() << "의 공격을 빗겨나갔습니다!!" << endl;
				damage /= 2;
			}
			victim->takeDamage(damage);
			cout << attacker->getName() << "이(가) " << victim->getName() << "에게 " << damage << "만큼 데미지를 입혔습니다!!" << endl;
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
	cout << "당신은 패배했습니다..." << endl;
}

void GameManager::StartGame()
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