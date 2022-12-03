#pragma once
#include "MapHandler.h"

class GameLogic
{
private:
	//moze do usuniecia
	bool _gameState;
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
		invalid
	};

	_Move MoveVector(_action action);
	_action CalledAction();

	void WhatToDo(_action action, MapHandler map);
	void MakeMove(_Move move, MapHandler map);
	void UndoMove();
	void RedoMove();
	/*void ApplyMoveToArr(int x, int y);
	void MoveMapChange();
	void MoveChest(int x, int y);

	bool IsThereAWall(int x, int y);
	bool IsThereAChest(int x, int y);*/

public:
	GameLogic();
	~GameLogic();

	void ActionHandler(MapHandler map);


};
