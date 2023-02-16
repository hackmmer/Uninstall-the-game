#include "Clickable.h"
#include "Button.h"

template <class Child>
eng::Clickable<Child>::Clickable(std::string name, sf::Vector2u rect, sf::Vector2f pos) : Object(name)
{
    sf::Vector2f trueRect(rect.x, rect.y);
    this->area = new sf::FloatRect(trueRect, pos);
    this->clickByPointer = false;
    this->clicked = false;
}

template <class Child>
eng::Clickable<Child>::~Clickable()
{
    delete this->area;
}

template <class Child>
bool eng::Clickable<Child>::isPressed()
{
    return (this->state == eng::Clickable<Child>::PRESSED);
}

template <class Child>
bool eng::Clickable<Child>::isJustPressed()
{    
    if (this->mIn && this->clicked && !this->justClicked)
    {
        this->justClicked = true;
        return true;
    }
    if(!this->clicked)
        this->justClicked = false;
    return false;
}

template <class Child>
void eng::Clickable<Child>::setClickByPressing(bool click)
{
    this->clickByPointer = click;
}

template <class Child>
void eng::Clickable<Child>::verifyClick(const sf::Vector2f &MousePos)
{
    if (this->area->contains(MousePos))
    {
        this->mIn = true;
        this->state = eng::Clickable<Child>::HOVER;
        if (this->mouse.isButtonPressed(sf::Mouse::Left))
        {
            this->state = eng::Clickable<Child>::PRESSED;
            if (!this->clicked)
            {
                this->clicked = true;
                if (this->clickByPointer)
                    this->onClick(this->context);
            }
        }
        else
            this->clicked = false;
    }
    else
    {
        this->mIn = false;
        this->state = eng::Clickable<Child>::IDLE;
    }
}
template <class Child>
void eng::Clickable<Child>::setOnClick(std::function<void(Child *)> onClick, Child *context)
{
    this->onClick = onClick;
    this->context = context;
}

template class eng::Clickable<eng::Button>;