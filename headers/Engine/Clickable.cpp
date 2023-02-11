#include "Clickable.h"
#include "Button.h"

template <class Child> 
eng::Clickable<Child>::Clickable(std::string name, sf::Vector2u rect, sf::Vector2f pos) : Object(name)
{
    sf::Vector2f trueRect(rect.x, rect.y);
    this->area = new sf::FloatRect(trueRect, pos);
}

template <class Child>
eng::Clickable<Child>::~Clickable()
{
    delete this->area;
}

template <class Child>
void eng::Clickable<Child>::verifyClick(const sf::Vector2f &MousePos)
{
    if (this->area->contains(MousePos))
    {
        this->state = eng::Clickable<Child>::HOVER;
        if (this->mouse.isButtonPressed(sf::Mouse::Left))
        {
            this->state = eng::Clickable<Child>::PRESSED;
            this->onClick(this->context);
        }
    }
    else
    {
        this->state = eng::Clickable<Child>::IDLE;
    }
}
template <class Child>
void eng::Clickable<Child>::setOnClick(std::function<void(Child*)> onClick, Child* context)
{
    this->onClick = onClick;
    this->context = context;
}

template class eng::Clickable<eng::Button>;