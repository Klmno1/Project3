#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Floor.h"

using namespace sf;

class Player
{
private:
	bool weed;
	RectangleShape shape; // sf
	void initVar();
	void initShape();
	void initPosition(float x = 0.f , float y = 0.f);

	float movementSpeed;
	void updatePlayerPosition(const RenderTarget* target,int& playerPosition, const int maxLevel);
	void updateFloorCollision(const Sprite& floor);
	void updateInput();
	void updateInputWeed();
public:
	Player();
	virtual ~Player();

	RectangleShape& getShape();
	int getWidth();
	int getHeight();
	void setWeed(bool keyBoardInverse);
	
	void update(const RenderTarget* target, const Sprite floor,int& playerPosition,const int maxLevel);
	
	void render(RenderTarget* target); // sf
};

