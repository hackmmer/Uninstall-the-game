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


const bool State::getQuit() const
{
    return this->quit;
}

void State::endState()
{
    this->quit = true;
}
