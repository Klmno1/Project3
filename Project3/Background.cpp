#include "Background.h"

Background::Background()
{
	this->texture.loadFromFile("../Project3/background.png");
	this->sprite.setTexture(this->texture);
}

Background::~Background()
{
}

void Background::show(RenderTarget* window)
{
	window->draw(this->sprite);
}

