#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Floor.h"
#include "Map.h"

using namespace sf;

class Player
{
private:
	RectangleShape shape; // sf
	void initVar();
	void initShape();

	float movementSpeed;

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	int getWidth();
	int getHeight();

	void updateInput();
	void update();
	void render(RenderTarget* target); // sf
};

