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
    // �⺻ ������
    Inventory();  

    // �Ҹ��� (������ �޸� ����)
    ~Inventory();

    // �κ��丮�� ������ �߰�
    void addItem(UseItem* item);

    // �κ��丮���� ������ ����
    void removeItem(int index);

    // ������ ��� ���
    void showItems() const;  

    // ������ �ϳ� ��ȯ
    UseItem* getItem(int index) const;

    // �κ��丮 ũ�� (������ ���� ��ȯ)
    int getSize() const;  
};