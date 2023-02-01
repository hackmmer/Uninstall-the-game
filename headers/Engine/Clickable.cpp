#include "Clickable.h"

eng::Clickable::Clickable(std::string name, sf::Vector2f rect, sf::Vector2f pos) : Object(name), area(rect, pos)
{}

eng::Clickable::~Clickable()
{
}

bool eng::Clickable::isHover()
{
    return this->_hover;
}

void eng::Clickable::verifyClick()
{
    if (this->area.contains(this->mousePos))
    {
        this->_hover = true;
    }
    else
    {
        this->_hover = false;
    }
    if (this->area.contains(this->mousePos) && this->mouse.isButtonPressed(sf::Mouse::Left))
    {
        while(this->mouse.isButtonPressed);
        this->onClick();
    }
}

void eng::Clickable::setOnClick(void (*onClick)())
{
    this->onClick = onClick;
}