#ifndef __GAME_H
#define __GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <ctime>

class Game{
    private:

        // Vars
        sf::RenderWindow *window;
        sf::Event sfEvent;

        // Funcs
        void initWindow();

    public:

        Game();
        virtual ~Game();

        // Funcs
        void updateSFMLEvents();
        void render();
        void update();
        void run();
};
#endif