#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
#include "Floor.h"
using namespace sf;

class Enemy
{
private:

	Sprite sprite;
	Texture texture;
	float movement;

public:
	Enemy(int enemySerial);
	virtual ~Enemy();

	void setPosition(Vector2f position);
	void update();
	void updateCollision(Player& player, int& playerPosition, const Floor floor);
	const Sprite& getSprite() const;
	int getWidth();
	int getHeight();
	void render(RenderTarget* window);
};

