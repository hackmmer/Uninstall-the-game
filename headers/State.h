#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>

class State
{

    private:
        std::vector <sf::Texture> textures;

    public:
        State();
        virtual ~State();
        virtual void update() = 0;
        virtual void render() = 0;

};

#endif