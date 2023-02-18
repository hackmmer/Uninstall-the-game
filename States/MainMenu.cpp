#include "MainMenu.h"

MainMenuState::MainMenuState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    this->loadRes();
    this->Title.text = "Hola mundo";
    this->Title.size = 48U;
    this->Title.x = 38;
    this->Title.y = 5;
    this->Title.color = sf::Color::White;
    this->Title.font = this->fonts["TITLE"];
    this->buttons["StartGame"] = new eng::Button(50, 110, this->textures["BUTTON_idle"], "Start Game", this->fonts["TITLE"]);
    this->buttons["StartGame"]->updateWindow(this->window);
    this->buttons["StartGame"]->setTexture(eng::Button::states::HOVER, this->textures["BUTTON_hover"]);
    this->buttons["StartGame"]->setTexture(eng::Button::states::PRESSED, this->textures["BUTTON_pressed"]);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::loadRes()
{
    sf::Font tmpFont;
    sf::Texture tmpTex;
    tmpFont.loadFromMemory(Assets::Fonts::Lato_Light_ttf, Assets::Fonts::Lato_Light_ttf_len);
    this->fonts["TITLE"] = tmpFont;
    std::string s[] = {"idle", "hover", "pressed"};
    for (std::string b : s)
    {
        tmpTex.loadFromFile("Textures/Buttons/TestingButton/" + b + ".png");
        this->textures["BUTTON_" + b] = tmpTex;
    }
}

void MainMenuState::endStateUpdate()
{
}

void MainMenuState::update(const float &dt)
{
    if (!this->pause)
    {
        this->Title.update(dt);
        this->buttons["StartGame"]->update(this->MousePos);
    }
}

void MainMenuState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    this->Title.draw(window);
    this->buttons["StartGame"]->draw(window);
}