#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>  // PlaySound 사용을 위해 필요
#pragma comment(lib, "winmm.lib")  // winmm.lib 라이브러리 연결

int main()
{
    // 음악 파일 경로 설정 (절대 경로로 지정)
    const char* musicFilePath = "C:\\Users\\a3749\\RandomTurnRpgProject\\EternalHunter\\EternalHunter\\x64\\Debug\\SellBuyMusic.wav";

    // char*를 LPCWSTR로 변환 (유니코드 문자열로 변환)
    wchar_t wMusicFilePath[256];  // 변환된 유니코드 문자열을 저장할 배열

    // 안전한 변환 함수 사용 (mbstowcs_s)
    size_t outSize;
    mbstowcs_s(&outSize, wMusicFilePath, sizeof(wMusicFilePath) / sizeof(wchar_t), musicFilePath, _TRUNCATE);

    // 음악을 비동기적으로 반복 재생
    PlaySound(NULL, 0, 0);  // 현재 재생 중인 소리 중지
    Sleep(1000);  // 잠시 대기 (1초)

    // 음악 파일 경로를 사용하여 재생
    PlaySound(wMusicFilePath, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    char c[256];

    // 사용자 입력을 기다리는 반복문
    while (1)
    {
        printf("명령어를 입력하세요 (pp를 입력하면 종료): ");
        scanf_s("%s", c, sizeof(c));  // 사용자 입력 받기

        if (strcmp(c, "pp") == 0)  // "pp"를 입력하면 종료
        {
            printf("종료합니다.\n");
            break;  // 반복문 종료
        }
        else {
            printf("입력한 명령어: %s\n", c);
        }
    }

    // 음악 정지
    PlaySound(NULL, 0, 0);  // 음악 중지
    return 0;
}