#ifndef __E_ENTITY_H
#define __E_ENTITY_H

#include "Object.h"

namespace eng
{
    class Entity : public Object
    {
    protected:
        sf::Sprite* sprite;
        sf::Texture* EntityTexture;
        float speed;

        float x;
        float y;

    public:
        void move(float x, float y, const float &dt);

        void update(const float &dt);
        void draw(sf::RenderTarget *target);

        void loadSprite(sf::Texture* texture);
        void setPosition(const float x, const float y);

        Entity();
        Entity(std::string name);
        virtual ~Entity();
    };

}

#endif