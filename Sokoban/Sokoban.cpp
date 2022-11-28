#include <iostream>
#include "HeaderFiles/MenuHandler.h"


int main()
{
	MenuHandler::DisplayMainMenu();
	MenuHandler menu;
	MenuHandler::DisplayedMenuType menuType = MenuHandler::DisplayedMenuType::main;
	
	//if(gra == w trakcie menuType = pause) else menuType = main

	//menuType = MenuHandler::DisplayedMenuType::main;

	int opt = menu.SelectedOption(menuType);

	std::cout << opt;

    return 0;
}