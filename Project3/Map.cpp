#include <iostream>

#include "Map.h"

using namespace std;

Map::Map()
{
	this->Bricknumber = 6;
	this->initTexture();
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

}


void Map::spawnBrick()
{
	for (int i = 0; i < this->Bricknumber; i++)
	{
		this->brick.push_back(new Brick(this->texture["BRICK"]));
	}
}

void Map::spawnPipe()
{
	this->pipe.push_back(new Pipe(this->texture["PIPE"]));
}

void Map::initTexture()
{
	this->texture["BRICK"] = new Texture();
	this->texture["PIPE"] = new Texture();
	this->texture["BRICK"]->loadFromFile("../Project3/Brick.png");
	this->texture["PIPE"]->loadFromFile("../Project3/Pipe.png");
}

void Map::initPosition()
{
	
	for (int i = 0; i < 4; i++)
	{
		this->brickPosition.push_back(Vector2f(200.f + static_cast<float>(i) * (*this->brick[i]).getBrickWidth(), 300.f));
	}
	
	for (int i = 0; i < 2; i++)
	{
		this->brickPosition.push_back(Vector2f(250.f + i * (*this->brick[i]).getBrickWidth(),
			200.f - (*this->brick[i]).getBrickHeight())
		);
	}

	this->pipePosition.push_back(Vector2f(600.f, 350.f));
	this->setBrickPosition();
	this->setPipePosition();
}

void Map::setBrickPosition()
{
	for (int i = 0; i < brick.size(); i++)
	{
		(*this->brick[i]).setPosition(this->brickPosition[i]);
	}
}

void Map::setPipePosition()
{
	for (int i = 0; i < pipe.size(); i++)
	{
		(*this->pipe[i]).setPosition(this->pipePosition[i]);
	}
}

void Map::update()
{
	this->spawnPipe();
	this->spawnBrick();
	this->initPosition();
}

void Map::render(RenderTarget* window)
{
	for (auto* i : this->brick)
	{
		i->render(window);
	}
	for (auto* i : this->pipe)
	{
		i->render(window);
	}
}


