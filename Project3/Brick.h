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
	Texture afterBreak;
	int type;

public:
	Brick();
	Brick(Texture* texture);
	~Brick();
	
	int getBrickWidth();
	int getBrickHeight();
	void setPosition(Vector2f position);

	void updateCollision(Player& player);
	void update(Player& player);
	void render(RenderTarget* window);
};

