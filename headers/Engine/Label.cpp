#include "Label.h"

eng::Label::Label() : Object<const float &>("Label")
{
}

eng::Label::Label(std::string text, const uint &size, const float &x, const float &y, sf::Font font) : Object<const float &>("Label"), text(text), size(size), x(x), y(y), font(font)
{
}

eng::Label::~Label()
{
}

void eng::Label::draw(sf::RenderTarget *window)
{

    if (this->visible)
    {
        window->draw(this->self);
    }
}

void eng::Label::update(const float &dt)
{
    this->self.setString(this->text);
    this->self.setFillColor(this->color);
    this->self.setCharacterSize(this->size);
    this->self.setPosition(sf::Vector2f(this->x, this->y));
    this->self.setFont(this->font);
}
