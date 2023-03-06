#include "MovementC.h"

eng::MovementC::MovementC(sf::Sprite *sprite, float speed) : ObjectF("MovementC")
{
    this->position = sf::Vector2f(0, 0);
    this->sprite = sprite;
    this->maxSpeed = speed;
}

eng::MovementC::~MovementC()
{
}

void eng::MovementC::draw(sf::RenderTarget *window)
{
    if(this->visible)
    {
        if (this->sprite)
            window->draw(*this->sprite);
    }
}

void eng::MovementC::update(const float &dt)
{
    this->x, this->y = this->position.x, this->position.y;
}

void eng::MovementC::move(sf::Vector2f dir, const float &dt)
{
    if (this->sprite)
    {
        dir *= dt * this->maxSpeed;
        this->sprite->move(dir);
    }
}

void eng::MovementC::sMove(sf::Vector2f dir, const float &dt)
{
    if (this->sprite)
    {
    }
}

void eng::MovementC::move(const float x, const float y, const float &dt)
{
    this->move(sf::Vector2f(x, y), dt);
}

void eng::MovementC::sMove(const float x, const float y, const float &dt)
{
    this->sMove(sf::Vector2f(x, y), dt);
}

const sf::Vector2f &eng::MovementC::getVelocity() const
{
    return this->velocity;
}

const sf::Vector2f &eng::MovementC::get() const
{
    return this->position;
}

void eng::MovementC::set(const float x, const float y)
{
    this->position = sf::Vector2f(x, y);
}
