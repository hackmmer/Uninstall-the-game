#include "Button.h"

template <typename T>
eng::Button<T>::Button(float x, float y, sf::Texture &normal, sf::Texture &hover, sf::Texture &pressed, const std::string &text, sf::Font font, sf::Color textColor, unsigned int textSize) : Clickable("Button",
                                                                                                                                                                                                        normal.getSize(),
                                                                                                                                                                                                        sf::Vector2f(x, y))
{
    this->normal = normal;
    this->hover = hover;
    this->pressed = pressed;

    this->image.setPosition(x, y);
    this->image.setScale(sf::Vector2f(1, 1));
    this->text.setString(text);
    this->text.setPosition(this->image.getPosition());
    this->text.move(
        this->image.getTextureRect().width / 2.f - this->text.getLocalBounds().width / 2.f,
        this->image.getTextureRect().height / 2.f - this->text.getLocalBounds().height / 2.f);
    this->text.setFont(font);
    this->text.setFillColor(textColor);
    this->text.setCharacterSize(textSize);
}
template <typename T>
eng::Button<T>::~Button()
{
}

template <typename T>
void eng::Button<T>::setTag(T &tag)
{
    this->tag = tag;
}

template <typename T>
T &eng::Button<T>::getTag()
{
    return this->tag;
}

template <typename T>
void eng::Button<T>::draw(sf::RenderTarget *window)
{
    if (this->visible)
    {
        //this->mousePos = window->mapPixelToCoords(this->mouse.getPosition((sf::Window)*window));
        verifyClick(window->mapPixelToCoords(this->mouse.getPosition((sf::Window)*window)));
        this->image.setTexture(this->texture);
        window->draw(this->image);
        window->draw(this->text);
    }
}

template <typename T>
void eng::Button<T>::update(const float &dt)
{
    switch (this->state)
    {
    case eng::Clickable::IDLE:
        this->image.setTexture(this->normal);
        break;
    case eng::Clickable::HOVER:
        this->image.setTexture(this->hover);
        break;
    case eng::Clickable::PRESSED:
        this->image.setTexture(this->pressed);
        break;
    }
}