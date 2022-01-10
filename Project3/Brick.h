#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Brick
{
private:
	Sprite sprite;
	Texture texture;

public:
	Brick();
	~Brick();
};

