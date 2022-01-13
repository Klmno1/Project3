#include "Pole.h"
#include <iostream>
using namespace std;

Pole::Pole()
{
	this->texture.loadFromFile("../Project3/Pole.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(Vector2f(-100.f, -100.f)); // 要等到 到 LEVELLAST 才會 setposition ( 不設 預設 0,0 待在原點太久會endgame )
}

Pole::~Pole()
{
}

Sprite& Pole::getSprite()
{
	return this->sprite;
}

int Pole::getPoleWidth()
{
	return this->texture.getSize().x;
}

int Pole::getPoleHeight()
{
	return this->texture.getSize().y;
}

void Pole::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}


bool Pole::updateCollision(Player& player, const int playerPosition)
{
	if (this->sprite.getGlobalBounds().intersects(
		player.getSprite().getGlobalBounds()) )
	{
		return true;
	}
	return false;
}

void Pole::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
