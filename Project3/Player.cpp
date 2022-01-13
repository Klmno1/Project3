#include "Player.h"
#include <iostream>
using namespace std;


bool direction = 0;
void Player::initVar()
{
	this->movementSpeed = 5.f;
	this->weed = false;
	this->gravity = 10.f;
}

void Player::initSize()
{
	this->texture.loadFromFile("../Project3/Mario_stand_right.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.f,1.f);

}

void Player::initPosition(float x,float y)
{
	this->sprite.setPosition(Vector2f(x,y)); // set player position
}


Player::Player()
{
	this->initVar();
	this->initSize();
	this->initPosition();
}

Player::~Player()
{

}


void Player::setWeed(bool weed)
{
	this->weed = weed;
}

Sprite& Player::getSprite()
{
	return this->sprite;
}


void Player::updateWindowCollision(const RenderTarget* window)
{
	if (this->sprite.getPosition().y < 0.f)
		this->sprite.setPosition(Vector2f(
			this->sprite.getPosition().x,
			0.f
		));
}

void Player::updatePlayerPosition(const RenderTarget* target,int& playerPosition, const int maxLevel, const Sprite& floor)
{

	// left
	if (this->sprite.getPosition().x < 0)  // .left() x-axis
	{
		if(playerPosition > 1)
			playerPosition -= 1;
		this->sprite.setPosition(Vector2f(
			target->getSize().x - this->sprite.getTexture()->getSize().x,
			floor.getPosition().y - this->sprite.getTexture()->getSize().y
		));
	}

	// right
	if (this->sprite.getPosition().x > target->getSize().x)
	{
		if(playerPosition != maxLevel)
			playerPosition += 1;
		this->sprite.setPosition(Vector2f(
			0.f,
			floor.getPosition().y - this->sprite.getTexture()->getSize().y
		));
	}
}

void Player::updateFloorCollision(const Sprite& floor)
{
	if (this->sprite.getGlobalBounds().intersects(
		floor.getGlobalBounds()
	))
	{
		this->sprite.setPosition(Vector2f(
			this->sprite.getPosition().x, floor.getPosition().y - this->sprite.getTexture()->getSize().y
		));
	}
}


void Player::updateInput(clock_t now)
{
	//Keyboard input   moving character

	this->sprite.move(0.f, this->gravity);

	if (direction == 0)
	{
		this->texture.loadFromFile("../Project3/Mario_stand_right.png");
	}
	else
	{
		this->texture.loadFromFile("../Project3/Mario_stand_left.png");
	}

	if (Keyboard::isKeyPressed(Keyboard::Left)) // sf
	{
		this->sprite.move(-1 * this->movementSpeed, 0.f); // move ( Speed on x-axis, Speed on y-axis ) 
		this->texture.loadFromFile("../Project3/Mario_walk_left.png");
		this->texture.loadFromFile("../Project3/Mario_walk_2_left.png");
		this->texture.loadFromFile("../Project3/Mario_walk_3_left.png");
		this->texture.loadFromFile("../Project3/Mario_walk_2_left.png");
		this->texture.loadFromFile("../Project3/Mario_walk_left.png");
		direction = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) // sf
	{
		this->sprite.move(this->movementSpeed, 0.f);
		this->texture.loadFromFile("../Project3/Mario_walk_right.png");
		this->texture.loadFromFile("../Project3/Mario_walk_2_right.png");
		this->texture.loadFromFile("../Project3/Mario_walk_3_right.png");
		this->texture.loadFromFile("../Project3/Mario_walk_2_right.png");
		this->texture.loadFromFile("../Project3/Mario_walk_right.png");
		direction = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) ) // sf
	{
		start = clock();

		this->gravity = -8.f;


		if (direction == 0)
		{
			this->texture.loadFromFile("../Project3/Mario_jump_right.png");
		}
		if (direction == 1)
		{
			this->texture.loadFromFile("../Project3/Mario_jump_left.png");
		}
	}

	if (now - start >= 200)
	{
		this->gravity = 10.f;
	}
		

}

void Player::updateInputWeed(clock_t now)
{
	this->sprite.move(0.f, this->gravity);
	
	if (Keyboard::isKeyPressed(Keyboard::Left)) // sf
	{
		this->sprite.move(1 * this->movementSpeed, 0.f); // move ( Speed on x-axis, Speed on y-axis ) 
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) // sf
	{
		this->sprite.move(-1 * this->movementSpeed, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) // sf
	{
		this->sprite.move(0.f, 1 * this->movementSpeed);  // going up is negative
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) // sf
	{
		this->sprite.move(0.f, -1 * this->movementSpeed);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) // sf
	{
		start = clock();

		this->gravity = -8.f;


		if (direction == 0)
		{
			this->texture.loadFromFile("../Project3/Mario_jump_right.png");
		}
		if (direction == 1)
		{
			this->texture.loadFromFile("../Project3/Mario_jump_left.png");
		}
	}

	if (now - start >= 200)
	{
		this->gravity = 10.f;
	}

	this->sprite.rotate(15.f);
}

void Player::update(const RenderTarget* target, const Sprite floor, int& playerPosition, const int maxLevel, clock_t now, RenderTarget* window)
{
	this->updateWindowCollision(target);
	this->updatePlayerPosition(target, playerPosition, maxLevel, floor);
	this->updateFloorCollision(floor);
	if (!this->weed)
		this->updateInput(now);
	else
		this->updateInputWeed(now);
}


void Player::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
