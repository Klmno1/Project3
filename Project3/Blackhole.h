#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
using namespace sf;

class Blackhole
{
private:
	Sprite sprite;
	Texture texture;

public:
	Blackhole();
	virtual ~Blackhole();

	void update();
	void updateCollision(Player& player, int& playerPosition);
	const Sprite& getSprite() const;
	int getWidth();
	int getHeight();
	void render(RenderTarget* window);
};

