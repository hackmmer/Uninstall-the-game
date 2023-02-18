#include "GameState.h"

void GameState::initPlayer()
{
    
}

GameState::GameState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    this->loadTextures();
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

void GameState::loadTextures()
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && !this->f5)
        {
            this->showDebug = !this->showDebug;
            this->f5 = true;
        }
        else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
            this->f5 = false;
    }
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    //this->showDebugOptions();
}
