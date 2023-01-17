#ifndef __STATE_H
#define __STATE_H
#include "State.h"

class GameState : public State
{

    public:
        GameState(sf::RenderWindow *window);
        virtual ~GameState();

        /// @brief Needed implementation of ``State``
        void endState();
        /// @brief Needed implementation of ``State``
        void update(const float& dt);
        /// @brief Needed implementation of ``State``
        void render(sf::RenderTarget* target);
};
#endif