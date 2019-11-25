#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "../Engine/GameState.hpp"

class PlayState : public GameState
{
public:
    PlayState(Game *game);

    void draw(const float dt);
    void update(const float dt);
    void handleInput();

private:
    void pauseGame();
};

#endif // PLAYSTATE_HPP
