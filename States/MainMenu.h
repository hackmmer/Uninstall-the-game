#ifndef __MAIN_MENU_H
#define __MAIN_MENU_H

#include "State.h"

class MainMenuState : public State
{
    protected:
        eng::Label Title;
    public:
        MainMenuState(sf::RenderWindow *window, std::stack<State *> *states);
        virtual ~MainMenuState();

        void loadRes();
        void endStateUpdate();
        void update(const float& dt);
        void render(sf::RenderTarget *window);

};

#endif