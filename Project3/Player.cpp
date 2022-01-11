#include "Player.h"

void Player::initVar()
{
	this->movementSpeed = 5.f;
}

void Player::initShape()
{
	this->shape.setFillColor(Color::Blue); //sf::Color
	this->shape.setSize(Vector2f(50.f, 50.f)); // sf::Vector2f
	//this->shape.setPosition(Vector2f(0.f, 0.f));

}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y); // set player position

	this->initVar();
	this->initShape();
}

Player::~Player()
{

}

int Player::getWidth()
{
	return this->shape.getSize().x;
}

int Player::getHeight()
{
	return this->shape.getSize().y;
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

void Player::update()
{
	//Window bounds collision

	this->updateInput();
}

void Player::render(RenderTarget* target)
{
	target->draw(this->shape);
}
