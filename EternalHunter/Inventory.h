#pragma once
#pragma once
#pragma once
#include <vector>
#include "item.h"
#include "useItem.h"

#include <iostream>

using namespace std;

class Player;  // 플레이어 클래스의 선언 (순환 의존성 해결을 위해)

class Inventory {
private:
    vector<UseItem*> items;  // 아이템 벡터 (플레이어가 보유한 아이템 목록)

public:
    // 기본 생성자
    Inventory();  

    // 소멸자 (아이템 메모리 관리)
    ~Inventory();

    // 인벤토리에 아이템 추가
    void addItem(UseItem* item);

    // 인벤토리에서 아이템 제거
    void removeItem(int index);

    // 아이템 목록 출력
    void showItems() const;  

    // 아이템 하나 반환
    UseItem* getItem(int index) const;

    // 인벤토리 크기 (아이템 개수 반환)
    int getSize() const;  
};