#pragma once
#include <iostream>
#include <ctime>

#include "Player.h"  // Player.h include SFML
#include "Background.h"
#include "Map.h"
using namespace sf;
using namespace std;

class Game
{
private:

	VideoMode videoMode; // sf
	RenderWindow* window; // sf
	bool endGame;
	Event sfmlEvent; // sf

	Player player;
	Background background;

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