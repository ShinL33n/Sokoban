#include <iostream>
#include "../HeaderFiles/MenuHandler.h"

using namespace std;

MenuHandler::MenuHandler()
{
	menuType = main;
}

MenuHandler::~MenuHandler()
{

}

short MenuHandler::SelectedOption(displayedMenuType MenuType)
{
	short enteredOption;
	bool isEnteredOptionValid = false;

	do {
		while (!(cin >> enteredOption)) {
			cin.clear();
			cin.ignore(64, '\n');
			cerr << "Wpisz podany wyzej numer opcji!\n";
		}

		if (MenuType == main) {
			isEnteredOptionValid = (enteredOption > 0 && enteredOption <= _mainMenuOptionsNumber) ? true : false;
		}
		else if (MenuType == pause) {
			isEnteredOptionValid = (enteredOption > 0 && enteredOption <= _pauseMenuOptionsNumber) ? true : false;
		}
		else {
			cout << "Error w wyœwietlaniu menu!\n";
		}

		if(!isEnteredOptionValid) cout << "Wybierz poprawny numer!\n";

	} while (!isEnteredOptionValid);

	return enteredOption;
}

void MenuHandler::DisplayLevels(int levelsCount)
{
	cout << "\033[H\033[J";
	cout << "\033[36;40m";
	cout << char(201);
	for (int i = 0; i < 7; i++) cout << char(205);
	cout << "\033[96;40m Wybierz Poziom \033[36;40m";
	for (int i = 0; i < 7; i++) cout << char(205);
	cout << char(187) << endl;

	cout << "\033[36;40m" << char(186) << "\033[96;40m			       " << "\033[36;40m" << char(186) << endl;

	for (int i = 0; i < levelsCount; i++) {
		cout << "\033[36;40m" << char(186) << "	   " << char(175) << "\033[96;40m Poziom " << i+1 << "\033[36;40m " << char(174) << "        " << "\033[36; 40m" << char(186) << endl;
	}

	cout << "\033[36;40m" << char(186) << "\033[96;40m			       " << "\033[36;40m" << char(186) << endl;

	cout << char(200);
	for (int i = 0; i < 30; i++) cout << char(205);
	cout << char(188) << endl;
	cout << "\033[97;40m";
}

void MenuHandler::DisplaySokobanLogo()
{
	cout << "\033[36;40m";
	cout << char(201);
	for (int i = 0; i < 75; i++) cout << char(205);
	cout << char(187) << endl;
	cout << char(186) << "									    " << "\033[36;40m" << char(186) << endl;
 	cout << "\033[36;40m" << char(186) << "\033[96;40m	  	       ##\\                 ##\\				    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m                      ## |                ## |				    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m   #######\\  ######\\  ## |  ##\\  ######\\  #######\\   ######\\  #######\\     " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m  ##  _____|##  __##\\ ## | ##  |##  __##\\ ##  __##\\  \\____##\\ ##  __##\\    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m  \\######\\  ## /  ## |######  / ## /  ## |## |  ## | ####### |## |  ## |   " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m   \\____##\\ ## |  ## |##  _##<  ## |  ## |## |  ## |##  __## |## |  ## |   " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m  #######  |\\######  |## | \\##\\ \\######  |#######  |\\####### |## |  ## |   " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m  \\_______/  \\______/ \\__|  \\__| \\______/ \\_______/  \\_______|\\__|  \\__|   " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "									    " << char(186) << endl;
	cout << char(204);
	for (int i = 0; i < 23; i++) cout << char(205);
	cout << "\033[96;40m" << " Adrian Kisieli" << char(228) << "ski " << " s193086 \033[36;40m";
	for (int i = 0; i < 23; i++) cout << char(205);
	cout << char(185) << endl;
	cout << char(186) << "									    " << char(186) << endl;
};

void MenuHandler::DisplayMainMenu()
{
	cout << "\033[H\033[J";
	DisplaySokobanLogo();
	cout << "\033[36;40m" << char(186) << "\033[96;40m				  MAIN MENU		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "				     " << char(196) << char(196) << char(196) << "				    " << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      1. Wybierz poziom		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      2. Wyjdz z gry		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "									    " << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 75; i++) cout << char(205);
	cout << char(188) << endl;
	cout << "\033[97;40m";
};

void MenuHandler::DisplayPauseMenu()
{
	cout << "\033[H\033[J";
	DisplaySokobanLogo();
	cout << "\033[36;40m" << char(186) << "\033[96;40m				  PAUSE MENU		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "				     " << char(196) << char(196) << char(196) << char(196) << "				    " << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      1. Kontynuuj		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      2. Rozpocznij od nowa			    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      3. Wyjdz do menu		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      4. Wyjdz z gry		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "									    " << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 75; i++) cout << char(205);
	cout << char(188) << endl;
	cout << "\033[97;40m";
};

void MenuHandler::DisplayWinScreen()
{
	cout << "\033[H\033[J";
	cout << "\033[36;40m";
	cout << char(201);
	for (int i = 0; i < 45; i++) cout << char(205);
	cout << char(187) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m                                       _     " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m  __ __ ___  _ __ _ _ _ __ _ _ _  __ _| |    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m  \\ V  V / || / _` | '_/ _` | ' \\/ _` |_|    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m   \\_/\\_/ \\_, \\__, |_| \\__,_|_||_\\__,_(_)    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m          |__/|___/			      " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "					      " << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 45; i++) cout << char(205);
	cout << char(188) << endl;
	cout << "\033[97;40m";
};

void MenuHandler::DisplayLostScreen()
{
	cout << "\033[H\033[J";
	cout << "\033[36;40m";
	cout << char(201);
	for (int i = 0; i < 45; i++) cout << char(205);
	cout << char(187) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m                                          _  " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m  _ __ _ _ ______ __ _ _ _ __ _ _ _  __ _| | " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m | '_ \\ '_|_ / -_) _` | '_/ _` | ' \\/ _` |_| " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m | .__/_| /__\\___\\__, |_| \\__,_|_||_\\__,_(_) " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m |_|             |___/			      " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "					      " << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 45; i++) cout << char(205);
	cout << char(188) << endl;
	cout << "\033[97;40m";
};

void MenuHandler::DisplayByeScreen()
{
	cout << "\033[H\033[J";
	cout << "\033[36;40m";
	cout << char(201);
	for (int i = 0; i < 40; i++) cout << char(205);
	cout << char(187) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m       _                                " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m      |_|____ ___ _  _   _     _        " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m     |_  / __/ __| \\| | /_\\ _ | |       " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m      / /| _| (_|| .` |/ _ \\ || |       " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m     /___|___\\___|_|\\_/_/ \\_\\__/        " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "					 " << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 40; i++) cout << char(205);
	cout << char(188) << endl;
	cout << "\033[97;40m";
};