#pragma once

class MenuHandler
{
private:
	int _mainMenuOptionsNumber = 2;
	int _pauseMenuOptionsNumber = 4;

	static void DisplaySokobanLogo();

	enum displayedMenuType { main, pause };

public:
	MenuHandler();
	~MenuHandler();


	short SelectedOption(displayedMenuType);

	static void DisplayMainMenu();
	static void DisplayPauseMenu();
};
