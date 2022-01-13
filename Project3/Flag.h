#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Flag
{
private:
	Sprite sprite;
	Texture texture;


public:
	Flag();
	~Flag();

	Sprite& getSprite();
	int getFlagWidth();
	int getFlagHeight();
	void setPosition(Vector2f position);

	void update(bool& endGame);
	void render(RenderTarget* window);
};

