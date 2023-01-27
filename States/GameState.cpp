#include "GameState.h"
eng::Entity player;
sf::Font f;
eng::Label lbl("Hola Mundo", 27, 15, 17, f);

GameState::GameState(sf::RenderWindow *window) : State(window)
{
    f.loadFromFile("/usr/lib/ruby/3.1.0/rdoc/generator/template/darkfish/fonts/Lato-LightItalic.ttf");
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
    lbl.font = f;
    lbl.update(dt);
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
    if(!target)
        target = this->window;
    player.draw(target);
    lbl.draw(target);
}
