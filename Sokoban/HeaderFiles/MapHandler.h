#pragma once

class MapHandler
{
private:
	unsigned int _width, _height;
	const unsigned int _hollow = 10;
	char*** _map;

	void MapArrayInit(unsigned int width, unsigned int height);
	void DeleteMapArray();
	void LevelToMapArray(std::ifstream& ifs);
	
	char* PathHelper(short lvl);

	enum mapElems {
		wall = 1,
		air = 2,
		player = 3,
		chest = 4,
		target = 5,
		null = 6
	};

public:
	MapHandler();
	~MapHandler();

	void LoadMap(short selectedLvl);

};
