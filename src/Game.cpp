#include "Game.h"

// private Funcs
void Game::initWindow()
{
    
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game Title");
}

// Constructor / Destructor
Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

// Public Funcs

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
        
    }
}

void Game::render()
{
    this->window->clear();
    this->window->display();
}

void Game::update()
{
    this->updateDt();
    this->updateSFMLEvents();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}