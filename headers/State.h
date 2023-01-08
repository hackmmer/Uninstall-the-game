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
#include <map>
#include <stack>
#include <fstream>
#include <sstream>

class State
{

    private:
        std::vector <sf::Texture> textures;
        sf::RenderWindow *window;

    public:
        State(sf::RenderWindow *window);
        virtual ~State();

        virtual void endState() = 0;
        
        /// @brief This called every frame
        /// @param dt Delta Time
        virtual void update(const float& dt) = 0;

        virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

#endif