#include "Blackhole.h"
Blackhole::Blackhole()
{
	this->texture.loadFromFile("../Project3/Blackhole.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(Vector2f(701.f, 701.f)); // �n���� �� LEVEL3 LEVELLAST �~�| setposition ( ���] �w�] 0,0 player �|�Q�l�� )
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

void Blackhole::updateCollision(Player& player, int& playerPosition, const Floor floor)
{
	if (this->sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
	{
		player.getSprite().setPosition(Vector2f(0.f, 0.f));
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
	window->draw(this->sprite);
}