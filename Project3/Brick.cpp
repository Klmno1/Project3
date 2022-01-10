#include "Brick.h"

Brick::Brick()
{
	this->texture.loadFromFile("../Project3/Brick.png");
	this->sprite.setTexture(this->texture);
}

Brick::~Brick()
{
}
