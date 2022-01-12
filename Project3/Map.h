#pragma once
#include <vector>
#include <map>

#include "Brick.h"
#include "Pipe.h"

using namespace std;
using namespace sf;

enum LEVEL
{
	LEVEL1 = 1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	TOTAL_LEVEL
};

enum BRCIK
{
	BRICK1 = 6,
	BRICK2 = 0,
	BRICK3 = 8,
	BRICK4 = 4
};

enum PIPE
{
	PIPE1 = 1,
	PIPE2 = 4,
	PIPE3 = 0,
	PIPE4 = 1
};

class Map
{
private:
	int brickNumber;
	int pipeNumber;
	map<string, Texture*> texture;
	vector <Brick*> brick;
	vector <Pipe*> pipe;
	vector<Vector2f> brickPosition;
	vector<Vector2f> pipePosition;

public:
	Map();
	~Map();

	void changeBrickNum(const int playerPosition);
	void changePipeNum(const int playerPosition);
	void spawnBrick();
	void spawnPipe();
	void initTexture();
	void initPosition(const int playerPosition, const Floor floor);
	void setBrickPosition();
	void setPipePosition();

	void update(const int playerPosition, const Floor floor, Player& player);
	void render(RenderTarget* window);
	
};

