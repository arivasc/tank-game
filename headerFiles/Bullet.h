#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:

	sf::Sprite shape;	//Representar graficamente en pantalla

	sf::Vector2f direction;		//Tomamos un vector en 2d
	float movementSpeed;	//decimal que determina la velocidad de movimiento
	int direc; 		//nesecitamos un estado que determine la direccion
public:
	Bullet();
	//Constructor sobrecargado que tomara la tex, posicion, velocidad, y la direc
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed,int direc);
	//Constructor virtual de la clase
	virtual ~Bullet();

	//Accessor
	const sf::FloatRect getBounds() const;

	void update();		//Actualiza la posicion de la bala

	
	void render(sf::RenderTarget* target);		//dibujar por acciones
};

#endif // !BULLET_H