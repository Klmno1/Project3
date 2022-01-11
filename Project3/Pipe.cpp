#include "Pipe.h"

Pipe::Pipe()
{
}

Pipe::Pipe(Texture* texture)
{
	this->sprite.setTexture(*texture);
}

Pipe::~Pipe()
{
}

int Pipe::getPipeWidth()
{
	return this->sprite.getTexture()->getSize().x;
}

int Pipe::getPipeHeight()
{
	return this->sprite.getTexture()->getSize().y;
}

void Pipe::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

void Pipe::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
