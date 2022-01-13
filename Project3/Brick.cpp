#include "Brick.h"

#include <iostream>
#include <ctime>
using namespace std;

Brick::Brick(Texture* texture)
{
	this->sprite.setTexture(*texture);
	//this->sprite.scale(0.7f, 0.7f);
	this->type = rand() % BrickType::NUMOFTYPE;
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

bool Brick::checkCollision(Player& player, int& playerPosition)
{
	if (this->sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()) )
	{

		if (this->sprite.getPosition().y > player.getSprite().getPosition().y
			and this->sprite.getPosition().x - player.getSprite().getTexture()->getSize().x <= player.getSprite().getPosition().x
			and this->sprite.getPosition().x + this->sprite.getTexture()->getSize().x  >= player.getSprite().getPosition().x
			)
		{ 
			player.getSprite().setPosition(Vector2f(
				player.getSprite().getPosition().x,
				this->sprite.getPosition().y - player.getSprite().getTexture()->getSize().y));
		}

		else if (this->sprite.getPosition().x < player.getSprite().getPosition().x)
		{
			player.getSprite().setPosition(Vector2f(
				this->sprite.getPosition().x + this->sprite.getTexture()->getSize().x,
				player.getSprite().getPosition().y
			));
		}

		else if (this->sprite.getPosition().x > player.getSprite().getPosition().x)
		{
			player.getSprite().setPosition(Vector2f(
				this->sprite.getPosition().x - player.getSprite().getTexture()->getSize().x,
				player.getSprite().getPosition().y
			));
		}

		else if (this->sprite.getPosition().y < player.getSprite().getPosition().y)
		{
			player.getSprite().setPosition(Vector2f(
				player.getSprite().getPosition().x,
				this->sprite.getPosition().y + this->sprite.getTexture()->getSize().y
			));
			this->obtainProps(player, playerPosition);
			return true;
		}
	}
	return false;
}

void Brick::update(Player& player)
{
}

void Brick::obtainProps(Player& player, int& playerPosition)
{
	switch (this->type)
	{

	case BrickType::DEFAULT:
		player.setWeed(false);
		break;

	case BrickType::ENLARGE:
		player.setenLarge(true);
		
		break;

	case BrickType::WEED:

		player.setWeed(true);
		break;

	case BrickType::BACKTOBEGIN:

		player.getSprite().setPosition(Vector2f(0.f, 0.f));
		playerPosition = 1;
		break;

	}
}

void Brick::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
