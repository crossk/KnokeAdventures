#include "SFML/Graphics.hpp"

#include <iostream>

#include "Engine/Game.hpp"
#include "View/MenuState.hpp"

int main(int argc, char* argv[])
{
    std::cout << "Welcome to Knoke Adventures!" << std::endl;
    std::cout << "-- Given program parameters: " << argc;
    std::cout << ", name = " << argv[0];

    Game game;

    game.pushState(new MenuState(&game));

    game.gameLoop();

    return 0;
}
