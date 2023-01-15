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
    eng::Object o;
    
    while(o.getChildsCount() < 50)
    {
        eng::Object tO;
        tO.name = std::to_string(o.getChildsCount());
        o.addChild(tO);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout << o.getChild(0) <<std::endl;
}

void GameState::render(sf::RenderTarget *target)
{
}
