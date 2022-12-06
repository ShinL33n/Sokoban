#include <iostream>
#include "HeaderFiles/MenuHandler.h"
#include "HeaderFiles/MapHandler.h"
#include "HeaderFiles/GameLogic.h"

#include "HeaderFiles/GameProcess.h"

int main()
{
	//MenuHandler::DisplayMainMenu();
	//MenuHandler menu;
	//
	//
	////if(gra == w trakcie menuType = pause) else menuType = main

	////menuType = MenuHandler::DisplayedMenuType::main;

	////int opt = menu.SelectedOption(menuType);
	////std::cout << "\033#6";

	////std::cout << opt;
	//int tmp;
	//std::cin >> tmp;
	//std::cin.clear();
	//std::cin.ignore(64, '\n');


	//MapHandler map(1);
	//GameLogic gm;

	////while (map.gS == game) {
	//	map.DisplayMap();

	//	gm.ActionHandler(map);
	////}

	GameProcess gameProcess;
	gameProcess.GameHandler();


	MenuHandler::DisplayByeScreen();

    return 0;
}