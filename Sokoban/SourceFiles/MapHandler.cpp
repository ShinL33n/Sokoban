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

void MapHandler::LoadMap(int selectedLvl = 1)
{	
	/*char lvlname[256];
	sprintf_s(lvlname, "%i", selectedlvl);*/
	//char* filename = new char[1];
	/*char filepath[] = { 'r','e','s','o','u','r','c','e','f','i','l','e','s','/','l','e','v','e','l','s','/','l','e','v','e','l','\0' };
	filename = strcat(strcat(filepath, lvlname), ".txt");*/
	char fileName[256];
	pathHelper(selectedLvl, fileName);
	
	cout << fileName << endl;

	ifstream input(fileName);

	if (input.good()) cout << "oooooo";
	else cout << "dupa";
	system("pause");
	input.close();
	
}

void MapHandler::pathHelper(int l, char* f)
{
	char lvlName[256];
	sprintf_s(lvlName, "%d", l);

	char filePath[1000] = { "ResourceFiles/levels/level" };

	//char filePath[] = { 'R', 'e', 's', 'o', 'u', 'r', 'c', 'e', 'F', 'i', 'l', 'e', 's', '/', 'l', 'e', 'v', 'e', 'l', 's', '/', 'l', 'e', 'v', 'e', 'l', '\0' };
	f = strcat(filePath, lvlName);
	f = strcat(f, ".txt");
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