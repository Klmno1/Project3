#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"

using namespace sf;

enum BrickType
{
	DEFAULT = 0,
	ENLARGE,
	WEED,
	BACKTOBEGIN,
	NUMOFTYPE
};

class Brick
{
private:
	Sprite sprite;
	int type;

public:
	Brick(Texture* texture);
	~Brick();
	
	Sprite& getSprite();
	int getBrickWidth();
	int getBrickHeight();
	void setPosition(Vector2f position);

	void obtainProps(Player& player, int& playerPosition);
	bool checkCollision(Player& player, int& playerPosition);
	void update(Player& player);
	void render(RenderTarget* window);
};

