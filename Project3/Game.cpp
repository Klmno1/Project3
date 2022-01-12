#include "Game.h"

using namespace std;

void Game::initWindow()
{
	this->videoMode = VideoMode(800, 600);
	this->window = new RenderWindow(this->videoMode, "Game", Style::Close | Style::Titlebar);
	// only show close button and the title bar  ;  simply set it to Style::Default
	this->window->setFramerateLimit(60); // set FPS

}

void Game::initVar()
{
	this->maxLevel = 4;
	this->playerPosition = 1;
	this->endGame = false;
}

// constructors & destructors
Game::Game()
{
	this->initVar();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Functions

void Game::update()
{
	this->pollEvents();
	this->player.update(this->window, this->floor.getSprite(), this->playerPosition,this->maxLevel);
	this->map.update(this->playerPosition, this->floor, this->player);
}

void Game::render()
{
	this->window->clear();

	// Render 
	this->background.show(this->window);
	this->player.render(this->window);
	this->map.render(this->window, this->playerPosition);
	this->floor.render(this->window);

	this->window->display();
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->sfmlEvent.key.code == Keyboard::Escape) //sf
				this->window->close();
			break;
		}
	}
}






