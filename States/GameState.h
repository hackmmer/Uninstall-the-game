#ifndef __STATE_H
#define __STATE_H
#include "State.h"

class GameState : public State
{

    public:
        GameState(sf::RenderWindow *window);
        virtual ~GameState();

        void endState();
        void update(const float& df);
        void render(sf::RenderTarget* target);
};
#endif