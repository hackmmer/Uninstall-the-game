#ifndef __E_PROGRESS_BAR_H
#define __E_PROGRESS_BAR_H

#include "Object.h"

namespace eng
{

    class ProgressBar : public Object
    {
    protected:
        sf::Sprite sfMarco;
        sf::Sprite sfBackground;
        sf::RectangleShape sfFiller;
        sf::Text sfText;

    public:
        ProgressBar(float min, float max, float x, float y, sf::Color barColor, std::string marco, std::string bg, std::string font);
        virtual ~ProgressBar();

        float max;
        float min;
        float value;
        std::string text;

        void draw(sf::RenderTarget *window);
        void update(const float &dt);
    };
}
#endif