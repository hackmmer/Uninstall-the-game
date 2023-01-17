#include "Entity.h"

void eng::Entity::move(int direction)
{
    if(direction == 0) // UP
    {

    }
    else if (direction == 1) // DOWN
    {

    }
    else if (direction == 2) // RIGHT
    {

    }else if (direction == 3) // DOWN
    {

    }
}

void eng::Entity::move(const float x, const float y, const float &dt)
{
    this->x = x * speed * dt;
    this->y = y * speed * dt;
    this->sprite.move(sf::Vector2f(x, y));
}

void eng::Entity::draw(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}

eng::Entity::Entity() : Object("Entity")
{
    this->sprite.setSize(sf::Vector2f(20.f, 20.f));
    this->sprite.setFillColor(sf::Color::White);
    this->speed = 100.f;
}

eng::Entity::Entity(std::string name) : Object(name)
{
}

eng::Entity::~Entity()
{
}
