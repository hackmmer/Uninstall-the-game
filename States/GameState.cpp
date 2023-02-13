#include "GameState.h"

void GameState::initPlayer()
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

    this->btns["HELLO_BUTTON"] = new eng::Button(45,80, tmp2, "Hola Mundo", tmp, sf::Color::White, 18U);
    tmp2.loadFromFile("/home/blizz/Projects/Zeno-Survival-Project/Textures/Buttons/TestingButton/hover.png");
    this->btns["HELLO_BUTTON"]->setTexture(eng::Button::states::HOVER, tmp2);
    tmp2.loadFromFile("/home/blizz/Projects/Zeno-Survival-Project/Textures/Buttons/TestingButton/pressed.png");
    this->btns["HELLO_BUTTON"]->setTexture(eng::Button::states::PRESSED,tmp2);

}

GameState::~GameState()
{
    //delete this->player;
    delete this->Title;
    for (auto it = this->btns.begin(); it != this->btns.end(); ++it)
    {
        std::cout << "Cleanning \"" << it->first << "\""<< std::endl;
        delete it->second;
    }
    
}

void GameState::btn1()
{
    this->Title->text = "Hello from fucking button :VVV";
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
        this->btns["HELLO_BUTTON"]->update(dt);
        if(this->btns["HELLO_BUTTON"]->isPressed())
            this->btn1();
    }
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    this->Title->draw(target);
    this->btns["HELLO_BUTTON"]->updateWindow(this->window);
    this->btns["HELLO_BUTTON"]->draw(target);
}
