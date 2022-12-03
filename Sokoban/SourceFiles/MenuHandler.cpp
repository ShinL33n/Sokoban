#include <iostream>
#include "../HeaderFiles/MenuHandler.h"

using namespace std;

MenuHandler::MenuHandler()
{
	//system("color 0B");
}

MenuHandler::~MenuHandler()
{

}

short MenuHandler::SelectedOption(DisplayedMenuType MenuType)
{
	short enteredOption;
	bool isEnteredOptionValid = false;

	do {
		while (!(std::cin >> enteredOption)) {
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
			cout << "Error w wy�wietlaniu menu!\n";
		}

		if(!isEnteredOptionValid) cout << "Wybierz poprawny numer!\n";

	} while (!isEnteredOptionValid);

	return enteredOption;
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
	for (int i = 0; i < 75; i++) cout << char(205);
	cout << char(185) << endl;
	cout << char(186) << "									    " << char(186) << endl;
};

void MenuHandler::DisplayMainMenu()
{
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
	DisplaySokobanLogo();
	cout << "\033[36;40m" << char(186) << "\033[96;40m				  PAUSE MENU		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "				     " << char(196) << char(196) << char(196) << char(196) << "				    " << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      1. Rozpocznij od nowa			    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      2. Wybierz poziom		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      3. Wyjdz do menu		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "\033[96;40m			      4. Wyjdz z gry		  		    " << "\033[36;40m" << char(186) << endl;
	cout << "\033[36;40m" << char(186) << "									    " << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 75; i++) cout << char(205);
	cout << char(188) << endl;
	cout << "\033[97;40m";
};