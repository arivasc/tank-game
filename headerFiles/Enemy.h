#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	unsigned pointCount;	//(vértices) que tendrá la forma del enemigo. 
	sf::Texture texture;	//textura para nuestro enemy
	//sf::CircleShape shape;
	sf::Sprite* shape;		//representar graficamente en pantalla
	int type;				//tipo de enemigo
	float speed;			//velocidad de movimiento
	int hp;					//puntos de vida
	int hpMax;				//max de vida
	int damage;				//dano capaz de inflingir
	int points;				//gain para player

	void initVariables();
	void initShape();

public:
	Enemy(float pos_x, float pos_y);
	~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;	//limites del enemy en pantalla
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif //!ENEMY_H