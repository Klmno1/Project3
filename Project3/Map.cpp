#include <iostream>

#include "Map.h"

using namespace std;
bool check = true;
bool check1 = true;

Map::Map()
{
	this->brickNumber = BRICK1;
	this->pipeNumber = PIPE1;
	this->enemyNumber = ENEMY2;
	this->initTexture();
	this->spawnPipe();
	this->spawnBrick();
	this->spawnEnemy();

}

Map::~Map()
{
	for (auto& i : this->texture)
	{
		delete i.second;
	}
	for (auto* i : this->pipe)
	{
		delete i;
	}
	for (auto* i : this->brick)
	{
		delete i;
	}
	for (auto* i : this->enemy)
	{
		delete i;
	}

}

void Map::changeBrickNum(const int playerPosition)
{
	switch (playerPosition)
	{
	case LEVEL1:
		this->brickNumber = BRICK1;
		break;

	case LEVEL2:
		this->brickNumber = BRICK2;
		break;

	case LEVEL3:
		this->brickNumber = BRICK3;
		break;

	case LEVELLAST:
		this->brickNumber = BRICK4;
		break;
	}
	
}

void Map::changePipeNum(const int playerPosition)
{
	switch (playerPosition)
	{
	case LEVEL1:
		this->pipeNumber = PIPE1;
		break;

	case LEVEL2:
		this->pipeNumber = PIPE2;
		break;

	case LEVEL3:

		this->pipeNumber = PIPE3;
		break;

	case LEVELLAST:
		this->pipeNumber = PIPE4;
		break;
	}
}

void Map::spawnBrick()
{
	for (int i = 0; i < BRICK3; i++)
	{
		this->brick.push_back(new Brick(this->texture["BRICK"]));
	}
}

void Map::spawnPipe()
{	
	for (int i = 0; i < PIPE2; i++)
	{
		this->pipe.push_back(new Pipe(this->texture["PIPE"]));
	}
	
}

void Map::spawnEnemy()
{
	for (int i = 0; i < ENEMY2; i++)
	{
		this->enemy.push_back(new Enemy(i));
	}
}

void Map::initTexture()
{
	this->texture["BRICK"] = new Texture();
	this->texture["PIPE"] = new Texture();
	this->texture["BLOCK"] = new Texture();


	this->texture["BRICK"]->loadFromFile("../Project3/Brick.png");
	this->texture["PIPE"]->loadFromFile("../Project3/Pipe.png");
	this->texture["BLOCK"]->loadFromFile("../Project3/Block.png");
}

void Map::initPosition(const int playerPosition, const Floor floor)
{
	this->brickPosition.clear();
	this->pipePosition.clear();
	int firstrow = 4;
	switch (playerPosition)
	{
	case LEVEL1:
		
		for (int i = 0; i < firstrow; i++)
		{
			this->brickPosition.push_back(Vector2f(
				200.f + static_cast<float>(i) * (*this->brick[0]).getBrickWidth(), 300.f
			));
		}

		for (int i = 0; i < this->brickNumber - firstrow; i++)
		{
			this->brickPosition.push_back(Vector2f(
				250.f + static_cast<float>(i) * (*this->brick[0]).getBrickWidth(),
				200.f - (*this->brick[i]).getBrickHeight())
			);
		}

		this->pipePosition.push_back(Vector2f(600.f,  300.f));
		break;

	case LEVEL2:
		for (int i = 0; i < this->pipeNumber; i++)
		{
			this->pipePosition.push_back(Vector2f(
				100.f + static_cast<float>(i)*this->pipe[0]->getPipeWidth() + static_cast<float>(i) * 30.f,
				350.f - static_cast <float> (i) *50.f
			));
		}

		for (int i = 0; i < this->enemyNumber; i++)
		{
			this->enemyPosition.push_back(Vector2f(
				this->pipePosition[i].x + 25.f,
				450.f + static_cast<float>(i) * 40.f
			));
		}
		
		if (check1)
		{
			check1 = false;
			this->setEnemyPosition();
		}

		break;

	case LEVEL3:

		for (int i = 0; i < this->brickNumber; i++)
		{
			if (i % 2 == 0)
			{
				this->brickPosition.push_back(Vector2f(
					150.f + static_cast<float>(i / 2) * 200.f,
					floor.getSprite().getPosition().y - this->brick[0]->getBrickHeight()
				));
			}
			else
			{
				this->brickPosition.push_back(Vector2f(
					150.f + static_cast<float>(i / 2) * 200.f,
					static_cast <float> (floor.getSprite().getPosition().y - 2*this->brick[0]->getBrickHeight())
				));
			} 
		}

		this->blackhole.setPosition(Vector2f(
			180.f,
			floor.getSprite().getPosition().y
		));
		break;

	case LEVELLAST:

		this->pipePosition.push_back(Vector2f(
			100.f, floor.getSprite().getPosition().y - 150.f
		));

		for (int i = 0; i < this->brickNumber; i++)
		{
			this->brickPosition.push_back(Vector2f(
				250.f + 2.5 * i * this->brick[0]->getBrickWidth(),
				250.f - 2 * i * this->brick[0]->getBrickHeight()
			));
		}

		this->pole.getSprite().setPosition(Vector2f(700.f, 50.f));

		if (check) // flag 位置只要設定一次就好
		{
			this->flag.getSprite().setPosition(Vector2f(
				this->pole.getSprite().getPosition().x,
				this->pole.getSprite().getPosition().y
			));
			check = false;
		}

		this->blackhole.setPosition(Vector2f(
			250.f,
			floor.getSprite().getPosition().y
		));
		

		break;
	}
	
	this->setBrickPosition();
	this->setPipePosition();
}

void Map::setBrickPosition()
{
	for (int i = 0; i < this->brickNumber; i++)
	{
		(*this->brick[i]).setPosition(this->brickPosition[i]);
	}
}

void Map::setPipePosition()
{
	for (int i = 0; i < this->pipeNumber; i++)
	{
		(*this->pipe[i]).setPosition(this->pipePosition[i]);
	}
}

void Map::setEnemyPosition()
{
	for (int i = 0; i < this->enemyNumber; i++)
	{
		(*this->enemy[i]).setPosition(this->enemyPosition[i]);
	}
}

void Map::update(int& playerPosition, const Floor floor, Player& player, bool& endGame, bool& failGame)
{
	for (int i = 0; i < this->brickNumber; i++)  // will change playerPosition if the player touches bricks which bring you back to beginning
	{
		if ((*this->brick[i]).checkCollision(player, playerPosition))
		{
			(*this->brick[i]).getSprite().setTexture(*this->texture["BLOCK"]);
		}
	}

	this->changePipeNum(playerPosition);
	this->changeBrickNum(playerPosition);

	this->initPosition(playerPosition, floor);

	for (int i = 0; i < this->pipeNumber; i++)
	{
		(*this->pipe[i]).update(player);
	}

	if (this->pole.updateCollision(player, playerPosition))
	{
		this->flag.update(endGame, playerPosition, LEVEL::LEVELLAST);
	}

	if (playerPosition == LEVEL2)
	{
		for (int i = 0; i < this->enemyNumber; i++)
		{
			(*this->enemy[i]).update();
		}
		
		for (int i = 0; i < this->enemyNumber; i++)
		{
			(*this->enemy[i]).updateCollision(player, playerPosition, floor);
		}
	}

	this->blackhole.updateCollision(player, playerPosition, floor, failGame);
	
}

void Map::render(RenderTarget* window, const int playerPosition)
{

	for (int i = 0; i < this->brickNumber; i++)
	{
		(*this->brick[i]).render(window);
	}


	if (playerPosition == LEVEL2)
	{
		for (int i = 0; i < this->enemyNumber; i++)
		{
			(*this->enemy[i]).render(window);
		}
	}

	for (int i = 0; i < this->pipeNumber; i++)
	{
		(*this->pipe[i]).render(window);
	}

	if (playerPosition == LEVEL3)
	{
		this->blackhole.render(window);
	}

	if (playerPosition == LEVELLAST)
	{
		this->blackhole.render(window);
		this->pole.render(window);
		this->flag.render(window);
	}
}


