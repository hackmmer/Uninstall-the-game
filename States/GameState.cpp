#include "GameState.h"
eng::Entity player;
sf::Font f;
eng::Label lbl("Hola Mundo", 27, 15, 17, f);
eng::Label lbl2("Start Game", 17, 15, 17*2*1.4, f);
eng::Label lbl3("Opciones", 17, 15, 17*3*1.4, f);
eng::Label lbl4("Extra", 17, 15, 17*4*1.4, f);
eng::Label lbl5("Salir", 17, 15, 17*5*1.4, f);

GameState::GameState(sf::RenderWindow *window) : State(window)
{
    f.loadFromFile("/home/blizz/Projects/Zeno-Survival-Project/Fonts/Lato-Light.ttf");
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
    lbl2.font = f;
    lbl3.font = f;
    lbl4.font = f;
    lbl5.font = f;
    lbl.update(dt);
    lbl2.update(dt);
    lbl3.update(dt);
    lbl4.update(dt);
    lbl5.update(dt);
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
    lbl2.draw(target);
    lbl3.draw(target);
    lbl4.draw(target);
    lbl5.draw(target);
}
