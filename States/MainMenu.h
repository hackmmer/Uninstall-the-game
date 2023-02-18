#ifndef __MAIN_MENU_H
#define __MAIN_MENU_H

#include "State.h"

class MainMenuState : public State
{
    public:
        MainMenuState(sf::RenderWindow *window, std::stack<State *> *states);
        virtual ~MainMenuState();

        void update(const float& dt);
        void render(sf::RenderTarget *window);
        void loadTextures();
        void endStateUpdate();

};

#endif