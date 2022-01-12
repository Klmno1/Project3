#include "Pipe.h"
#include <iostream>
using namespace std;

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

void Pipe::update(Player& player)
{
	this->updateCollision(player);
}

void Pipe::updateCollision(Player& player)
{
	if (this->sprite.getGlobalBounds().intersects(player.getShape().getGlobalBounds()))
	{
		if (player.getShape().getPosition().x >= this->sprite.getPosition().x
			and player.getShape().getPosition().y < this->sprite.getPosition().y)
			player.getShape().setPosition(Vector2f(
				this->sprite.getPosition().x + this->sprite.getTexture()->getSize().x,
				player.getShape().getPosition().y
			));

		else if (player.getShape().getPosition().x < this->sprite.getPosition().x
			and player.getShape().getPosition().y < this->sprite.getPosition().y)
			player.getShape().setPosition(Vector2f(
				this->sprite.getPosition().x - player.getShape().getPosition().x,
				player.getShape().getPosition().y
			));
		else if (player.getShape().getPosition().y > this->sprite.getPosition().y)
			player.getShape().setPosition(Vector2f(
				player.getShape().getPosition().x,
				this->sprite.getPosition().y + player.getShape().getSize().y
			));
	}
}

void Pipe::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
