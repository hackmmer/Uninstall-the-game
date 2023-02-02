#include "Game.h"

// private Funcs

/// @brief Initialize the Game Window **PARTIALLY DON'T TOUCH**
void Game::initWindow()
{
    //  <Touchable region>

    std::ifstream winConfig("Config/window.ini"); // Configuracion
    sf::VideoMode winDimension; // Dimensiones de la ventana
    unsigned frameLimit; // Frame Limit
    bool vsync; // Vertical Sync

    // </Touchable Region>

    /// @brief Window config load
    if(winConfig.is_open())
    {
        winConfig >> winDimension.width >> winDimension.height;
        winConfig >> frameLimit;
        winConfig >> vsync;
    }
    else
    {
        /// @brief Cannot to load file config window
        std::cerr << "Cannot open Config/window.ini file" << std::endl;
        return;
    }

    this->window = new sf::RenderWindow(winDimension, "Game Title"); // Game Title es cambiable
    this->window->setFramerateLimit(frameLimit);
    this->window->setVerticalSyncEnabled(vsync);
}

/// @brief Initialize the first State **DON'T TOUCH**
void Game::initStates()
{
    this->states.push(new GameState(this->window, &(this->states)));
}

// Constructor / Destructor
Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;
    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

// Public Funcs

/// @brief Called when the game ends 
void Game::endGame()
{
    // Do something when the game ends
    // TODO code here for that...
}

/// @brief Update the Delta time every frame **DON'T TOUCH**
void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

/// @brief Update the SFML Events
void Game::updateSFMLEvents()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
        
    }
}

/// @brief Update the display render **DON'T TOUCH**
void Game::render()
{
    this->window->clear();
    // Items to render
    if(!this->states.empty())
        this->states.top()->render();

    this->window->display();
}

/// @brief Update all game logic **DON'T TOUCH**
void Game::update()
{
    this->updateDt();
    this->updateSFMLEvents();

    if(!this->states.empty())
    {
        this->states.top()->update(this->dt);
        this->states.top()->checkQuit();
        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else // The game ends...
    {
        this->endGame();
        this->window->close();
    }
}

/// @brief Main loop **DON'T TOUCH**
void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}