#include "Flag.h"
#include <iostream>
using namespace std;

Flag::Flag()
{
	this->texture.loadFromFile("../Project3/Flag.png");
	this->sprite.setTexture(this->texture);
}

Flag::~Flag()
{
}

Sprite& Flag::getSprite()
{
	return this->sprite;
}

int Flag::getFlagWidth()
{
	return this->texture.getSize().x;
}

int Flag::getFlagHeight()
{
	return this->texture.getSize().y;
}

void Flag::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

void Flag::update(bool& endGame)
{
	this->sprite.move(Vector2f(0.f, 5.f));
	if (this->sprite.getPosition().y >= 500.f)
	{
		endGame = true;
	}
		
}


void Flag::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
