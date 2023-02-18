#ifndef _GAME_STATE_H
#define _GAME_STATE_H
#include "State.h"

class GameState : public State
{
protected:
    Player *player;
    void initPlayer();
    bool f5;

public:
    GameState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~GameState();

    void btn1();

    void endStateUpdate();

    /// @brief Here we load all the textures of the scene
    void loadRes();
    /// @brief Needed implementation of ``State``
    void endState();
    /// @brief Needed implementation of ``State``
    void update(const float &dt);
    /// @brief Needed implementation of ``State``
    void render(sf::RenderTarget *target);
};
#endif