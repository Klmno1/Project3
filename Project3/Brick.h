#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Brick
{
private:
	Sprite sprite;
	int type;

public:
	Brick();
	Brick(Texture* texture);
	~Brick();
	
	int getBrickWidth();
	int getBrickHeight();
	void setPosition(Vector2f position);
	void render(RenderTarget* window);
};
