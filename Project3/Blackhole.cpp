#include "Blackhole.h"
Blackhole::Blackhole()
{
	this->texture.loadFromFile("../Project3/Blackhole.png");
	this->sprite.setTexture(this->texture);
}

Blackhole::~Blackhole()
{
}

void Blackhole::update()
{
}

void Blackhole::updateCollision(Player& player, int& playerPosition)
{
	if (this->sprite.getGlobalBounds().intersects(player.getShape().getGlobalBounds()))
	{
		player.getShape().setPosition(Vector2f(0.f, 0.f));
		playerPosition = 1;
	}
}

const Sprite& Blackhole::getSprite() const
{
	return this->sprite;
}

int Blackhole::getWidth()
{
	return this->sprite.getTexture()->getSize().x;
}

int Blackhole::getHeight()
{
	return this->sprite.getTexture()->getSize().y;
}

void Blackhole::render(RenderTarget* window)
{
	this->sprite.setPosition(Vector2f(0, 500));
	window->draw(this->sprite);
}