#include "main.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>

#pragma comment(lib, "winmm.lib")

using namespace std;


int main() {
    

    srand(time(NULL));

    GameManager gm;
    
    gm.StartGame();
   
    
   

    return 0;
}
