#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

Inventory::~Inventory() {
    // 아이템 메모리 해제
    for (Item* item : items) {
        delete item;
    }
}

void Inventory::addItem(Item* item) {
    items.push_back(item);  // 아이템을 벡터에 추가
}

void Inventory::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        delete items[index];  // 아이템 메모리 해제
        items.erase(items.begin() + index);  // 인덱스에 해당하는 아이템 제거
    }
}

void Inventory::showItems() const {
    if (items.empty()) {
        std::cout << "현재 보유한 아이템이 없습니다.\n";
    }
    else {
        for (int i = 0; i < items.size(); i++) {
            std::cout << i << ": " << items[i]->getName() << " (가격: " << items[i]->getPrice() << "골드)\n";
        }
    }
}

Item* Inventory::getItem(int index) const {
    if (index >= 0 && index < items.size()) {
        return items[index];
    }
    return nullptr;
}

int Inventory::getSize() const {
    return items.size();  // 아이템 개수를 반환
}