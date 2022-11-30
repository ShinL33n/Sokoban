#pragma once

class MenuHandler
{
private:
	int _mainMenuOptionsNumber = 2;
	int _pauseMenuOptionsNumber = 4;

	static void DisplaySokobanLogo();



public:
	MenuHandler();
	~MenuHandler();

	enum DisplayedMenuType { main, pause };

	short SelectedOption(DisplayedMenuType);

	static void DisplayMainMenu();
	static void DisplayPauseMenu();
};
