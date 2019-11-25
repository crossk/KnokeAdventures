#include "MenuState.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../Engine/GameState.hpp"
#include "PlayState.hpp"

MenuState::MenuState(Game *game)
{
    this->game = game;
}



void MenuState::draw(const float dt)
{

}

void MenuState::update(const float dt)
{

}

void MenuState::handleInput()
{
    sf::Event event;

    while(game->window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                game->window.close();
            break;

        case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                {
                    game->window.close();
                }
                else if(event.key.code == sf::Keyboard::Return)
                {
                    loadGame();
                }
        }
    }
}

void MenuState::loadGame()
{
    game->pushState(new PlayState(game));
}
