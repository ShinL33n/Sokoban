#pragma once

class MapHandler
{
private:
	unsigned int _width, _height;
	const unsigned int _hollow = 10;
	char*** _map;

	void MapArrayInit(unsigned int width, unsigned int height);
	void DeleteMapArray();

public:
	enum mapElems {
		wall = 1,
		air = 2,
		player = 3,
		chest = 4,
		target = 5
	};

	MapHandler();
	~MapHandler();

	void LoadMap(int selectedLvl);
	void pathHelper(int l,char* f);

};
