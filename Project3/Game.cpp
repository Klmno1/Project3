#include "Game.h"

using namespace std;

void Game::initFont()
{
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}

void Game::initEndGameText()
{
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(Color::Red);
	this->endGameText.setCharacterSize(64);
	this->endGameText.setPosition(Vector2f(100, 200));
	this->endGameText.setString("GAME END! EXIT THE GAME");
}

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
	this->initFont();
	this->initEndGameText();
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
	this->map.update(this->playerPosition, this->floor, this->player, this->endGame);
}

void Game::render()
{
	this->window->clear();

	// Render
	if (not this->endGame)
	{
		this->background.show(this->window);
		this->player.render(this->window);
		this->map.render(this->window, this->playerPosition);
		this->floor.render(this->window);
	}
	else
	{
		this->window->draw(this->endGameText);
	}
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






