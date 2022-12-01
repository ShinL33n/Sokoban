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
}

MapHandler::~MapHandler()
{
	DeleteMapArray();
}

void MapHandler::LoadMap(short selectedLvl = 1)
{	

	char* fileName = PathHelper(selectedLvl);

	ifstream input(fileName, ifstream::in);

	if (input.good()) {

		MapSizeReading(input);
		MapArrayInit();
		LevelToMapArray(input);

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

	for (int h = 0; h < _height; lvlElem != '\n' ? h++ : h) {
		for (int w = 0; w < _width; lvlElem != '\n' ? w++ : w) {

			ifs.get(lvlElem);

			if (lvlElem != '\n')
				_map[w][h][0] = FieldValue(lvlElem);
		}
	}

	cout << endl;
	for (int h = 0; h < _height; h++) {
		for (int w = 0; w < _width; w++) {
			cout << _map[w][h][0] << " ";
		}
		cout << endl;
	}
}

MapHandler::mapElems MapHandler::FieldValue(char lvlElem)
{
		 if (lvlElem == '1') return wall;
	else if (lvlElem == '2') return air;
	else if (lvlElem == '3') return player;
	else if (lvlElem == '4') return chest;
	else if (lvlElem == '5') return target;
	else if (lvlElem == '6') return null;
	else {
			 cout << "Wadliwy level, nierozpoznany element mapy!" << endl;
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
	char filePathPostfix[] = ".txt";

	sprintf(lvlName, "%i", lvl);

	char* fileName = new char[strlen(filePathPrefix) + strlen(filePathPostfix) + strlen(lvlName)];
	sprintf(fileName, "%c", '\0');

	strcat(fileName, filePathPrefix);
	strcat(fileName, lvlName);
	strcat(fileName, filePathPostfix);

	
	return fileName;
}

void MapHandler::MapArrayInit()
{
	_map = new mapElems** [_width];
	for (int i = 0; i < _width; i++) {
		_map[i] = new mapElems* [_height];
		for (int j = 0; j < _height; j++) {
			_map[i][j] = new mapElems[_hollow];
			for (int k = 0; k < _hollow; k++) {
				_map[i][j][k] = null;
			}
		}
	}
	/*_map = new char** [_width];
	for (int i = 0; i < _width; i++) {
		_map[i] = new char* [_height];
		for (int j = 0; j < _height; j++) {
			_map[i][j] = new char[_hollow];
			for (int k = 0; k < _hollow; k++) {
				_map[i][j][k] = 0;
			}
		}
	}*/
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