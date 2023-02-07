#ifndef STATE_H
#define STATE_H

#include "Engine/Engine.h"
#include "Player.h"

class State
{

protected:
    std::map<std::string, sf::Texture> textures;
    sf::RenderWindow *window;
    bool quit;
    std::stack<State *> *states;
    bool pause;

public:
    State(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~State();

    

    /// @brief Verifies if the game is gonna quit
    void checkQuit();

    /// @brief Verifies if quit?
    /// @return the Quit value
    const bool getQuit() const;

    /// @brief Called when a state is gonna quit (Like a State Destructor)
    virtual void endState() = 0;

    /// @brief This called every frame
    /// @param dt Delta Time
    virtual void update(const float &dt) = 0;

    /// @brief The render state
    /// @param target the Window target
    virtual void render(sf::RenderTarget *target = nullptr) = 0;

    /// @brief Load all the textures of the scene
    virtual void loadTextures() = 0;
};

#endif