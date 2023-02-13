#ifndef __E_LABEL_H
#define __E_LABEL_H

#include "Object.h"

namespace eng
{
    class Label : public Object<const float &>
    {
    protected:
        sf::Text self;

    public:
        std::string text;
        uint size;
        float x;
        float y;
        sf::Font font;
        sf::Color color = sf::Color::White;

        Label(std::string text, const uint &size, const float &x, const float &y, sf::Font font);
        virtual ~Label();

        void draw(sf::RenderTarget *window);
        void update(const float &dt);
    };
}
#endif