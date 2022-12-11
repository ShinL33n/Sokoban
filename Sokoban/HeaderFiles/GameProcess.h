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


	void GameSequence(MapHandler &map, GameLogic *game, MenuHandler &menu, std::fstream &fs);
	void Win();
	void Lost();

	short EnteredNumber();


public:
	GameProcess();
	~GameProcess();

	// Niesko�czona p�tla menu gry zawieraj�ca wszystkie
	// dost�pne opcje oferowane przez program.
	int GameHandler();
};