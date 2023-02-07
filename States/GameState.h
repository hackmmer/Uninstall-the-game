#ifndef __STATE_H
#define __STATE_H
#include "State.h"

class GameState : public State
{
    protected:
        Player* player;
        void initPlayer();

    public:
        GameState(sf::RenderWindow *window,  std::stack<State*> *states);
        virtual ~GameState();


        /// @brief Here we load all the textures of the scene
        void loadTextures();
        /// @brief Needed implementation of ``State``
        void endState();
        /// @brief Needed implementation of ``State``
        void update(const float& dt);
        /// @brief Needed implementation of ``State``
        void render(sf::RenderTarget* target);
};
#endif