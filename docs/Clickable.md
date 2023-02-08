# Clickable

## Descripción
> `Clickable` es una clase abstracta para implementar una API para clickear objetos con el mouse. Extiende de [Object](Object.md).

## Index

* [Button](Button.md)
* **Clickable**
* [Engine](Engine.md)
* [Entity](Entity.md)
* [Label](Label.md)
* [Object](Object.md)
* [ProgressBar](ProgressBar.md)

## Usage

> Esta clase se usa para heredar nuevas clases de ella que tengan la propiedad [onClick](Clickable.md#onclick).

### Parámetros
* `sf::Mouse mouse`: Posicion del mouse relativa a la cámara.
* `sf::FloatRect area`: Área clickeable del objeto.
* `unsigned short state`: Estado del objeto. (IDLE, HOVER, PRESSED).
* `void (*onClick)(Clickable *self)`: Puntero a funcion donde se ejecuta el codigo de clickado del objeto.
* ``enum states{ IDLE = 0, HOVER, PRESSED}``: Estados posibles del objeto.
*  * **IDLE**: Estado natural del objeto.
*  * **HOVER**: Estado del objeto mientras tiene encima el ratón.
*  * **PRESSED**: Estado del objeto mientras está presionado.

### Constructores y Destructores

```
Clickable(std::string name, sf::Vector2f rect, sf::Vector2f pos)
virtual ~Clickable()
```
* **name**: Nombre del tipo de objeto. Ej: `Button`, `Label`, etc... (Ver [Object](Object.md#parámetros))
* **rect**: Área clickeable del objeto.
* **pos**: Posicion del área del objeto.

### Métodos

```
virtual void draw(sf::RenderTarget *window) = 0
virtual void update(const float &dt) = 0
```

> Métodos de actualizacion y renderizado de la clase (Ver [Object](Object.md#métodos))

```
void verifyClick(const sf::Vector2f &MousePos);
```
* **MousePos**: Posicion del mouse para verificar si se esta clickeando este objeto.
> Verifica si se esta clickeando el objeto.

```
void setOnClick(void (*onClick)(Clickable* self));
```
* **onClick**: Puntero a una funcion vacía.
* * **self**: Puntero al Objeto que se clickeó.
> Método llamado al hacer click en el objeto en cuestion.
