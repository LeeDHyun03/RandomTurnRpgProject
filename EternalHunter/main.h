#pragma once
#include "gameManager.h"


int main()
{
	GameManager* gm = new GameManager;
	cout << "캐릭터 이름을 입력하세요. : ";
	string name;
	getline(cin, name);
	gm->player.setName(name);





	delete gm;
}


