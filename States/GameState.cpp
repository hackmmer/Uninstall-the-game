#include "GameState.h"

void GameState::initPlayer()
{
    
}

GameState::GameState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    this->loadRes();
    this->initPlayer();

}

GameState::~GameState()
{    
}


void GameState::endStateUpdate()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->endState();
}

void GameState::loadRes()
{
    // this->textures["PLAYER_IDLE"].loadFromXXX and we save it like this...
}

void GameState::endState()
{
    std::cout << "Ending state...!!"
              << "\n";
}

void GameState::update(const float &dt)
{
    if (!this->pause)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->quit = true;
    }
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    //this->showDebugOptions();
}
