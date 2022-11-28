#include <stdio.h>
#include <iostream>
#include "../HeaderFiles/MenuHandler.h"


MenuHandler::MenuHandler()
{

}

MenuHandler::~MenuHandler()
{

}

//enum MenuHandler::DisplayedMenuType
//{
//	main,
//	pause
//};

void MenuHandler::DisplaySokobanLogo()
{
	printf("		    ##\\                 ##\\\n");
	printf("                    ## |                ## |\n");
	printf(" #######\\  ######\\  ## |  ##\\  ######\\  #######\\   ######\\  #######\\\n");
	printf("##  _____|##  __##\\ ## | ##  |##  __##\\ ##  __##\\  \\____##\\ ##  __##\\\n");
	printf("\\######\\  ## /  ## |######  / ## /  ## |## |  ## | ####### |## |  ## |\n");
	printf(" \\____##\\ ## |  ## |##  _##<  ## |  ## |## |  ## |##  __## |## |  ## |\n");
	printf("#######  |\\######  |## | \\##\\ \\######  |#######  |\\####### |## |  ## |\n");
	printf("\\_______/  \\______/ \\__|  \\__| \\______/ \\_______/  \\_______|\\__|  \\__|\n");
};

void MenuHandler::DisplayMainMenu()
{
	DisplaySokobanLogo();
	printf("-------------------------\n");
	printf("| 1. Wybierz poziom	|\n");
	printf("| 2. Wyjdz z gry	|\n");
	printf("-------------------------\n");
};

void MenuHandler::DisplayPauseMenu()
{
	DisplaySokobanLogo();
	printf("-------------------------\n");
	printf("| 1. Rozpocznij od nowa	|\n");
	printf("| 2. Wybierz poziom	|\n");
	printf("| 3. Wyjdz do menu	|\n");
	printf("| 4. Wyjdz z gry	|\n");
	printf("-------------------------\n");
};

// Metoda sprawdzaj�ca czy wpisana w konsoli warto�� jest typu liczbowego
short MenuHandler::KeyboardSelection()
{
	short option;

	while (!(std::cin >> option)) {
		std::cin.clear();
		std::cin.ignore(64, '\n');
		std::cerr << "Wpisz podany wyzej numer opcji!" << std::endl;
	}

	return option;
}

// Metoda sprawdzaj�ca czy podana warto�� jest warto�ci� poprawn� dla danego menu (g��wnego/pauzy)
short MenuHandler::IsSelectedOptionValid(DisplayedMenuType menuType)
{
	short selectedValue = KeyboardSelection();

	switch (menuType)
	{
	case main:
		if (selectedValue > 0 && selectedValue <= _mainMenuOptionsNumber)
			return selectedValue;
		break;
	case pause:
		if (selectedValue > 0 && selectedValue <= _pauseMenuOptionsNumber)
			return selectedValue;
		break;
	default:
		printf("Error w wy�wietlaniu menu!\n");
		return -1;
		break;
	}

	return -1;
}

// Medoda zwracaj�ca zwalidowan� wybran� opcje z menu
short MenuHandler::SelectedOption(DisplayedMenuType menuType=main) {

	int selectedValue = IsSelectedOptionValid(menuType);

	while (selectedValue == -1) {
		printf("Wybierz poprawny numer!\n");
		selectedValue = IsSelectedOptionValid(menuType);
	}

	return selectedValue;

}
