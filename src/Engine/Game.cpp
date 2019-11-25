#include "Game.hpp"
#include "GameState.hpp"

#include "SFML/Graphics.hpp"

Game::Game()
{
    window.create(sf::VideoMode(1024,768), "Knoke Adventure!");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
}

Game::~Game()
{
    while(!states.empty())
    {
        popState();
    }
}

void Game::pushState(GameState *state)
{
    states.push_back(state);
}

void Game::popState()
{
//    states.back();
    delete states.back();
    states.pop_back();
}

GameState *Game::currentState()
{
    if(!states.empty())
    {
        return states.back();
    }
    else
    {
        return nullptr;
    }
}

void Game::gameLoop()
{
    sf::Clock clock;

    while(window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if(currentState() == nullptr)
        {
            continue;
        }
        window.clear();

        currentState()->handleInput();

        currentState()->update(dt);

        currentState()->draw(dt);

        window.display();
    }
}
