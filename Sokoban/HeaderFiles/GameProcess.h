#pragma once
#include "GameLogic.h"
#include "MapHandler.h"
#include "MenuHandler.h"

class GameProcess
{
private:
	short _levelCount;
	short _accessibleLevels;
	short _selectedLevel;

	short EnteredNumber();

	void GameSequence(MapHandler &map, GameLogic *game, MenuHandler &menu, std::fstream &fs);

	void Win();
	void Lost();


public:
	GameProcess();
	~GameProcess();

	int GameHandler();

};