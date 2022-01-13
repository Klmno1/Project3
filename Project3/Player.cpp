#include "Player.h"



void Player::initVar()
{
	this->movementSpeed = 10.f;
	this->weed = false;
}

void Player::initShape()
{
	this->shape.setFillColor(Color::Blue); //sf::Color
	this->shape.setSize(Vector2f(50.f, 50.f)); // sf::Vector2f
	//this->shape.setPosition(Vector2f(0.f, 0.f));

}

void Player::initPosition(float x,float y)
{
	this->shape.setPosition(Vector2f(x,y)); // set player position
}


Player::Player()
{
	this->initVar();
	this->initShape();
	this->initPosition();
}

Player::~Player()
{

}

RectangleShape& Player::getShape() 
{
	return this->shape;
}

int Player::getWidth()
{
	return this->shape.getSize().x;
}

int Player::getHeight()
{
	return this->shape.getSize().y;
}

void Player::setWeed(bool keyBoardInverse)
{
	this->weed = keyBoardInverse;
}

void Player::updatePlayerPosition(const RenderTarget* target,int& playerPosition, const int maxLevel)
{
	// left
	if (this->shape.getGlobalBounds().left < 0)  // .left() x-axis
	{
		if(playerPosition > 1)
			playerPosition -= 1;
		this->shape.setPosition(Vector2f(target->getSize().x - this->shape.getSize().x, 0.f));
	}

	// right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width > target->getSize().x)
	{
		if(playerPosition != maxLevel)
			playerPosition += 1;
		this->shape.setPosition(Vector2f(0.f, 0.f));
	}
}

void Player::updateFloorCollision(const Sprite& floor)
{
	if (this->shape.getGlobalBounds().intersects(
		floor.getGlobalBounds()
	))
	{
		this->shape.setPosition(Vector2f(
			this->shape.getPosition().x, floor.getPosition().y - this->shape.getSize().y
		));
	}
}


void Player::updateInput()
{
	//Keyboard input   moving character

	if (Keyboard::isKeyPressed(Keyboard::Left)) // sf
	{
		this->shape.move(-1 * this->movementSpeed , 0.f); // move ( Speed on x-axis, Speed on y-axis ) 
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) // sf
	{
		this->shape.move(this->movementSpeed, 0.f); 
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) // sf
	{
		this->shape.move( 0.f , -1 * this->movementSpeed);  // going up is negative
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) // sf
	{
		this->shape.move(0.f , this->movementSpeed); 
	}
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
	target->draw(this->shape);
}
