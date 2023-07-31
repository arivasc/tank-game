#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Tank{
protected:
	//Variable de movimiento
	float movementSpeed;

	//Iniciar Variables
	virtual void initVariables();
public:
	Tank(){};
	~Tank(){};

	//retorna coordenadas y tamaño 
	virtual const sf::FloatRect getBounds() const;

	//añadir pocision
    virtual void setPosition(float pos_x, float pos_y);
	
};

#endif // TANK