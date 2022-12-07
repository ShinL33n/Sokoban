#include <iostream>
#include "../HeaderFiles/GameLogic.h"
#include "../HeaderFiles/GameProcess.h"
#include "../HeaderFiles/MenuHandler.h"
#include "../HeaderFiles/MapHandler.h"

using namespace std;

GameLogic::GameLogic()
{

}

GameLogic::~GameLogic()
{

}

void GameLogic::ActionHandler(MapHandler& map, MenuHandler& menuHndl)
{
	if (map.gS == map.game) {

		_action action = CalledAction();

		do {
			if (action == invalid) action = CalledAction();

			if (action == moveForward || action == moveBackwards || action == moveLeft || action == moveRight) {
				MakeMove(MoveVector(action), map);
			}
			else if (action == menu) {
				map.gS = map.menu;
				menuHndl.menuType = menuHndl.pause;
			}
			else if (action == quit) {
				map.gS = map.menu;
				menuHndl.menuType = menuHndl.main;
			}
			else if (action == undo) {
				UndoMove(map);
			}
			else if (action == redo) {
				RedoMove(map);
			}

		} while (action == invalid);
	}
}

GameLogic::_Move GameLogic::MoveVector(_action action)
{
		 if (action == moveForward)		return { 0, -1 };
	else if (action == moveBackwards)	return { 0, 1 };
	else if (action == moveLeft)		return { -1, 0 };
	else if (action == moveRight)		return { 1, 0 };
	else {
			 return { 0, 0 };
		 }
}

GameLogic::_action GameLogic::CalledAction()
{
	char inputedChoice;

	cin >> inputedChoice;

		 if (inputedChoice == 'W' || inputedChoice == 'w') return moveForward;
	else if (inputedChoice == 'S' || inputedChoice == 's') return moveBackwards;
	else if (inputedChoice == 'A' || inputedChoice == 'a') return moveLeft;
	else if (inputedChoice == 'D' || inputedChoice == 'd') return moveRight;

	else if (inputedChoice == 'M' || inputedChoice == 'm') return menu;

	else if (inputedChoice == 'Q' || inputedChoice == 'q') return quit;

	else if (inputedChoice == 'R' || inputedChoice == 'r') return redo;
	else if (inputedChoice == 'U' || inputedChoice == 'u') return undo;

	else {
			 cout << "Niepoprawna opcja! Prosze zapoznac sie ze sterowaniem." << endl;
			 return invalid;
		 }
}

void GameLogic::MakeMove(_Move move, MapHandler &map)
{
	if (!map.IsThereAWall(move.x, move.y) && map.CanMove(move.x, move.y)) {

		map.MoveMapChange();

		if (map.IsThereAChest(move.x, move.y) && !map.IsThereAChest(move.x + move.x, move.y + move.y)) {

			map.MoveChest(move.x, move.y);
			map.ApplyMoveToArr(move.x, move.y);
		}
		else if(!map.IsThereAChest(move.x, move.y))
			map.ApplyMoveToArr(move.x, move.y);
	}
}

void GameLogic::UndoMove(MapHandler &map)
{
	map.UndoMove();
}

void GameLogic::RedoMove(MapHandler &map)
{
	map.RedoMove();
}