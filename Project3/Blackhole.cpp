#include "Blackhole.h"
Blackhole::Blackhole()
{
	this->texture.loadFromFile("../Project3/Blackhole.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(Vector2f(701.f, 701.f)); // 要等到 到 LEVEL3 LEVELLAST 才會 setposition ( 不設 預設 0,0 player 會被吸住 )
}

Blackhole::~Blackhole()
{
}

void Blackhole::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

void Blackhole::update()
{
}

void Blackhole::updateCollision(Player& player, int& playerPosition, const Floor floor, bool& failGame)
{
	if (this->sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
	{
		failGame = true;
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
	window->draw(this->sprite);
}