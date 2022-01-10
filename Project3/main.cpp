#include "Game.h"
using namespace sf;
using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(0)));

    // initialize game obj
    Game game;

    // game loop
    while (game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}