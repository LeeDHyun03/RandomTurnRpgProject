#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>  // PlaySound ����� ���� �ʿ�
#pragma comment(lib, "winmm.lib")  // winmm.lib ���̺귯�� ����

int main()
{
    // ���� ���� ��� ���� (���� ��η� ����)
    const char* musicFilePath = "C:\\Users\\a3749\\RandomTurnRpgProject\\EternalHunter\\EternalHunter\\x64\\Debug\\SellBuyMusic.wav";

    // char*�� LPCWSTR�� ��ȯ (�����ڵ� ���ڿ��� ��ȯ)
    wchar_t wMusicFilePath[256];  // ��ȯ�� �����ڵ� ���ڿ��� ������ �迭

    // ������ ��ȯ �Լ� ��� (mbstowcs_s)
    size_t outSize;
    mbstowcs_s(&outSize, wMusicFilePath, sizeof(wMusicFilePath) / sizeof(wchar_t), musicFilePath, _TRUNCATE);

    // ������ �񵿱������� �ݺ� ���
    PlaySound(NULL, 0, 0);  // ���� ��� ���� �Ҹ� ����
    Sleep(1000);  // ��� ��� (1��)

    // ���� ���� ��θ� ����Ͽ� ���
    PlaySound(wMusicFilePath, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    char c[256];

    // ����� �Է��� ��ٸ��� �ݺ���
    while (1)
    {
        printf("��ɾ �Է��ϼ��� (pp�� �Է��ϸ� ����): ");
        scanf_s("%s", c, sizeof(c));  // ����� �Է� �ޱ�

        if (strcmp(c, "pp") == 0)  // "pp"�� �Է��ϸ� ����
        {
            printf("�����մϴ�.\n");
            break;  // �ݺ��� ����
        }
        else {
            printf("�Է��� ��ɾ�: %s\n", c);
        }
    }

    // ���� ����
    PlaySound(NULL, 0, 0);  // ���� ����
    return 0;
}