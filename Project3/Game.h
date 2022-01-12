#pragma once
#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"  // Player.h include SFML
#include "Background.h"

using namespace sf;
using namespace std;

class Game
{
private:
	int playerPosition;
	int maxLevel;
	VideoMode videoMode; // sf
	RenderWindow* window; // sf
	bool endGame;
	Event sfmlEvent; // sf

	Floor floor;
	Player player;
	Background background;
	Map map;

	void initWindow();
	void initVar();

public:
	// constructors & destructors
	Game();
	~Game();

	// accessors

	// modifier

	// functions
	void update();
	void render();

	const bool running() const; // check if still running 
	void pollEvents();
};