#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "../HeaderFiles/MapHandler.h"

using namespace std;

MapHandler::MapHandler()
{
	_width = 0;
	_height = 0;
	_map = nullptr;
	_isMapValid = true;
	gS = game;
	st = no;
}

MapHandler::~MapHandler()
{
	DeleteMapArray();
}

void MapHandler::DisplayMap()
{
	if (!_isMapValid)
		gS = menu;

	cout << "\033[H\033[J";
	char display = '\0';

	for (short h = 0; h < _height; h++) {
		for (short w = 0; w < _width; w++) {

			cout << DisplayedChar(w, h);
		}
		cout << endl;

	}
}

char MapHandler::DisplayedChar(int width, int height)
{
	_mapElems e = _map[width][height][_main];

	if (e == wall) return char(178);
	else if (e == air) return char(32);
	else if (e == player) return char(2);
	else if (e == chest) return char(254);
	else if (e == target) return char(207);
	else if (e == null) return char(255);
	else if (e == winChest) return '#'; //char(127);
	else
		 {
			 cout << "Wystapil blad przy wyswietlaniu elementu mapy!" << endl;
			 return '\0';
		 }
}

int MapHandler::NumberOfLevels()
{
	int levelCount = 0;
	char* fileName;

	ifstream inputTester;

	for (int i = 1; true; i++)
	{
		inputTester.clear();
		inputTester.seekg(0);

		fileName = PathHelper(i);

		inputTester.open(fileName, ifstream::in);

		if (inputTester.good()) {
			levelCount++;
			inputTester.close();
		}
		else {
			inputTester.close();
			return levelCount;
		}
	}

	inputTester.close();
	return 0;
}

void MapHandler::LoadMap(short selectedLvl)
{	

	char* fileName = PathHelper(selectedLvl);

	ifstream input(fileName, ifstream::in);

	if (input.good()) {

		MapSizeReading(input);
		MapArrayInit();
		LevelToMapArray(input);
		RedoMapInit();

	}
	else 
		cout << "Wystapil blad podczas wczytywania levela.";


	input.close();
}

void MapHandler::LevelToMapArray(ifstream &ifs)
{
	ifs.clear();
	ifs.seekg(0);

	char lvlElem = '\0';
	_mapElems mE = null;

	for (short h = 0; h < _height; lvlElem != '\n' ? h++ : h) {
		for (short w = 0; w < _width; lvlElem != '\n' ? w++ : w) {

			ifs.get(lvlElem);

			if (lvlElem != '\n') {
				mE = FieldValue(lvlElem);
				_map[w][h][_main] = mE;
			}

			if (mE == player) {
				_playerPosition.width = w;
				_playerPosition.height = h ;
			}
		}
	}
}

void MapHandler::RedoMapInit()
{
	for (short w = 0; w < _width; w++) {
		for (short h = 0; h < _height; h++) {
			for (short d = 0; d < _hollow; d++) {

				if (d != _main) 
					_map[w][h][d] = _map[w][h][_main];
			}
		}
	}
}

MapHandler::_mapElems MapHandler::FieldValue(char lvlElem)
{
		 if (lvlElem == '1') return wall;
	else if (lvlElem == '2') return air;
	else if (lvlElem == '3') return player;
	else if (lvlElem == '4') return chest;
	else if (lvlElem == '5') return target;
	else if (lvlElem == '6') return null;
	else if (lvlElem == '7') return winChest;
	else {
			 cout << "Wadliwy level, nierozpoznany element mapy!" << endl;
			 _isMapValid = false;
			 system("pause");
			 return null;
		 }
}

void MapHandler::MapSizeReading(ifstream &ifs)
{
	unsigned int width = 0, height = 0;
	bool isWidthCounted = false;
	char checkChar = '\0';

	while (ifs.get(checkChar)) {

		if (checkChar == '\n') {
			isWidthCounted = true;
			height++;
		}

		if (!isWidthCounted) width++;
	}

	_width = width;
	_height = ++height;
}

char* MapHandler::PathHelper(short lvl)
{
	char* lvlName = new char[sizeof(short)];
	char filePathPrefix[] = "ResourceFiles/levels/level";
	//char filePathPrefix[] = "../../Sokoban/ResourceFiles/levels/level";
	char filePathPostfix[] = ".txt";

	sprintf(lvlName, "%i", lvl);

	char* fileName = new char[strlen(filePathPrefix) + strlen(filePathPostfix) + strlen(lvlName)];
	sprintf(fileName, "%c", '\0');

	strcat(fileName, filePathPrefix);
	strcat(fileName, lvlName);
	strcat(fileName, filePathPostfix);
	
	return fileName;
}

void MapHandler::ApplyMoveToArr(int x, int y)
{
	if (_map[_playerPosition.width + x][_playerPosition.height + y][_main] == target || _map[_playerPosition.width + x][_playerPosition.height + y][_main] == winChest)
		st = willStep;

	_map[_playerPosition.width + x][_playerPosition.height + y][_main] = player;


	if (st == willStep) {
		_map[_playerPosition.width][_playerPosition.height][_main] = air;
		st = stepped;
	}
	else if (st == stepped) {
		_map[_playerPosition.width][_playerPosition.height][_main] = target;
		st = no;
	}
	else {
		_map[_playerPosition.width][_playerPosition.height][_main] = air;
	}
	
	_playerPosition.width += x;
	_playerPosition.height += y;
	
}

///Stosowaæ przed zatwierdzeniem jakiegokolwiek ruchu
void MapHandler::MoveMapChange()
{
	for (short w = 0; w < _width; w++) {
		for (short h = 0; h < _height; h++) {
			for (short d = _hollow - 1; d > _main; d--) {

				_map[w][h][d] = _map[w][h][d - 1];
			}
		}
	}
}

void MapHandler::MoveChest(int x, int y)
{
	if (_map[_playerPosition.width + x + x][_playerPosition.height + y + y][_main] == target) {
		_map[_playerPosition.width + x + x][_playerPosition.height + y + y][_main] = winChest;
		_map[_playerPosition.width + x][_playerPosition.height + y][_main] = air;
		if(AreEveryChestOnTarget()) gS = win;
	}
	else if (_map[_playerPosition.width + x][_playerPosition.height + y][_main] == winChest) {
		_map[_playerPosition.width + x + x][_playerPosition.height + y + y][_main] = chest;
		_map[_playerPosition.width + x][_playerPosition.height + y][_main] = target;
	}
	else {
		_map[_playerPosition.width + x + x][_playerPosition.height + y + y][_main] = chest;
		_map[_playerPosition.width + x][_playerPosition.height + y][_main] = air;

	}
}

bool MapHandler::CanMove(int x, int y)
{
	return IsInfrontAvaible(_playerPosition.width, _playerPosition.height,  x,  y);
}

bool MapHandler::IsInfrontAvaible(int actualWidth, int actualHeight, int x, int y)
{
	if (WhatIsInfront(actualWidth, actualHeight, x, y) == air || WhatIsInfront(actualWidth, actualHeight, x, y) == target)
		return true;
	else if (WhatIsInfront(actualWidth, actualHeight, x, y) == chest || WhatIsInfront(actualWidth, actualHeight, x, y) == winChest)
		return IsInfrontAvaible(actualWidth + x, actualHeight + y, x, y);
	else
		return false;
}

MapHandler::_mapElems MapHandler::WhatIsInfront(int w, int h, int x, int y)
{
	return _map[w + x][h + y][_main];
}

bool MapHandler::IsThereAWall(int x, int y)
{
	return _map[_playerPosition.width + x][_playerPosition.height + y][_main] == wall;
}

bool MapHandler::IsThereAChest(int x, int y)
{
	return _map[_playerPosition.width + x][_playerPosition.height + y][_main] == chest || _map[_playerPosition.width + x][_playerPosition.height + y][_main] == winChest;
}

void MapHandler::UndoMove()
{
	if (!IsMapTheSame(_main, _main + 1)) {
		for (short w = 0; w < _width; w++) {
			for (short h = 0; h < _height; h++) {
				for (short d = 0; d < _hollow - 1; d++) {

					_map[w][h][d] = _map[w][h][d + 1];

					if (d == _main && _map[w][h][d] == player) {
						_playerPosition.width = w;
						_playerPosition.height = h;
					}
				}
			}
		}
	}
}

void MapHandler::RedoMove()
{
	if (!IsMapTheSame(_main - 1, _main - 2)) {
		for (short w = 0; w < _width; w++) {
			for (short h = 0; h < _height; h++) {
				for (short d = _hollow - 1; d > 0; d--) {

					_map[w][h][d] = _map[w][h][d - 1];

					if (d == _main && _map[w][h][d] == player) {
						_playerPosition.width = w;
						_playerPosition.height = h;
					}
				}
			}
		}
	}
}

bool MapHandler::IsMapTheSame(int m, int mc)
{
	bool isSame = true;

	for (short w = 0; w < _width; w++) {
		for (short h = 0; h < _height; h++) {
			if (_map[w][h][m] != _map[w][h][mc])
				isSame = false;
		}
	}

	return isSame;
}

bool MapHandler::AreEveryChestOnTarget() {

	bool result = true;

	for (int w = 0; w < _width; w++) {
		for (int h = 0; h < _height; h++) {

			if (_map[w][h][_main] == chest) result = false;
		}
	}

	return result;
}

void MapHandler::MapArrayInit()
{
	_map = new _mapElems** [_width];
	for (short w = 0; w < _width; w++) {
		_map[w] = new _mapElems* [_height];
		for (short h = 0; h < _height; h++) {
			_map[w][h] = new _mapElems[_hollow];
			for (short k = 0; k < _hollow; k++) {
				_map[w][h][k] = null;
			}
		}
	}
}

void MapHandler::DeleteMapArray()
{
	for (short w = 0; w < _width; w++) {
		for (short h = 0; h < _height; h++) {
			delete[] _map[w][h];
			_map[w][h] = nullptr;
		}
		delete[] _map[w];
		_map[w] = nullptr;
	}

	delete[] _map;
	_map = nullptr;
}