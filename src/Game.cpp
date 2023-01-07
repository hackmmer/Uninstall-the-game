#include "Game.h"

// private Funcs
void Game::initWindow()
{
    std::ifstream winConfig("Config/window.ini");
    sf::VideoMode winDimension; // Dimensiones de la ventana
    unsigned frameLimit; // Frame Limit
    bool vsync; // Vertical Sync

    if(winConfig.is_open())
    {
        winConfig >> winDimension.width >> winDimension.height;
        winConfig >> frameLimit;
        winConfig >> vsync;
    }
    else
    {
        std::cerr << "Cannot open Config/window.ini file" << std::endl;
        return;
    }

    this->window = new sf::RenderWindow(winDimension, "Game Title");
    this->window->setFramerateLimit(frameLimit);
    this->window->setVerticalSyncEnabled(vsync);
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