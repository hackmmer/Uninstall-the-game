#ifndef _GAME_STATE_H
#define _GAME_STATE_H
#include "State.h"

class GameState : public State
{
    protected:
        Player* player;
        void initPlayer();
        eng::Label* Title;
        eng::Button* btn;

    public:
        GameState(sf::RenderWindow *window,  std::stack<State*> *states);
        virtual ~GameState();

        void btn1(eng::Button btn);

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