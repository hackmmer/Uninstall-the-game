#ifndef __E_CLICKABLE_H
#define __E_CLICKABLE_H

#include "Object.h"

namespace eng
{
    class Clickable : public Object
    {

    private:
        sf::Mouse mouse;
        sf::Vector2f mousePos;
        bool _hover;
        sf::FloatRect area;

    protected:
        void (*onClick)();

    public:
        virtual void draw(sf::RenderTarget *window) = 0;
        virtual void update(const float &dt) = 0;

        Clickable(std::string name, sf::Vector2f rect, sf::Vector2f pos);
        virtual ~Clickable();

        bool isHover();
        void verifyClick();
        void setOnClick(void (*onClick)());
    };
}
#endif
