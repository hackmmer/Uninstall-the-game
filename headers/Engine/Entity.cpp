#include "Entity.h"

void eng::Entity::move(const float x, const float y, const float &dt)
{
    this->x = x * speed * dt;
    this->y = y * speed * dt;
    this->sprite.move(sf::Vector2f(x, y));
}

void eng::Entity::update(const float &dt)
{
}

void eng::Entity::draw(sf::RenderTarget *target)
{

    if (this->visible)
    {
        target->draw(this->sprite);
    }
}

eng::Entity::Entity() : Object("Entity")
{
    // Need the sprite configuration
    this->speed = 100.f;
}

eng::Entity::Entity(std::string name) : Object(name)
{
}

eng::Entity::~Entity()
{
}
