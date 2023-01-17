#include "GameState.h"
eng::Entity player;

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

void GameState::update(const float &dt)
{
    
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.move(-1, 0, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.move(1, 0, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.move(0, -1, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move(0, 1, dt);
    }
}

void GameState::render(sf::RenderTarget *target)
{
    player.draw(this->window);
}
