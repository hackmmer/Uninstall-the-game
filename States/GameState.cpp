#include "GameState.h"

void GameState::initPlayer()
{
    
}

void btn1(eng::Clickable* btn)
{
}

GameState::GameState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    this->loadTextures();
    this->initPlayer();
    sf::Font tmp;
    tmp.loadFromMemory(Assets::Fonts::Lato_Light_ttf, Assets::Fonts::Lato_Light_ttf_len);
    this->Title = new eng::Label("Hello world", 32, 15, 15, tmp);

    sf::Texture tmp2;
    tmp2.loadFromFile("/home/blizz/Projects/Zeno-Survival-Project/Textures/Buttons/TestingButton/idle.png");

    this->btn = new eng::Button(45,80, tmp2, "Hola Mundo", tmp, sf::Color::White, 18U);
    tmp2.loadFromFile("/home/blizz/Projects/Zeno-Survival-Project/Textures/Buttons/TestingButton/hover.png");
    this->btn->setTexture(eng::Button::states::HOVER, tmp2);
    this->btn->setOnClick(btn1);
}

GameState::~GameState()
{
    //delete this->player;
    delete this->Title;
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
        this->btn->update(dt);
    }
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    this->Title->draw(target);
    this->btn->updateWindow(this->window);
    this->btn->draw(target);
}
