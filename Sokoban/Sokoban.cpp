#include <iostream>
#include "HeaderFiles/MenuHandler.h"
#include "HeaderFiles/MapHandler.h"

int main()
{
	MenuHandler::DisplayMainMenu();
	MenuHandler menu;
	MenuHandler::DisplayedMenuType menuType = MenuHandler::DisplayedMenuType::main;
	
	//if(gra == w trakcie menuType = pause) else menuType = main

	//menuType = MenuHandler::DisplayedMenuType::main;

	int opt = menu.SelectedOption(menuType);


	std::cout << opt;

	
	//std::cout << "\033[H\033[J";

	MapHandler map;
	map.LoadMap(2);
	map.DisplayMap();

    return 0;
}