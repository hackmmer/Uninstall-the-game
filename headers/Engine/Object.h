#ifndef __E_OBJECT_H
#define __E_OBJECT_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <fstream>
#include <sstream>


namespace eng
{
    class Object
    {
        public:
            std::string name;
            bool visible = true;

            Object();
            Object(std::string name);
            virtual ~Object();

            virtual void draw(sf::RenderTarget* window) = 0;
            virtual void update(const float& dt) = 0;
    };
}
#endif