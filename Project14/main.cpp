#include "main.h"

using namespace std;

// ���� ���� �Լ� ����
void startGame() {
    // ���� �Ŵ������� ���� ������ ȣ���մϴ�.
    GameManager::startGame();
}

int main() {
    // ���� �õ� �ʱ�ȭ
    srand(static_cast<unsigned int>(time(0)));

    // ���� ����
    startGame();

    return 0;
}