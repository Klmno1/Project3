#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
class Floor
{
private:
	Sprite sprite;
	Texture texture;

public:
	Floor();
	virtual ~Floor();

	const Sprite& getSprite() const;
	int getWidth();
	int getHeight();
	void render(RenderTarget* window);
};

