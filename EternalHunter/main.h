#pragma once
#include "gameManager.h"


int main()
{
	GameManager* gm = new GameManager;
	cout << "ĳ���� �̸��� �Է��ϼ���. : ";
	string name;
	getline(cin, name);
	gm->player.setName(name);





	delete gm;
}


