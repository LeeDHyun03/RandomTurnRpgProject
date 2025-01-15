#pragma once
#pragma once
#pragma once
#include <vector>
#include "item.h"
#include "useItem.h"

#include <iostream>

using namespace std;

class Player;  // �÷��̾� Ŭ������ ���� (��ȯ ������ �ذ��� ����)

class Inventory {
private:
    vector<UseItem*> items;  // ������ ���� (�÷��̾ ������ ������ ���)

public:
    Inventory();  // �⺻ ������
    ~Inventory(); // �Ҹ��� (������ �޸� ����)

    void addItem(UseItem* item);  // �κ��丮�� ������ �߰�
    void removeItem(int index);  // �κ��丮���� ������ ����
    void showItems() const;  // ������ ��� ���
    UseItem* getItem(int index) const;  // ������ �ϳ� ��ȯ
    int getSize() const;  // �κ��丮 ũ�� (������ ���� ��ȯ)
};