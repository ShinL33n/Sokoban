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

void MapHandler::DisplayMap()
{
	for (int h = 0; h < _height; h++) {
		for (int w = 0; w < _width; w++) {
			cout << DisplayedChar(w,h);
		}
		cout << endl;
	}
}

char MapHandler::DisplayedChar(int width, int height)
{
	mapElems e = _map[width][height][0];

		 if (e == wall) return char(178);
	else if (e == air) return char(32);
	else if (e == player) return char(2);
	else if (e == chest) return char(254);
	else if (e == target) return char(158);
	else if (e == null) return char(255);
	else
		 {
			 cout << "Wystopil blad przy wyswietlaniu elementu mapy!" << endl;
			 return '\0';
		 }

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

void MapHandler::MapArrayInit()
{
	_map = new mapElems** [_width];
	for (int w = 0; w < _width; w++) {
		_map[w] = new mapElems* [_height];
		for (int h = 0; h < _height; h++) {
			_map[w][h] = new mapElems[_hollow];
			for (int k = 0; k < _hollow; k++) {
				_map[w][h][k] = null;
			}
		}
	}
}

void MapHandler::DeleteMapArray()
{
	for (int w = 0; w < _width; w++) {
		for (int h = 0; h < _height; h++) {
			delete[] _map[w][h];
			_map[w][h] = nullptr;
		}
		delete[] _map[w];
		_map[w] = nullptr;
	}

	delete[] _map;
	_map = nullptr;
}