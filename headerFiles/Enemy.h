#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	unsigned pointCount;
	sf::Texture texture;
	//sf::CircleShape shape;
	sf::Sprite* shape;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initVariables();
	void initShape();

public:
	Enemy(float pos_x, float pos_y);
	~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif //!ENEMY_H