#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(int enemySerial)
{
	this->movement = -4.f;

	switch (enemySerial)
	{
	case 0:
		this->texture.loadFromFile("../Project3/Enemy1.png");
		break;

	case 1:
		this->texture.loadFromFile("../Project3/Enemy2.png");
		break;

	case 2:
		this->texture.loadFromFile("../Project3/Enemy3.png");
		break;

	case 3:
		this->texture.loadFromFile("../Project3/Enemy4.png");
		break;

	}

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(Vector2f(701.f, 701.f)); // 要等到 到 LEVEL2 才會 setposition ( 不設 預設 0,0 player 會被吸住 )
}

Enemy::~Enemy()
{
}

void Enemy::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

void Enemy::update()
{
	this->sprite.move(Vector2f(0.f, this->movement));
	if (this->sprite.getPosition().y == 50.f)
		this->movement = 4.f ;
	if (this->sprite.getPosition().y == 550.f)
		this->movement = -2.f;
}

void Enemy::updateCollision(Player& player, int& playerPosition, const Floor floor)
{
	if (this->sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
	{
		player.getSprite().setPosition(Vector2f(0.f, floor.getSprite().getPosition().y));
		playerPosition = 1;
	}
}

const Sprite& Enemy::getSprite() const
{
	return this->sprite;
}

int Enemy::getWidth()
{
	return this->sprite.getTexture()->getSize().x;
}

int Enemy::getHeight()
{
	return this->sprite.getTexture()->getSize().y;
}

void Enemy::render(RenderTarget* window)
{
	window->draw(this->sprite);
}