#include "State.h"

State::State(sf::RenderWindow *window, std::stack<State*> *states)
{
    this->window = window;
    this->quit = false;
    this->states = states;
}

State::~State()
{
}

void State::checkQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
}

const bool State::getQuit() const
{
    return this->quit;
}
