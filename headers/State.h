#ifndef _STATE_H
#define _STATE_H

#include "Engine/Engine.h"
#include "Player.h"
#include "Assets/Fonts.h"

class State
{
private:
    bool f5;

protected:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
    sf::RenderWindow *window;
    bool quit;
    std::stack<State *> *states;
    bool pause;
    sf::Mouse mouse;
    sf::Vector2f MousePos;
    bool showDebug;

public:
    State(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~State();

    virtual void updateMouse();

    /// @brief Updates if the state is gonna quit
    virtual void endStateUpdate() = 0;

    /// @brief Verifies if quit?
    /// @return the Quit value
    const bool getQuit() const;

    /// @brief Called when a state is gonna quit (Like a State Destructor)
    void endState();

    /// @brief This called every frame
    /// @param dt Delta Time
    virtual void update(const float &dt) = 0;

    /// @brief The render state
    /// @param target the Window target
    virtual void render(sf::RenderTarget *target = nullptr) = 0;

    /// @brief Load all the textures of the scene
    virtual void loadRes() = 0;

    virtual void showDebugOptions();
};

#endif