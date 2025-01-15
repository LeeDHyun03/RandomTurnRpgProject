#pragma once
#pragma once
#pragma once
#include <vector>
#include "item.h"

#include <iostream>

using namespace std;

class Player;  // �÷��̾� Ŭ������ ���� (��ȯ ������ �ذ��� ����)

class Inventory {
private:
    vector<Item*> items;  // ������ ���� (�÷��̾ ������ ������ ���)

public:
    Inventory();  // �⺻ ������
    ~Inventory(); // �Ҹ��� (������ �޸� ����)

    void addItem(Item* item);  // �κ��丮�� ������ �߰�
    void removeItem(int index);  // �κ��丮���� ������ ����
    void showItems() const;  // ������ ��� ���
    Item* getItem(int index) const;  // ������ �ϳ� ��ȯ
    int getSize() const;  // �κ��丮 ũ�� (������ ���� ��ȯ)
};