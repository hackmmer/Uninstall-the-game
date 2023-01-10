#include "GameState.h"

GameState::GameState(sf::RenderWindow *window) : State(window)
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
    std::cout << "Ending state...!!" << "\n";
}

void GameState::update(const float &df)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout<<"A\n";
}

void GameState::render(sf::RenderTarget *target)
{
}
