#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
using namespace sf;

enum BrickType
{
	BREAKABLE = 0,
	UNBREAKABLE,
	NUMOFTYPES
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

	bool checkCollision(Player& player);
	void update(Player& player);
	void render(RenderTarget* window);
};

