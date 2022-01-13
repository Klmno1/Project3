#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include<Windows.h>
#include <ctime>

#include "Floor.h"

using namespace sf;

class Player
{
private:
	bool weed;
	bool jumping;
	int gravity;
	RectangleShape shape; // sf
	Sprite sprite;
	Texture texture; // sf
	void initVar();
	void initSize();
	void initPosition(float x = 0.f , float y = 0.f);

	float movementSpeed;
	void updatePlayerPosition(const RenderTarget* target,int& playerPosition, const int maxLevel);
	void updateFloorCollision(const Sprite& floor);
	void updateInput();
	void updateInputWeed();
public:
	Player();
	virtual ~Player();

	Sprite& getShape();
	/* int getWidth();
	int getHeight();*/
	void update(const RenderTarget* target, const Sprite floor,int& playerPosition,const int maxLevel);
	
	void render(RenderTarget* target); // sf
};

