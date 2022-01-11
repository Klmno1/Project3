#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Pipe
{
private:
	Sprite sprite;

public:
	Pipe();
	Pipe(Texture* texture);
	~Pipe();

	int getPipeWidth();
	int getPipeHeight();
	void setPosition(Vector2f position);
	void render(RenderTarget* window);
};

