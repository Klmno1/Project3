#include "Brick.h"

enum BrickType
{
	BREAKABLE = 0,
	UNBREAKABLE,
	NUMOFTYPES
};


Brick::Brick()
{
	this->type = BrickType::UNBREAKABLE;
}

Brick::Brick(Texture* texture)
{
	this->sprite.setTexture(*texture);
	//this->sprite.scale(0.7f, 0.7f);
	this->type = BrickType::UNBREAKABLE;
}

Brick::~Brick()
{
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

void Brick::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
