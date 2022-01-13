#pragma once
#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"  // Player.h include SFML
#include "Background.h"
#include "Map.h"

using namespace sf;
using namespace std;

class Game
{
private:

	Music backgroundMusic;

	clock_t now;
	Text startGameText;
	Text endGameText;
	Text failGameText;
	Font font;

	int playerPosition;
	int maxLevel;
	VideoMode videoMode; // sf
	RenderWindow* window; // sf
	bool startGame;
	bool endGame;
	bool failGame;
	Event sfmlEvent; // sf

	Floor floor;
	Player player;
	Background background;
	Map map;

	void initMusic();
	void initFont();
	void initEndGameText();
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