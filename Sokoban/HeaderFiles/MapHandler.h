#pragma once

class MapHandler
{
private:
	const unsigned int _hollow = 10;
	unsigned int _width, _height;

	void LevelToMapArray(std::ifstream &ifs);
	void MapSizeReading(std::ifstream &ifs);
	void MapArrayInit();
	void RedoMapInit();
	void DeleteMapArray();
	
	char* PathHelper(short lvl);
	char DisplayedChar(int w, int h);

	enum mapElems {
		wall = 1,
		air = 2,
		player = 3,
		chest = 4,
		target = 5,
		null = 6
	};

	mapElems FieldValue(char lvlElem);
	mapElems*** _map;

public:
	MapHandler();
	~MapHandler();

	void LoadMap(short selectedLvl);
	void DisplayMap();

};
