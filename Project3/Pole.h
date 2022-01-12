#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
using namespace sf;

class Pole
{
private:
	Sprite sprite;
	Texture texture;


public:
	Pole();
	~Pole();

	Sprite getSprite();
	int getPoleWidth();
	int getPoleHeight();
	void setPosition(Vector2f position);

	bool updateCollision(Player& player);
	void render(RenderTarget* window);
};

