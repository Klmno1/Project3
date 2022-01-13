#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include<Windows.h>
#include <ctime>

#include "Floor.h"

using namespace sf;

class Player
{
private:
	clock_t start;
	bool weed;
	int gravity;
	Sprite sprite;
	Texture texture; // sf
	void initVar();
	void initSize();
	void initPosition(float x = 0.f , float y = 0.f);
	float movementSpeed;

	void updateWindowCollision(const RenderTarget* window);
	void updatePlayerPosition(const RenderTarget* target,int& playerPosition, const int maxLevel, const Sprite& floor);
	void updateFloorCollision(const Sprite& floor);
	void updateInput(clock_t now);
	void updateInputWeed(clock_t now);
public:
	Player();
	virtual ~Player();

	void setWeed(bool weed);
	Sprite& getSprite();
	/* int getWidth();
	int getHeight();*/
	void update(const RenderTarget* target, const Sprite floor,int& playerPosition,const int maxLevel, clock_t now, RenderTarget* window);
	
	void render(RenderTarget* target); // sf
};

