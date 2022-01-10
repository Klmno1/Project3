#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
class Background
{
private:
	Sprite sprite;
	Texture texture;

public:
	Background();
	virtual ~Background();
	
	void show(RenderTarget* window);
};

 