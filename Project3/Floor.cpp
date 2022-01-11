#include "Floor.h"
Floor::Floor()
{
	this->texture.loadFromFile("../Project3/Floor.jfif");
	this->sprite.setTexture(this->texture);
}

Floor::~Floor()
{
}

int Floor::getWidth()
{
	return this->sprite.getTexture()->getSize().x;
}

int Floor::getHeight()
{
	return this->sprite.getTexture()->getSize().y;
}

void Floor::render(RenderTarget* window)
{
	this->sprite.setPosition(Vector2f(0, 500));
	window->draw(this->sprite);
}