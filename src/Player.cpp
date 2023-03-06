#include "Player.h"

void Player::initializeVariables()
{
    Afinity *afinity = new Afinity();
    afinity->agua = 0;
    afinity->aire = 0;
    afinity->fuego = 0;
    afinity->rayo = 0;
    afinity->tierra = 0;
    afinity->luz = 0;
    afinity->dark = 0;
    switch (this->race)
    {
    case Player::Races::HUMAN:
        this->s_race = "HUMAN";
        this->life = 200;
        this->force = 4;
        this->destreza = 4;
        this->vitalidad = 4;
        this->speed = 2;
        afinity->agua = 2;
        afinity->aire = 2;
        afinity->fuego = 2;
        afinity->rayo = 2;
        afinity->tierra = 2;
        break;
    case Player::Races::HAMPHER:
        this->s_race = "HAMPHER";
        this->life = 300;
        this->force = 7;
        this->destreza = 2;
        this->vitalidad = 5;
        this->speed = 1;
        afinity->agua = 4;
        afinity->tierra = 2;
        afinity->luz = 2;
        afinity->dark = 2;
        break;
    case Player::Races::ERINON:
        this->s_race = "ERINON";
        this->life = 240;
        this->force = 3;
        this->destreza = 3;
        this->vitalidad = 6;
        this->speed = 3;
        afinity->agua = 6;
        afinity->aire = 6;
        break;
    case Player::Races::CORKE:
        this->s_race = "CORKE";
        this->life = 170;
        this->force = 5;
        this->destreza = 5;
        this->vitalidad = 4;
        this->speed = 3;
        afinity->fuego = 6;
        afinity->rayo = 3;
        afinity->tierra = 3;
        break;
    case Player::Races::CHESIRAT:
        this->s_race = "CHESIRAT";
        this->life = 150;
        this->force = 2;
        this->destreza = 8;
        this->vitalidad = 2;
        this->speed = 5;
        afinity->aire = 6;
        afinity->dark = 3;
        afinity->luz = 3;
        break;
    }
    this->speed *= 7.33;
    
    // For normalize the race string
    for(auto it = this->s_race.begin(); it != this->s_race.end(); ++it)
    {
        if(it == this->s_race.begin())
            continue;
        *it = *it + 32;
    }
    
    this->afinidades = afinity;
}

Player::Player(const float x, const float y, sf::Texture *texture, int Race) : race(Race)
{
    this->initializeVariables();
    this->loadSprite(texture);
    this->setPosition(x, y);
}

void Player::update(float const &dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->movement->move(-1 * this->speed, 0, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->movement->move(1 * this->speed, 0, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->movement->move(0, 1 * this->speed, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->movement->move(0, -1 * this->speed, dt);
}

Player::~Player()
{
    delete this->afinidades;
}