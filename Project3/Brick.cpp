#include "Brick.h"

#include <iostream>
using namespace std;

Brick::Brick(Texture* texture)
{
	this->sprite.setTexture(*texture);
	//this->sprite.scale(0.7f, 0.7f);
	this->type = BrickType::BREAKABLE;
}

Brick::~Brick()
{
}

Sprite& Brick::getSprite()
{
	return this->sprite;
}

int Brick::getBrickWidth()
{
	return this->sprite.getTexture()->getSize().x;
}

int Brick::getBrickHeight()
{
	return this->sprite.getTexture()->getSize().y;
}

void Brick::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

bool Brick::updateCollision(Player& player)
{
	if (this->sprite.getGlobalBounds().intersects(player.getShape().getGlobalBounds()) and this->type == BREAKABLE)
	{
		if (this->sprite.getPosition().y > player.getShape().getPosition().y)
		{
			return true;
			
		}
	}
	return false;
}

void Brick::update(Player& player)
{
}

void Brick::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
