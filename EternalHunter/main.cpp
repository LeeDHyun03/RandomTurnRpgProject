#include "main.h"

using namespace std;

// 게임 시작 함수 정의
void startGame() {
    // 게임 매니저에서 게임 시작을 호출합니다.
    GameManager::startGame();
}

int main() {
    // 랜덤 시드 초기화
    srand(static_cast<unsigned int>(time(0)));

    // 게임 시작
    startGame();

    return 0;
}
