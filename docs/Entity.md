# Entity

## Descripción
> `Entity` es una clase para implementar Entidades como NPCs, el Jugador, u otros elementos de este tipo.

## Index

* [Button](Button.md)
* [Clickable](Clickable.md)
* [Engine](Engine.md)
* **Entity**
* [Label](Label.md)
* [Object](Object.md)
* [ProgressBar](ProgressBar.md)

## Usage

> Se utiliza para crear NPCs como enemigos, vendedores, Jefes, Aliados, o simplemente "Entidades decorativas". Ej: Guardias en una ciudad que solo saludan, y tales....

### Parámetros
* ``sf::Sprite* sprite``: El Sprite que va a ser renderizado.
* ``sf::Texture* EntityTexture``: Textura a usar por `sprite`.
* ``float speed``: Velocidad de movimiento.
* ``float x``: Posición en  **X**.
* ``float y``: Posición en **Y**.

### Constructores y Destructores

```
Entity();
Entity(std::string name);
virtual ~Entity();
```
* **name**: Usado para la herencia de esta clase.

### Métodos

`void update(const float &dt)`
* **dt**: Variacion del tiempo requerido por la clase Padre (Ver [Object](Object.md#métodos)).
> Actualiza el estado de la Entidad en el juego. 

`void draw(sf::RenderTarget *target)`
* **target**: Objetivo de renderizado requerido por la clase Padre (Ver [Object](Object.md#métodos)).
> Dibuja el objeto en pantalla.

`void loadSprite(sf::Texture* texture)`
* **texture**: La textura que se va a usar para el sprite.
> Carga la textura dada en el sprite para cambiar su imagen.

`void move(float x, float y, const float &dt)`
* **x**: translacion en **X**.
* **y**: translacion en **Y**.
* **dt**: Variacion del tiempo para normalizar el movimiento.
> Usado para mover el personaje, de un punto a otro.

`void setPosition(const float x, const float y)`
* **x**: posición en **X**.
* **y**: posición en **Y**.
> Teletransporta al personaje a las posiciones dadas en **X** y **Y**.
