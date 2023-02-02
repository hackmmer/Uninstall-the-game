#include "Clickable.h"

eng::Clickable::Clickable(std::string name, sf::Vector2f rect, sf::Vector2f pos) : Object(name), area(rect, pos)
{
}

eng::Clickable::~Clickable()
{
}

void eng::Clickable::verifyClick()
{
    if (this->area.contains(this->mousePos))
    {
        this->state = eng::Clickable::HOVER;
        if (this->mouse.isButtonPressed(sf::Mouse::Left))
        {
            this->state = eng::Clickable::PRESSED;
            this->onClick();
        }
    }
    else
    {
        this->state = eng::Clickable::IDLE;
    }
}

void eng::Clickable::setOnClick(void (*onClick)())
{
    this->onClick = onClick;
}