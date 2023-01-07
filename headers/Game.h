#ifndef __GAME_H
#define __GAME_H

#include <State.h>

class Game{
    private:

        // Vars

        /**
         * ***window**
         * 
         * _**Descripcion**_: Ventana principal del proyecto.
         * 
         * _**Objetivo**_: Cargar la ventana del juego.
        */
        sf::RenderWindow *window;

        /**
         * sfEvent
         * 
         * _**Descripcion**_: Evento principal.
         * 
         * _**Objetivo**_: Encargado del cierre de la ventana y otras cosas.
        */
        sf::Event sfEvent;

        /**
         * **Delta Time Clock**
         * 
         * _**Descripcion**_: Delta Time Clock _(Reloj de variacion del tiempo)_ 
         * 
         * _**Objetivo**_: Usado para actualizar el deltaTime (`dt`).
         * 
         * _**Resumen:**_ Hace conteos de tiempo.
        */
        sf::Clock dtClock;

        /**
         * **Delta Time**
         * 
         * _**Descripcion**_: Delta Time _(Variacion del tiempo)_ 
         * 
         * _**Objetivo**_: usado para la sincronizacion del juego y para la normalizacion del movimiento y el calculo de tiempo que tarda el juego en actualizar cada frame.
         * 
         * _**Resumen:**_ hace que el juego corra a la misma velocidad para todo el mundo.
        */
        float dt;

        // Funcs
        void initWindow();

    public:

        Game();
        virtual ~Game();

        // Funcs
        void updateDt();
        void updateSFMLEvents();
        void render();
        void update();
        void run();
};
#endif