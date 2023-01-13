#ifndef __GAME_H
#define __GAME_H

#include <GameState.h>
#include <Engine/Engine.h> // Engine Stuff

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
         * _**Resumen**_: Hace conteos de tiempo.
        */
        sf::Clock dtClock;

        /**
         * **Delta Time**
         * 
         * _**Descripcion**_: Delta Time _(Variacion del tiempo)_ 
         * 
         * _**Objetivo**_: usado para la sincronizacion del juego y para la normalizacion del movimiento y el calculo de tiempo que tarda el juego en actualizar cada frame.
         * 
         * _**Resumen**_: hace que el juego corra a la misma velocidad para todo el mundo.
        */
        float dt;

        /**
         * **States**
         * 
         * _**Descripcion**_: Variables que almacena los States cargados del juego.
         * 
         * _**Objetivo**_: Almacenar los state cargados para borrarlos despues.
         * 
         * _**Resumen**_: Almacena los state.
        */
        std::stack<State*> states;

        // Funcs
        void initWindow();
        void initStates();

    public:

        Game();
        virtual ~Game();

        // Funcs
        void endGame();
        void updateDt();
        void updateSFMLEvents();
        void render();
        void update();
        void run();
};
#endif