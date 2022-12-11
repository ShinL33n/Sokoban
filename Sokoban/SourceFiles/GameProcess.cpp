#include <iostream>
#include <fstream>
#include "../HeaderFiles/GameProcess.h"

using namespace std;

GameProcess::GameProcess()
{
	_accessibleLevels = 1;
	_selectedLevel = 1;
}

GameProcess::~GameProcess()
{

}

int GameProcess::GameHandler()
{
	MenuHandler menu;
	MapHandler map;
	GameLogic* game = new GameLogic(_selectedLevel);;

	short option;
	_levelCount = map.NumberOfLevels();

	fstream fs("ResourceFiles/progress/levelsCompleted.txt", ios::in | ios::out);
	//fstream fs("../../Sokoban/ResourceFiles/progress/levelsCompleted.txt", ios::in | ios::out);

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
				_selectedLevel = EnteredNumber();

				fs.clear();
				fs.seekg(0);

				if (fs.good())
					fs >> _accessibleLevels;
				else
					cout << "Blad w odczytywaniu postepu";

				fs.clear();
				fs.seekg(0);

				if (_selectedLevel <= _accessibleLevels) {

					map.LoadMap(_selectedLevel);
					//game = new GameLogic(_selectedLevel);
					GameSequence(map, game, menu, fs);
				}
				else {

					cout << "\033[96;40mUkoncz poprzednie poziomy, aby miec mozliwosc zagrania tego!\033[0m" << endl;
					system("pause");
				}
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
				//game = new GameLogic(_selectedLevel);
				GameSequence(map, game, menu, fs);
				break;

			case 2:
				menu.menuType = menu.main;
				map.LoadMap(_selectedLevel);
				//game = new GameLogic(_selectedLevel);
				GameSequence(map, game, menu, fs);
				break;

			case 3:
				menu.menuType = menu.main;
				break;

			case 4:
				return 0;
			}
		}
	}

	delete game;
	fs.close();
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

void GameProcess::GameSequence(MapHandler &map, GameLogic *game, MenuHandler &menu, fstream &fs)
{	
	game = new GameLogic(_selectedLevel);

	while (map.gS == map.game) {
		map.DisplayMap();
		(*game).ActionHandler(map, menu);
		//}

		if (map.gS == map.win) {

			map.gS = map.game;

			Win();

			if (fs.good()) {
				if (_selectedLevel >= _accessibleLevels)
					fs << ++_selectedLevel;
			}
			else {
				cout << "Nie udalo sie zapisac postepu." << endl;
				system("pause");
			}

			map.LoadMap(_selectedLevel);
			game = new GameLogic(_selectedLevel);
		}

		else if (map.gS == map.lost) {

			map.gS = map.game;
			Lost();
			map.LoadMap(_selectedLevel);
			game = new GameLogic(_selectedLevel);
		}
	}

	//map.gS = map.game;

}

void GameProcess::Win()
{
	MenuHandler::DisplayWinScreen();

	system("pause");
}

void GameProcess::Lost()
{
	MenuHandler::DisplayLostScreen();

	system("pause");
}

