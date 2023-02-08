#ifndef __E_BUTTON_H
#define __E_BUTTON_H

#include "Clickable.h"

namespace eng
{
    
    template <typename T>
    class Button : public Clickable
    {
    protected:
        sf::Sprite image;
        std::map<std::string, sf::Texture> textures;
        
        sf::Text text;
        T tag;
    public:
        Button(float x, float y, sf::Texture &normal, const std::string text, sf::Font font, sf::Color textColor = sf::Color::White, unsigned int textSize = 27);
        virtual ~Button();

        void setTag(T &tag);
        T &getTag();

        void setTexture(unsigned int stage, sf::Texture& texture);
        sf::Texture& getTexture(unsigned int stage);

        void update(const float &dt);
        void draw(sf::RenderTarget *window);
    };

}

#endif