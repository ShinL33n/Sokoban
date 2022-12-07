#include <iostream>
#include "../HeaderFiles/GameProcess.h"

using namespace std;

GameProcess::GameProcess()
{

}

GameProcess::~GameProcess()
{

}

int GameProcess::GameHandler()
{
	MenuHandler menu;
	MapHandler map;
	GameLogic game;

	short selectedLevel = 1;
	short option;
	_levelCount = map.NumberOfLevels();

	while (true) {
		if (menu.menuType == menu.main)
			MenuHandler::DisplayMainMenu();
		else
			MenuHandler::DisplayPauseMenu();


		if (map.gS == map.menu) map.gS = map.game;

		option = menu.SelectedOption(menu.menuType);


		if (menu.menuType == menu.main) {

			switch (option)
			{
			case 1:
				menu.DisplayLevels(_levelCount);
				selectedLevel = EnteredNumber();
				map.LoadMap(selectedLevel);

				GameSequence(map, game, menu);

				break;
			case 2:
				return 0;
			}
		}
		else if (menu.menuType == menu.pause) {

			switch (option)
			{
			case 1:
				menu.menuType = menu.main;
				GameSequence(map, game, menu);
				break;
			case 2:
				menu.menuType = menu.main;
				map.LoadMap(selectedLevel);
				GameSequence(map, game, menu);
				break;
			case 3:
				menu.menuType = menu.main;
				break;
			case 4:
				return 0;
			}
		}
	}
}

short GameProcess::EnteredNumber()
{
	short enteredOption;
	bool isEnteredOptionValid = false;

	do {
		while (!(cin >> enteredOption)) {
			cin.clear();
			cin.ignore(64, '\n');
			cerr << "Wpisz podany wyzej numer poziomu!\n";
		}

		if (enteredOption > 0 && enteredOption <= _levelCount)
			isEnteredOptionValid = true;
		

		if (!isEnteredOptionValid)
			cout << "Wybierz poprawny poziom!!\n";

	} while (!isEnteredOptionValid);

	return enteredOption;
}

void GameProcess::GameSequence(MapHandler &map, GameLogic &game, MenuHandler &menu)
{
	while (map.gS == map.game) {
		map.DisplayMap();
		game.ActionHandler(map, menu);
	}

	if (map.gS == map.win) {
		map.gS = map.game;
		Win();
	}
	else if (map.gS == map.lost) {
		map.gS = map.game;
		Lost();
	}
}

void GameProcess::Win()
{
	MenuHandler::DisplayWinScreen();

	system("pause");
}

void GameProcess::Lost()
{
	MenuHandler::DisplayWinScreen();

	system("pause");
}
