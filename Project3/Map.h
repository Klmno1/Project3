#pragma once
#include <vector>
#include <map>

#include "Brick.h"
#include "Pipe.h"
#include "Pole.h"
#include "Flag.h"
#include "Blackhole.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

enum LEVEL
{
	LEVEL1 = 1,
	LEVEL2,
	LEVEL3,
	LEVELLAST,
	TOTAL_LEVEL
};

enum BRCIK
{
	BRICK1 = 6,
	BRICK2 = 0,
	BRICK3 = 8,
	BRICK4 = 3
};

enum PIPE
{
	PIPE1 = 1,
	PIPE2 = 4,
	PIPE3 = 0,
	PIPE4 = 1
};

enum ENEMY
{
	ENEMY1 = 0,
	ENEMY2 = 4,
	ENEMY3 = 0,
	ENEMY4 = 0
};

class Map
{
private:
	int brickNumber;
	int pipeNumber;
	int enemyNumber;
	map<string, Texture*> texture;
	vector <Brick*> brick;
	vector <Pipe*> pipe;
	vector <Enemy*> enemy;
	vector<Vector2f> brickPosition;
	vector<Vector2f> pipePosition;
	vector<Vector2f> enemyPosition;
	Pole pole;
	Flag flag;
	Blackhole blackhole;

public:
	Map();
	~Map();

	void changeBrickNum(const int playerPosition);
	void changePipeNum(const int playerPosition);
	void spawnBrick();
	void spawnPipe();
	void spawnEnemy();
	void initTexture();
	void initPosition(const int playerPosition, const Floor floor);
	void setBrickPosition();
	void setPipePosition();
	void setEnemyPosition();

	void update(int& playerPosition, const Floor floor, Player& player, bool& endGame);
	void render(RenderTarget* window, const int playerPosition);
	
};

