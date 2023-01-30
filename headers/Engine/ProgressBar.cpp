#include "ProgressBar.h"

eng::ProgressBar::ProgressBar(float min, float max, float x, float y, sf::Color barColor, std::string marco, std::string bg, std::string font)
{
    this->min = min;
    this->value = min;
    this->max = max;

    sf::Texture textMarco, textBg;
    sf::Font fFont;
    textMarco.loadFromFile(marco);
    textBg.loadFromFile(bg);
    fFont.loadFromFile(font);

    this->sfMarco.setTexture(textMarco);
    
    this->sfFiller.setPosition(x, y);
    this->sfMarco.setPosition(x, y);
    this->sfFiller.setSize(sf::Vector2f(
        0,                                    // the long
        this->sfMarco.getLocalBounds().height // the height
        ));

    this->sfText.setString(std::to_string(value).append("/").append(std::to_string(max)));
    this->sfText.setPosition(sf::Vector2f(
        (this->sfMarco.getPosition().x + this->sfMarco.getGlobalBounds().width / 2.f) - this->sfText.getLocalBounds().width / 2.f,
        (this->sfMarco.getPosition().y + this->sfMarco.getGlobalBounds().height / 2.f) - this->sfText.getLocalBounds().height / 2.f));
    this->sfText.setCharacterSize(this->sfMarco.getLocalBounds().height / 2.f);
    this->sfFiller.setFillColor(barColor);
}

eng::ProgressBar::~ProgressBar()
{
}

void eng::ProgressBar::draw(sf::RenderTarget *window)
{
    if (this->visible)
    {
        window->draw(this->sfBackground);
        window->draw(this->sfFiller);
        window->draw(this->sfMarco);
        window->draw(this->sfText);
    }
}

void eng::ProgressBar::update(const float &dt)
{
    float percent = this->value / this->max;
    float longitude = this->sfMarco.getLocalBounds().width * percent;

    this->sfFiller.setSize(sf::Vector2f(
        longitude,
        this->sfMarco.getLocalBounds().height));

    this->sfText.setString(this->text);
}
