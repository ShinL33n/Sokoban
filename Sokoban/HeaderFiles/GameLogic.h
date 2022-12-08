#pragma once
#include "MapHandler.h"
#include "MenuHandler.h"

class GameLogic
{
private:
	unsigned int _numberOfMoves;

	struct _Move {
		int x;
		int y;
	};

	enum _action {
		moveForward,
		moveBackwards,
		moveLeft,
		moveRight,
		menu,
		quit,
		undo,
		redo,
		invalid,
		cameraUp,
		cameraDown,
		cameraLeft,
		cameraRight
	};

	_Move MoveVector(_action action);
	_action CalledAction();

	void MakeMove(_Move move, MapHandler &map);
	void UndoMove(MapHandler &map);
	void RedoMove(MapHandler &map);
	void DisplayNumOfMoves();

	char* SettingsPathHelper(short lvl);

	unsigned int CheckNumberOfMoves(short selectedLevel);

public:
	GameLogic(short selectedLevel);
	~GameLogic();

	void ActionHandler(MapHandler &map, MenuHandler &menuHndl);

};
