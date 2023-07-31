#include "Bullet.h"

Bullet::Bullet()
{
	
}
// Actualiza la posiccion de la bala en funcion de su movimiento en nuestro caso con 
// direccion y velocidad. Dependiendo del valor de direc de movera en una direccion
Bullet::Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed,int direc)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
	this->direc = direc;
	if(this->direc == 1 || this->direc == 3){
		this->shape.setRotation(90);
	} 
}

Bullet::~Bullet()
{

}

// limites
const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

// dibujar la bala en la ventana o en el objetivo (target) proporcionado. 
// La función draw() de la clase "sf::RenderTarget" se utiliza para dibujar 
// la forma ("shape") de la bala en el objetivo que se pasa como argumento.
void Bullet::update()
{
	//Movement
	if(this->direc==0)
	this->shape.move(0,(this->movementSpeed * this->direction.y));
	//RIGTH
	else if (this->direc==1)
	this->shape.move(-(this->movementSpeed * this->direction.y),0);
	//BOTTOM
	else if (this->direc==2)
	this->shape.move(0,-(this->movementSpeed * this->direction.y));
	//LEFT
	else if (this->direc==3)
	this->shape.move((this->movementSpeed * this->direction.y),0);
}

//dibujar por acciones
void Bullet::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}