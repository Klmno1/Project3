#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
using namespace sf;

class Pipe
{
private:
	Sprite sprite;


public:
	Pipe();
	Pipe(Texture* texture);
	~Pipe();

	
	int getPipeWidth();
	int getPipeHeight();
	void setPosition(Vector2f position);

	void update(Player& player);
	void updateCollision(Player& player);
	void render(RenderTarget* window);
};

