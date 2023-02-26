#ifndef __E_ENTITY_H
#define __E_ENTITY_H

#include "Object.h"

namespace eng
{
    class Entity : public Object<const float &>
    {
    protected:
        sf::Sprite *sprite;
        sf::Texture *EntityTexture;

        sf::Rect<float> colisionArea;

    public:
        float speed;

        float x;
        float y;

        virtual void move(float x, float y, const float &dt);

        virtual void update(const float &dt) = 0;
        virtual void draw(sf::RenderTarget *target);

        void loadSprite(sf::Texture *texture);
        void setPosition(const float x, const float y);

        Entity();
        Entity(std::string name);
        virtual ~Entity();
    };

}

#endif