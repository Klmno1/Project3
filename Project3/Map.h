#pragma once
#include <vector>
#include <map>

#include "Brick.h"
#include "Pipe.h"
#include "Player.h"

using namespace std;
using namespace sf;

class Map
{
private:
	int Bricknumber;
	map<string, Texture*> texture;
	vector <Brick*> brick;
	vector <Pipe*> pipe;
	vector<Vector2f> brickPosition;
	vector<Vector2f> pipePosition;

public:
	Map();
	~Map();

	void spawnBrick();
	void spawnPipe();
	void initTexture();
	void initPosition();
	void setBrickPosition();
	void setPipePosition();

	void update();
	void render(RenderTarget* window);
	
};

