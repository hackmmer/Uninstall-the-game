#ifndef __E_BUTTON_H
#define __E_BUTTON_H

#include <Engine/Engine.h>

namespace eng
{
    template <typename T>
    class Button: public Object
    {
        private:
            sf::Mouse mouse;
            sf::Vector2f mousePos;

        protected:
            sf::Sprite image;
            sf::Texture normal;
            sf::Texture hover;
            sf::Texture pressed;
            sf::Text text;

            T tag;

            void (*onClick)();

        public: 
            Button(float x, float y, sf::Texture& image, sf::Texture& hover, sf::Texture& pressed, const std::string& text);
            

            virtual ~Button();

            void setOnClick(void (*onClick)());
            void setTag(T& tag);
            T& getTag();

            void update(const float& dt);
            void draw(sf::RenderTarget *window);
    };
}

#endif