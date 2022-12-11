#include <iostream>
#include "HeaderFiles/MenuHandler.h"
#include "HeaderFiles/MapHandler.h"
#include "HeaderFiles/GameLogic.h"

#include "HeaderFiles/GameProcess.h"

int main()
{
	GameProcess gameProcess;
	gameProcess.GameHandler();


	MenuHandler::DisplayByeScreen();

    return 0;
}


//REG ADD HKCU\CONSOLE /f /v VirtualTerminalLevel /t REG_DWORD /d 1