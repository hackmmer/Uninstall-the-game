#ifndef __E_CLICKABLE_H
#define __E_CLICKABLE_H

#include "Object.h"

namespace eng
{
    template <class Child>
    class Clickable : public Object<sf::Vector2f &>
    {

    private:
        bool hasPressed;

    protected:
        sf::Mouse mouse;
        sf::FloatRect *area;

        unsigned short state;
        std::function<void(Child *)> onClick;
        Child *context;
        bool clickByPointer;

        bool clicked;
        bool justClicked;
        bool mIn; // Mouse Inside

    public:
        enum states
        {
            IDLE = 0,
            HOVER,
            PRESSED
        };

        virtual void draw(sf::RenderTarget *window) = 0;
        virtual void update(sf::Vector2f &mousePos) = 0;

        Clickable(std::string name, sf::Vector2u rect, sf::Vector2f pos);
        virtual ~Clickable();

        bool isPressed();
        bool isJustPressed();
        void setClickByPressing(bool click);

        void verifyClick(const sf::Vector2f &MousePos);
        void setOnClick(std::function<void(Child *)> onClick, Child *context);
    };
}
#endif
