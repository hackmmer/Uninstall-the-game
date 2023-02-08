#ifndef __E_CLICKABLE_H
#define __E_CLICKABLE_H

#include "Object.h"

namespace eng
{
    class Clickable : public Object
    {

    protected:
        sf::Mouse mouse;
        sf::FloatRect area;

        unsigned short state;
        void (*onClick)(Clickable *self);

    public:
        enum states
        {
            IDLE = 0,
            HOVER,
            PRESSED
        };

        virtual void draw(sf::RenderTarget *window) = 0;
        virtual void update(const float &dt) = 0;

        Clickable(std::string name, sf::Vector2f rect, sf::Vector2f pos);
        virtual ~Clickable();

        void verifyClick(const sf::Vector2f &MousePos);
        void setOnClick(void (*onClick)(Clickable* self));
    };
}
#endif
