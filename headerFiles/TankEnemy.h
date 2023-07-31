#ifndef TANKENEMY_H
#define TANKENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tank.h"

class TankEnemy:public Tank
{
private:

	sf::Sprite* sprite;
    sf::Sprite* bullet;
    int cam;
    int atack;
	//sf::Vector2f direction;
	//float movementSpeed;
	//int direc;
	void initVariables() override; 
	//void initVariables(); 
    void initSprite(sf::Texture* texture,sf::Texture* textureB);
public:
	TankEnemy();
	TankEnemy(sf::Texture* texture,sf::Texture* textureB, float pos_x,float pos_y);
	virtual ~TankEnemy();

	//Accessor
	const sf::FloatRect getBounds() const override;
	//const sf::FloatRect getBounds() const;
    void setPosition(float pos_x, float pos_y) override;
    //void setPosition(float pos_x, float pos_y);
	void update(sf::Sprite* player);
	void render(sf::RenderTarget* target);
};

#endif // TANKENEMY