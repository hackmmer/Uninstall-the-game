#include "State.h"

State::State(sf::RenderWindow *window, std::stack<State*> *states)
{
    this->window = window;
    this->quit = false;
    this->states = states;
    this->showDebug = false;
}

State::~State()
{
}

void State::updateMouse()
{
    this->MousePos = this->window->mapPixelToCoords(this->mouse.getPosition(*this->window));
}

const bool State::getQuit() const
{
    return this->quit;
}

void State::endState()
{
    this->quit = true;
}

void State::showDebugOptions()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && !this->f5)
        {
            this->showDebug = !this->showDebug;
            this->f5 = true;
        }
        else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
            this->f5 = false;

    if(this->showDebug)
    {
        sf::Text text;
        sf::Font font;
        font.loadFromMemory(Assets::Fonts::Lato_Light_ttf, Assets::Fonts::Lato_Light_ttf_len);
        text.setFont(font);
        std::stringstream pos;
        pos << this->MousePos.x << ", " << this->MousePos.y;
        text.setString(pos.str());
        text.setCharacterSize(32U);
        sf::Vector2f p(this->MousePos.x + 10, this->MousePos.y - text.getGlobalBounds().height * 1.3);
        if(p.x + text.getGlobalBounds().width > this->window->getSize().x)
            p.x = p.x - text.getGlobalBounds().width - 10;
        if(p.y + text.getGlobalBounds().height > this->window->getSize().y - 8)
            p.y = this->window->getSize().y - 32 - 10;
        if(p.y - text.getGlobalBounds().height <= 0)
            p.y = 5;
        if(p.x - text.getGlobalBounds().width <= 0)
            p.x = 5;
        text.setPosition(p);
        this->window->draw(text);
    }
}
