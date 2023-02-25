#include "GameState.h"

void GameState::initPlayer()
{
    this->player = new Player(15, 15, &this->textures["PLAYERY_TEST"], Player::HUMAN);
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
    sf::Texture temp;
    temp.loadFromFile("/home/blizz/Projects/Zeno-Survival-Project/Textures/Entitys/Player/test.png");
    this->textures["PLAYERY_TEST"] = temp;
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
        this->player->update(dt);
    }
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    this->player->draw(target);
}
