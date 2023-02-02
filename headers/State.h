#ifndef STATE_H
#define STATE_H

#include <Engine/Engine.h>

class State
{

protected:
    std::vector<sf::Texture> textures;
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

    virtual void render(sf::RenderTarget *target = nullptr) = 0;
};

#endif