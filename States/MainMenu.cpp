#include "MainMenu.h"

MainMenuState::MainMenuState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    this->loadTextures();
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::update(const float &dt)
{
}

void MainMenuState::render(sf::RenderTarget *window)
{
}

void MainMenuState::loadTextures()
{
}

void MainMenuState::endStateUpdate()
{
}
