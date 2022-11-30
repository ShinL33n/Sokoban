#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "../HeaderFiles/MapHandler.h"

using namespace std;

MapHandler::MapHandler()
{
	MapArrayInit(10, 10);
}

MapHandler::~MapHandler()
{
	DeleteMapArray();
}

void MapHandler::LoadMap(short selectedLvl = 1)
{	

	char* fileName = PathHelper(selectedLvl);

	ifstream input(fileName);

	if (input.good()) {

		LevelToMapArray(input);

	}
	else 
		cout << "Wystapil blad podczas wczytywania levela.";


	input.close();
}

void MapHandler::LevelToMapArray(ifstream& ifs)
{
	unsigned int width = 0, height = 1;
	bool isWidthCounted = false;
	char checkChar;

	while (ifs.get(checkChar)) {

		if (checkChar == '\n') {
			isWidthCounted = true;
			height++;
		}

		if (!isWidthCounted) width++;
	}
}

char* MapHandler::PathHelper(short lvl)
{
	char* lvlName = new char[sizeof(short)];
	char filePathPrefix[] = "ResourceFiles/levels/level";
	char filePathPostfix[] = ".txt";

	sprintf(lvlName, "%i", lvl);

	char* fileName = new char[strlen(filePathPrefix) + strlen(filePathPostfix) + strlen(lvlName)];
	sprintf(fileName, "%c", '\0');

	strcat(fileName, filePathPrefix);
	strcat(fileName, lvlName);
	strcat(fileName, filePathPostfix);

	
	return fileName;
}

void MapHandler::MapArrayInit(unsigned int width, unsigned int height)
{
	_width = width;
	_height = height;

	_map = new char** [_width];
	for (int i = 0; i < _width; i++) {
		_map[i] = new char* [_height];
		for (int j = 0; j < _height; j++) {
			_map[i][j] = new char[_hollow];
			for (int k = 0; k < _hollow; k++) {
				_map[i][j][k] = 0;
			}
		}
	}
}

void MapHandler::DeleteMapArray()
{
	for (int i = 0; i < _width; i++) {
		for (int j = 0; j < _height; j++) {
			delete[] _map[i][j];
			_map[i][j] = nullptr;
		}
		delete[] _map[i];
		_map[i] = nullptr;
	}

	delete[] _map;
	_map = nullptr;
}