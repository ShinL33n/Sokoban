#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../HeaderFiles/GameLogic.h"
#include "../HeaderFiles/GameProcess.h"

using namespace std;

GameLogic::GameLogic(short selectedLevel)
{
	_numberOfMoves = CheckNumberOfMoves(selectedLevel);
}

GameLogic::~GameLogic()
{

}

void GameLogic::ActionHandler(MapHandler& map, MenuHandler& menuHndl)
{
	DisplayNumOfMoves();

	if (map.gS == map.game) {

		if (_numberOfMoves == 0)
			map.gS = map.lost;

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
			else if (action == cameraUp || action == cameraDown || action == cameraLeft || action == cameraRight) {
				map.MoveCamera(MoveVector(action).x, MoveVector(action).y);
			}

		} while (action == invalid);
	}
}

GameLogic::_Move GameLogic::MoveVector(_action action)
{
		 if (action == moveForward || action == cameraUp)		return { 0, -1 };
	else if (action == moveBackwards || action == cameraDown)	return { 0, 1 };
	else if (action == moveLeft || action == cameraLeft)		return { -1, 0 };
	else if (action == moveRight || action == cameraRight)		return { 1, 0 };
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

	else if (inputedChoice == 'P' || inputedChoice == 'p') return menu;

	else if (inputedChoice == 'Q' || inputedChoice == 'q') return quit;

	else if (inputedChoice == 'R' || inputedChoice == 'r') return redo;
	else if (inputedChoice == 'U' || inputedChoice == 'u') return undo;

	else if (inputedChoice == 'I' || inputedChoice == 'i') return cameraUp;
	else if (inputedChoice == 'K' || inputedChoice == 'k') return cameraDown;
	else if (inputedChoice == 'J' || inputedChoice == 'j') return cameraLeft;
	else if (inputedChoice == 'L' || inputedChoice == 'l') return cameraRight;

	else {
			 cout << "Niepoprawna opcja! Prosze zapoznac sie ze sterowaniem." << endl;
			 return invalid;
		 }
}

void GameLogic::MakeMove(_Move move, MapHandler &map)
{
	if (map.CanMove(move.x, move.y)) {

		map.MoveMapChange();

		if (map.IsThereAChest(move.x, move.y) && !map.IsThereAChest(move.x + move.x, move.y + move.y)) {

			map.MoveChest(move.x, move.y);
			map.ApplyMoveToArr(move.x, move.y);
		}
		else if(!map.IsThereAChest(move.x, move.y))
			map.ApplyMoveToArr(move.x, move.y);

		map.BlockRedoAfterMove();

		_numberOfMoves--;
	}
}

void GameLogic::UndoMove(MapHandler &map)
{
	_numberOfMoves = map.UndoMove(_numberOfMoves);
}

void GameLogic::RedoMove(MapHandler &map)
{
	_numberOfMoves = map.RedoMove(_numberOfMoves);
}

void GameLogic::DisplayNumOfMoves()
{
	cout << char(218);
	for (int i = 0; i < 22; i++) cout << char(196);
	cout << char(191) << endl;
	cout << char(179) << "Pozostalych ruchow:" << setw(3) << _numberOfMoves << char(179) << endl;
	cout << char(192);
	for (int i = 0; i < 22; i++) cout << char(196);
	cout << char(217) << endl;
}

char* GameLogic::SettingsPathHelper(short lvl)
{
	char* lvlName = new char[sizeof(short)];

	sprintf(lvlName, "%i", lvl);

	char filePathPrefix[] = "ResourceFiles/levelsProperties/NOM";
	//char filePathPrefix[] = "../../Sokoban/ResourceFiles/levels/level";
	char filePathPostfix[] = ".txt";

	char* fileName = new char[strlen(filePathPrefix) + strlen(filePathPostfix) + strlen(lvlName)];
	sprintf(fileName, "%c", '\0');


	strcat(fileName, filePathPrefix);
	strcat(fileName, lvlName);
	strcat(fileName, filePathPostfix);

	return fileName;
}

unsigned int GameLogic::CheckNumberOfMoves(short selectedLevel)
{
	unsigned int MON = 0;

	char* fileName = SettingsPathHelper(selectedLevel);

	ifstream ifs(fileName, ifstream::in);

	if (ifs.good()) {

		ifs >> MON;
	}
	else {
		cout << "Wystapil blad podczas wczytywania ustawien.";
		return 100;
	}

	ifs.close();

	return MON;
}