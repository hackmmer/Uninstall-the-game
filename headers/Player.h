#ifndef _PLAYER_H
#define _PLAYER_H

#include "Engine/Engine.h"

typedef struct
{
    int agua = 0;
    int aire = 0;
    int fuego = 0;
    int rayo = 0;
    int tierra = 0;
    int luz = 0;
    int dark = 0;
} Afinity;

class Player : public eng::Entity
{
private:
    void initializeVariables();

protected:
    int life;
    int race;

    int force;
    int destreza;
    int vitalidad;
    int speed;
    Afinity* afinidades;

public:
    // need to add the other them
    enum Races
    {
        HUMAN = 0,
        HAMPHER,
        ERINON,
        CORKE,
        CHESIRAT
    };

    Player(const float x, const float y, sf::Texture *texture, int Race);
    virtual ~Player();
};

#endif