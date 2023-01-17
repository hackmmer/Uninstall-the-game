#ifndef __E_ENTITY_H
#define __E_ENTITY_H

#include <Engine/Engine.h>

namespace eng
{
    class Entity : public Object
    {
        protected:
            sf::Sprite sprite;

        public:
            Entity();
            Entity(std::string name);
            virtual ~Entity();


    };

}

#endif