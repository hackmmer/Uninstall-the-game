#include "Button.h"


eng::Button::Button(float x, float y, sf::Texture normal, const std::string strText, sf::Font font, sf::Color textColor, unsigned int textSize)
    : Clickable("Button",
                normal.getSize(),
                sf::Vector2f(x, y))
{
    this->textures["NORMAL"] = normal;
    this->textures["HOVER"] = normal;
    this->textures["PRESSED"] = normal;

    this->currentTexture = normal;

    this->font = new sf::Font(font);

    this->image.setPosition(x, y);
    this->image.setScale(sf::Vector2f(1, 1));
    this->image.setTexture(this->currentTexture);
    this->text = new sf::Text();
    this->text->setString(strText);
    this->text->setFont(*this->font);
    this->text->setFillColor(textColor);
    this->text->setCharacterSize(textSize);

    this->text->setPosition(
        this->image.getPosition().x + (this->image.getGlobalBounds().width / 2.f) - this->text->getGlobalBounds().width / 2.f,
        this->image.getPosition().y + (this->image.getGlobalBounds().height / 2.f) - this->text->getGlobalBounds().height
        );
        
        
    
}

eng::Button::~Button()
{
    delete this->font;
    delete this->text;
}

/*
void eng::Button::setTag(T &tag)
{
    this->tag = tag;
}


T &eng::Button::getTag()
{
    return this->tag;
}*/


void eng::Button::setTexture(unsigned int stage, sf::Texture &texture)
{
    std::string state;
    switch (stage)
    {
    case eng::Clickable::IDLE:
        state = "NORMAL";
        break;
    case eng::Clickable::HOVER:
        state = "HOVER";
        break;
    case eng::Clickable::PRESSED:
        state = "PRESSED";
        break;
    }
    this->textures[state] = texture;
}


sf::Texture &eng::Button::getTexture(unsigned int stage)
{
    switch (stage)
    {
    case eng::Clickable::IDLE:
        return this->textures["NORMAL"];
        break;
    case eng::Clickable::HOVER:
        return this->textures["HOVER"];
        break;
    case eng::Clickable::PRESSED:
        return this->textures["PRESSED"];
        break;
    default:
        return this->textures["NORMAL"];
        break;
    }
}


void eng::Button::draw(sf::RenderTarget *target)
{
    if (this->visible)
    {
        verifyClick(window->mapPixelToCoords(this->mouse.getPosition(*this->window)));
        this->image.setTexture(this->currentTexture);
        target->draw(this->image);
        if(!this->text)
            throw "EXCEPTION";
        target->draw(*this->text);
    }
}

void eng::Button::updateWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void eng::Button::update(const float &dt)
{
    switch (this->state)
    {
    case eng::Clickable::IDLE:
        this->image.setTexture(this->textures["NORMAL"]);
        this->currentTexture = this->textures["NORMAL"];
        break;
    case eng::Clickable::HOVER:
        this->image.setTexture(this->textures["HOVER"]);
        this->currentTexture = this->textures["HOVER"];
        break;
    case eng::Clickable::PRESSED:
        this->image.setTexture(this->textures["PRESSED"]);
        this->currentTexture = this->textures["PRESSED"];
        break;
    }
}