#ifndef __E_BUTTON_H
#define __E_BUTTON_H

#include "Clickable.h"

namespace eng
{

    class Button : public Clickable<Button>
    {
    protected:
        sf::Sprite image;
        std::map<std::string, sf::Texture> textures;
        sf::Texture currentTexture;
        sf::Text *text;
        sf::RenderWindow *window;
        sf::Font *font;
        // T tag;

    public:
        Button(float x, float y, sf::Texture normal, const std::string text, sf::Font font, sf::Color textColor = sf::Color::White, unsigned int textSize = 27);
        virtual ~Button();

        /*
        void setTag(T &tag);
        T &getTag();
*/
        void setTexture(unsigned int stage, sf::Texture &texture);
        sf::Texture &getTexture(unsigned int stage);

        void updateWindow(sf::RenderWindow *window);

        void update(sf::Vector2f &MousePos);
        void draw(sf::RenderTarget *window);
    };

}

#endif