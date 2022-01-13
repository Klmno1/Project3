#include "Game.h"

using namespace std;

void Game::initMusic()
{
	this->backgroundMusic.openFromFile("../Project3/Music/Background.ogg");
	this->backgroundMusic.setLoop(true);
	this->backgroundMusic.setVolume(60.f);

}

void Game::initFont()
{
	this->font.loadFromFile("../Project3/Fonts/Dosis-Light.ttf");
}

void Game::initEndGameText()
{
	this->startGameText.setFont(this->font);
	this->startGameText.setFillColor(Color::Blue);
	this->startGameText.setCharacterSize(85);
	this->startGameText.setPosition(Vector2f(85, 200));
	this->startGameText.setString("       Start Escaping \n  Press Enter to start");

	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(Color::Red);
	this->endGameText.setCharacterSize(75);
	this->endGameText.setPosition(Vector2f(85, 200));
	this->endGameText.setString("Congratulation! \n You Pass the PD Class");

	this->failGameText.setFont(this->font);
	this->failGameText.setFillColor(Color::Red);
	this->failGameText.setCharacterSize(85);
	this->failGameText.setPosition(Vector2f(100, 200));
	this->failGameText.setString("Fail! \nYOU ARE FLUNKED");
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
	this->startGame = true;
	this->failGame = false;
}

// constructors & destructors
Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initFont();
	this->initEndGameText();
	this->initMusic();
}

Game::~Game()
{
	delete this->window;
}

//Functions

void Game::update()
{
	//this->backgroundMusic.play();
	this->now = clock();
	this->pollEvents();
	this->player.update(this->window, this->floor.getSprite(), this->playerPosition,this->maxLevel, this->now, this->window);
	this->map.update(this->playerPosition, this->floor, this->player, this->endGame, this->failGame);
}

void Game::render()
{
	this->window->clear();

	if (this->startGame)
	{
		this->window->draw(this->startGameText);
		if (Keyboard::isKeyPressed(Keyboard::Enter))
			this->startGame = false;
	}
	else {
		if (not this->endGame)
		{
			this->background.show(this->window);
			this->floor.render(this->window);
			this->player.render(this->window);
			this->map.render(this->window, this->playerPosition);
		}
		else
		{
			this->window->clear();
			this->window->draw(this->endGameText);
		}

		if (this->failGame)
		{
			this->window->clear();
			this->window->draw(this->failGameText);
		}
	}
	// Render
	
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






