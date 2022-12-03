#include <iostream>
#include "HeaderFiles/MenuHandler.h"
#include "HeaderFiles/MapHandler.h"
#include "HeaderFiles/GameLogic.h"

int main()
{
	MenuHandler::DisplayMainMenu();
	MenuHandler menu;
	
	
	//if(gra == w trakcie menuType = pause) else menuType = main

	//menuType = MenuHandler::DisplayedMenuType::main;

	//int opt = menu.SelectedOption(menuType);


	//std::cout << opt;
	int tmp;
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(64, '\n');


	MapHandler map(2);
	map.DisplayMap();

	GameLogic gm;
	gm.ActionHandler(map);

    return 0;
}