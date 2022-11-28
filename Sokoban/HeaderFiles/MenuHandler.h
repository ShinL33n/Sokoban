#pragma once

class MenuHandler
{
private:
	int _mainMenuOptionsNumber = 2;
	int _pauseMenuOptionsNumber = 4;


public:
	MenuHandler();

	~MenuHandler();

	enum DisplayedMenuType { main, pause};

	static void DisplaySokobanLogo();
	static void DisplayMainMenu();
	static void DisplayPauseMenu();

	short KeyboardSelection();
	short IsSelectedOptionValid(DisplayedMenuType);
	short SelectedOption(DisplayedMenuType);

};