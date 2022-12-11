#pragma once

class MapHandler
{
private:
	const unsigned int _hollow = 21;
	const unsigned int _main = _hollow / 2;
	const unsigned int _screenWidth = 80;
	const unsigned int _screenHeight = 25;
	unsigned int _width, _height;

	bool _isMapValid;

	void MapSizeReading(std::ifstream &ifs);
	void LevelToMapArray(std::ifstream &ifs);
	void MapArrayInit();
	void DeleteMapArray();
	void RedoMapInit();
	
	char DisplayedChar(int w, int h);
	char* PathHelper(short lvl);

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

	struct _CameraPosition {
		int w;
		int h;
	};

	_mapElems FieldValue(char lvlElem);
	_mapElems*** _map;

	_PlayerPosition _playerPosition;
	_CameraPosition _cameraPosition;
	
	_steppedOnTarget st;


public:
	MapHandler();
	~MapHandler();

	void LoadMap(short selectedLvl);
	void DisplayMap();
	void MoveMapChange();
	void MoveChest(int x, int y);
	void ApplyMoveToArr(int x, int y);
	void MoveCamera(int x, int y);
	void BlockRedoAfterMove();

	int NumberOfLevels();
	unsigned int UndoMove(unsigned int numberOfMoves);
	unsigned int RedoMove(unsigned int numberOfMoves);

	bool CanMove(int x, int y);
	bool IsThereAChest(int x, int y);
	bool IsInfrontAvaible(int actualWidth, int actualHeight, int x, int y);


	_mapElems WhatIsInfront(int w, int h, int x, int y);


	enum gameState {
		game,
		win,
		lost,
		menu
	};

	gameState gS;
};
