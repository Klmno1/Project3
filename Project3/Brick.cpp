#include "Brick.h"


Brick::Brick()
{
	this->type = BrickType::UNBREAKABLE;
	this->afterBreak.loadFromFile("../Project3/Block.jfif");
}

Brick::Brick(Texture* texture)
{
	this->sprite.setTexture(*texture);
	//this->sprite.scale(0.7f, 0.7f);
	this->type = BrickType::UNBREAKABLE;
}

Brick::~Brick()
{
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

void Brick::updateCollision(Player& player)
{
	if (this->sprite.getGlobalBounds().intersects(player.getShape().getGlobalBounds()))
	{
		if (this->sprite.getPosition().y > player.getShape().getPosition().y)
		{
			this->sprite.setTexture(this->afterBreak);
		}
	}
}

void Brick::update(Player& player)
{
	this->updateCollision(player);
}

void Brick::render(RenderTarget* window)
{
	window->draw(this->sprite);
}
