#include "GameState.h"

void GameState::initPlayer()
{
}

GameState::GameState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    this->loadTextures();
    this->initPlayer();
    sf::Font tmp;
    tmp.loadFromMemory(Fonts::Lato_Light_ttf, Fonts::Lato_Light_ttf_len);
    this->Title = new eng::Label("Hello world", 32, 15, 15, tmp);
}

GameState::~GameState()
{
    //delete this->player;
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
        this->Title->update(dt);
    }
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    this->Title->draw(target);
}
