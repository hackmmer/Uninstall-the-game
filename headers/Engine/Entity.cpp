#include "Entity.h"

void eng::Entity::createMovementC(sf::Sprite *sprite, float maxSpeed)
{
    this->movement = new eng::MovementC(sprite);
}

void eng::Entity::draw(sf::RenderTarget *target)
{

    if (this->visible)
    {
        if (this->movement)
            this->movement->draw(target);
    }
}

void eng::Entity::loadSprite(sf::Texture *texture)
{
    this->EntityTexture = texture;
    this->sprite = new sf::Sprite(*this->EntityTexture);
    this->movement = new eng::MovementC(this->sprite, this->speed);
}

void eng::Entity::setPosition(const float x, const float y)
{
    if (this->sprite)
        this->sprite->setPosition(x, y);
}

eng::Entity::Entity() : ObjectF("Entity")
{
    // Need the sprite configuration
    this->speed = 100.f;
}

eng::Entity::Entity(std::string name) : ObjectF(name)
{
    this->sprite = nullptr;
    this->EntityTexture = nullptr;
    this->speed = 100.f;
}

eng::Entity::~Entity()
{
    delete this->sprite;
}
