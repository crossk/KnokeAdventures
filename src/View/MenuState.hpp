#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "../Engine/GameState.hpp"

class MenuState : public GameState
{
public:
    MenuState(Game *game);

    void draw(const float dt);
    void update(const float dt);
    void handleInput();

private:
    sf::View view;

    void loadGame();
};

#endif // MENUSTATE_HPP
