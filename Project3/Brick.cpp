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

bool Brick::checkCollision(Player& player)
{
	if (this->sprite.getGlobalBounds().intersects(player.getShape().getGlobalBounds()) and this->type == BREAKABLE)
	{

		if (this->sprite.getPosition().y > player.getShape().getPosition().y
			and this->sprite.getPosition().x <= player.getShape().getPosition().x
			and this->sprite.getPosition().x + this->sprite.getTexture()->getSize().x  > player.getShape().getPosition().x
			)
		{
			player.getShape().setPosition(Vector2f(
				player.getShape().getPosition().x,
				this->sprite.getPosition().y - player.getShape().getSize().y
			));
		}

		else if (this->sprite.getPosition().x < player.getShape().getPosition().x)
		{
			player.getShape().setPosition(Vector2f(
				this->sprite.getPosition().x + this->sprite.getTexture()->getSize().x,
				player.getShape().getPosition().y
			));
		}

		else if (this->sprite.getPosition().x > player.getShape().getPosition().x)
		{
			player.getShape().setPosition(Vector2f(
				this->sprite.getPosition().x - player.getShape().getSize().x,
				player.getShape().getPosition().y
			));
		}

		else if (this->sprite.getPosition().y < player.getShape().getPosition().y)
		{
			player.getShape().setPosition(Vector2f(
				player.getShape().getPosition().x,
				this->sprite.getPosition().y + this->sprite.getTexture()->getSize().y
			));
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
