#pragma once

class MenuHandler
{
private:
	const int _mainMenuOptionsNumber = 2;
	const int _pauseMenuOptionsNumber = 4;

	static void DisplaySokobanLogo();


public:
	MenuHandler();
	~MenuHandler();

	enum displayedMenuType { main, pause };

	displayedMenuType menuType;

	short SelectedOption(displayedMenuType);

	static void DisplayMainMenu();
	static void DisplayPauseMenu();
	static void DisplayWinScreen();
	static void DisplayLostScreen();
	static void DisplayByeScreen();

	void DisplayLevels(int lntevelsCount);
};
