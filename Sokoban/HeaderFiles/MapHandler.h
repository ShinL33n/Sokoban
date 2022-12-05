#pragma once

class MapHandler
{
private:
	const unsigned int _hollow = 21;
	const unsigned int _main = _hollow / 2;
	unsigned int _width, _height;

	void LevelToMapArray(std::ifstream &ifs);
	void MapSizeReading(std::ifstream &ifs);
	void MapArrayInit();
	void RedoMapInit();
	void DeleteMapArray();
	
	char* PathHelper(short lvl);
	char DisplayedChar(int w, int h);

	bool IsMapTheSame(int m, int mc);
	bool AreEveryChestOnTarget();

	enum _mapElems {
		wall = 1,
		air = 2,
		player = 3,
		chest = 4,
		target = 5,
		null = 6,
		winChest = 7
	};

	enum _steppedOnTarget {
		willStep,
		stepped,
		no
	};

	
	struct _PlayerPosition {
		int width;
		int height;
	};

	_mapElems FieldValue(char lvlElem);
	_mapElems*** _map;

	_PlayerPosition _playerPosition;
	
	_steppedOnTarget st;



public:
	MapHandler();
	MapHandler(short selectedLvl);
	~MapHandler();

	void LoadMap(short selectedLvl);
	void DisplayMap();

	void ApplyMoveToArr(int x, int y);
	void MoveMapChange();
	void MoveChest(int x, int y);

	bool IsThereAWall(int x, int y);
	bool IsThereAChest(int x, int y);
	bool IsInfrontAvaible(int actualWidth, int actualHeight, int x, int y);
	bool CanMove(int x, int y);
	void UndoMove();
	void RedoMove();

	_mapElems WhatIsInfront(int w, int h, int x, int y);


	enum gameState {
		game,
		win,
		lost,
		menu
	};

	gameState gS = game;
};
