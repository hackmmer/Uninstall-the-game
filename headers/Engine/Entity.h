#ifndef __E_ENTITY_H
#define __E_ENTITY_H

#include <Engine/Engine.h>

namespace eng
{
    

    class Entity : public Object
    {
        protected:
            sf::Sprite sprite;
            float speed;

            float x;
            float y;

        public:
            const static int UP = 0;
            const static int DOWN = 1;
            const static int RIGHT = 2;
            const static int LEFT = 3;


            void move(int direction);
            void move(float x, float y, const float& dt);

            void draw(sf::RenderTarget* target);

            Entity();
            Entity(std::string name);
            virtual ~Entity();


    };

}

#endif