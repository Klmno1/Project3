#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
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

	void updateInput();
	void update();
	void render(RenderTarget* target); // sf
};

