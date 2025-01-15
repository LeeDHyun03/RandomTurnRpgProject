#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

Inventory::~Inventory() {
    // ������ �޸� ����
    for (Item* item : items) {
        delete item;
    }
}

void Inventory::addItem(UseItem* item) {
    items.push_back(item);  // �������� ���Ϳ� �߰�
}

void Inventory::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        delete items[index];  // ������ �޸� ����
        items.erase(items.begin() + index);  // �ε����� �ش��ϴ� ������ ����
    }
}

void Inventory::showItems() const {
    if (items.empty()) {
        std::cout << "���� ������ �������� �����ϴ�.\n";
    }
    else {
        for (int i = 0; i < items.size(); i++) {
            std::cout << i << ": " << items[i]->getName() << " (����: " << items[i]->getPrice() << "���)\n";
        }
    }
}

UseItem* Inventory::getItem(int index) const {
    if (index >= 0 && index < items.size()) {
        return items[index];
    }
    return nullptr;
}

int Inventory::getSize() const {
    return items.size();  // ������ ������ ��ȯ
}