# Button \<T\>

## Descripción

> Crea un objeto de tipo Button para el interfaz. Extiende de [Clickable](Clickable.md)

## Index

* **Button**
* [Clickable](Clickable.md)
* [Engine](Engine.md)
* [Entity](Entity.md)
* [Label](Label.md)
* [Object](Object.md)
* [ProgressBar](ProgressBar.md)

## Usage

> Esta clase aun no esta testeada

### Constructors and destructors

`Button(float x, float y, sf::Texture &normal, const std::string text, sf::Font font, sf::Color textColor, unsigned int textSize)`

* **x**: Posicion en X del botón
* **y**: Posicion en Y del botón
* **normal**: Textura normal del botón (Sin estados, esta se aplica a todos los estados del boton, hay q cambiarlos despues usando `setXXX` donde XXX se sustituye por el estado (Normal, Hover, Pressed))
* **text**: El texto que contendrá el botón
* **font**: La fuente a usar por el texto en el botón
* **textColor**: El color que usará el texto en el botón 
* **textSize**: El tamaño del texto

### Parámetros

* `sf::Sprite image`: El sprite que se encargara de cargar el texture.

* `std::map<std::string, sf::Texture> textures`: Alberga las texturas que usará el botón.

* `sf::Text text`: Texto que muestra el botón

* `T tag`: Un identificador para el botón. Puede alvergar cualquier tipo de dato, el boton no usa esto.

### Métodos

#### Getters/Setters

```
void setTag(T &tag)
T &getTag()
```

**tag**: El tag que usarás en el botón.<br>
> _Devuelve el objeto almacenado en la variable `tag` del Botón._
> Ajusta o devuelve el valor de `tag`.

```
void setTexture(unsigned int stage, sf::Texture& texture)
sf::Texture& getTexture(unsigned int stage)
```

**stage**: Entero que hace referencia al estado del boton (IDLE, HOVER, PRESSED).<br>
**texture**: Textura del botón.<br>
> _Devuelve la textura del estado `stage` del botón._
> _Ajusta o devuelve la textura del boton en un estado específico._

#### Otros

`void update(const float &dt)`<br>
**dt**: Tiempo en delta.<br>
> Actualiza los estados del botón y llama la funcion de click.

`void draw(sf::RenderTarget *window)`<br>
**window**: Ventana donde se renderiza el botón.<br>
> Dibuja el botón en la ventana.

`void setOnClick(void (*onClick)(Clickable* self))`<br>
> Ajusta el valor del parametro `onClick`. (ver [Clickable->onClick](Clickable.md#métodos))
