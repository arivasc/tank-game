#include "Bullet.h"

Bullet::Bullet()
{
	
}

Bullet::Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	//Movement
	//this->shape.move(movimento en x,moviento en y);
	//ABAJO
	this->shape.move(0,-(this->movementSpeed * this->direction.y));
	//ARRIBA
	//this->shape.move(0,(this->movementSpeed * this->direction.y));
	//IZQUIERDA
	//this->shape.move((this->movementSpeed * this->direction.y),0);
	//DERECHA
	//this->shape.move(-(this->movementSpeed * this->direction.y),0);
}

void Bullet::update(int i){
	//TOP
	if(i==0)
	this->shape.move(0,-(this->movementSpeed * this->direction.y));
	//RIGTH
	else if (i==1)
	this->shape.move(-(this->movementSpeed * this->direction.y),0);
	//BOTTOM
	else if (i==2)
	this->shape.move(0,(this->movementSpeed * this->direction.y));
	//LEFT
	else if (i==3)
	this->shape.move((this->movementSpeed * this->direction.y),0);
}

void Bullet::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}