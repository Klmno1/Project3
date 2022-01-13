#include "Player.h"


bool direction = 0;
void Player::initVar()
{
	this->movementSpeed = 10.f;
	this->weed = false;
	this->jumping = false;
	this->gravity = 3.f;
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


Sprite& Player::getShape()
{
	return this->sprite;
}
/*
int Player::getWidth()
{
	return this->shape.getSize().x;
}

int Player::getHeight()
{
	return this->shape.getSize().y;
}
*/

void Player::setWeed(bool keyBoardInverse)
{
	this->weed = keyBoardInverse;
}

void Player::updatePlayerPosition(const RenderTarget* target,int& playerPosition, const int maxLevel)
{
	// left
	if (this->sprite.getGlobalBounds().left < 0)  // .left() x-axis
	{
		if(playerPosition > 1)
			playerPosition -= 1;
		this->sprite.setPosition(Vector2f(target->getSize().x - this->sprite.getTexture()->getSize().x, 0.f));
	}

	// right
	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width > target->getSize().x)
	{
		if(playerPosition != maxLevel)
			playerPosition += 1;
		this->sprite.setPosition(Vector2f(0.f, 0.f));
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


void Player::updateInput()
{
	//Keyboard input   moving character
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
	bool jump = 0;
	if (Keyboard::isKeyPressed(Keyboard::Space)) // sf
	{
		if (direction == 0)
		{
			this->texture.loadFromFile("../Project3/Mario_jump_right.png");
			this->sprite.move(0.f, -1 * this->movementSpeed);
		}
		if (direction == 1)
		{
			this->texture.loadFromFile("../Project3/Mario_jump_left.png");
			this->sprite.move(0.f, -1 * this->movementSpeed);
		}
		jump = 1;
	}


	else if (Keyboard::isKeyPressed(Keyboard::Down)) // sf
	{
		this->sprite.move(0.f, this->movementSpeed);
	}
	if (jump == 1)
	{
		Sleep(5000);
		this->sprite.move(0.f, 1 * this->movementSpeed);
		jump == 0;
	}
	/*
	if (jump == 1)
	{
		this->texture.loadFromFile("../Project3/Mario_jump_right.png");
		for (int i = 10; i >= 10; i--)
		{
			this->sprite.move(0.f, -1 * i * 0.05 * this->movementSpeed);  // going up is negative

		}
		clock_t   now = clock();
		time_t times = 10;
		while (clock() - now < times)
		{

		}
		for (int i = 10; i >= 10; i--)
		{
			this->sprite.move(0.f, i * 0.05 * this->movementSpeed);  // going up is negative

		}

		//this->sprite.move(0.f, this->velocity.y);
	}*/
}

void Player::updateInputWeed()
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) // sf
	{
		this->shape.move(1 * this->movementSpeed, 0.f); // move ( Speed on x-axis, Speed on y-axis ) 
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) // sf
	{
		this->shape.move(-1 * this->movementSpeed, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) // sf
	{
		this->shape.move(0.f, 1 * this->movementSpeed);  // going up is negative
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) // sf
	{
		this->shape.move(0.f, -1 * this->movementSpeed);
	}
	this->shape.rotate(15.f);
}

void Player::update(const RenderTarget* target, const Sprite floor, int& playerPosition, const int maxLevel)
{
	this->updatePlayerPosition(target, playerPosition, maxLevel);
	this->updateFloorCollision(floor);
	if (!this->weed)
		this->updateInput();
	else
		this->updateInputWeed();
}


void Player::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
