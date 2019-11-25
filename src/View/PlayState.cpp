#include "PlayState.hpp"

PlayState::PlayState(Game *game)
{
    this->game = game;
}


void PlayState::draw(const float dt)
{
    sf::RectangleShape rect;
    rect.setPosition(sf::Vector2f(100,100));
    rect.setSize(sf::Vector2f(100,100));
    rect.setFillColor(sf::Color::Green);

    game->window.clear(sf::Color::Black);
    game->window.draw(rect);
}

void PlayState::update(const float dt)
{

}

void PlayState::handleInput()
{
    sf::Event event;

        while (this->game->window.pollEvent(event))
        {
            switch (event.type)
            {
                /* Close the window */
            case sf::Event::Closed:
                this->game->window.close();
                break;

                //pause game
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    pauseGame();
                break;

            }
        }
}

void PlayState::pauseGame()
{

}
