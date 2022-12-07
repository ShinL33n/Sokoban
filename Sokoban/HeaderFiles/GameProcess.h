#pragma once
#include "GameLogic.h"
#include "MapHandler.h"
#include "MenuHandler.h"

class GameProcess
{
private:
	int _levelCount;

	short EnteredNumber();

	void GameSequence(MapHandler &map, GameLogic &game, MenuHandler &menu);

	void Win();
	void Lost();


public:
	GameProcess();
	~GameProcess();

	int GameHandler();

};