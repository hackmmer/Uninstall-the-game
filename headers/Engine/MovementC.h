#ifndef __E_MOVEMENT_C
#define __E_MOVEMENT_C

#include "Object.h"

namespace eng
{
    class MovementC : ObjectF
    {
    
    protected:
        sf::Vector2f position;
        sf::Sprite *sprite;

        sf::Vector2f acceleration;
        sf::Vector2f deceleration;
        sf::Vector2f velocity;

        float maxSpeed;

    public:
        float x;
        float y;

        MovementC(sf::Sprite *sprite, float speed = 1);
        virtual ~MovementC();

        void draw(sf::RenderTarget *window);
        void update(const float &dt);

        void move(sf::Vector2f dir, const float &dt);
        void sMove(sf::Vector2f dir, const float &dt);

        void move(const float x, const float y, const float &dt);
        void sMove(const float x, const float y, const float &dt);

        const sf::Vector2f &getVelocity() const;

        const sf::Vector2f &get() const;
        void set(const float x, const float y);
    };
}

#endif