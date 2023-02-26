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

void GameState::showDebugOptions()
{
    State::showDebugOptions();

    if(this->showDebug)
    {
        sf::Text text;
        sf::Font font;
        font.loadFromMemory(Assets::Fonts::Lato_Light_ttf, Assets::Fonts::Lato_Light_ttf_len);
        text.setFont(font);
        std::stringstream data;
        data << "Vida: " << this->player->life << "\nAgua: " << this->player->afinidades->agua 
        << "\nAire: " << this->player->afinidades->aire << "\nDark: " << this->player->afinidades->dark
        << "\nFuego: " << this->player->afinidades->fuego << "\nLuz: " << this->player->afinidades->luz 
        << "\nRayo: " << this->player->afinidades->rayo << "\nTierra: " << this->player->afinidades->tierra
        << "\nSpeed: " << this->player->speed;
        text.setString(data.str());
        text.setCharacterSize(22U);
        text.setPosition(15,15);
        this->window->draw(text);
    }
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
