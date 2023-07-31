#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#define DTOP 0
#define DRIGHT 1
#define DBOTTOM 2
#define DLEFT 3

class Player{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;
	sf::IntRect rectSourceSprite;

	int hp;
	int hpMax;

	//Private functions
	void initVariables();
	void initTexture();
	void initSprite();
    
	//Direccion
    int direc;

public:
	Player();
	virtual ~Player();

	//Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getDireccion() const;
	const int& getHpMax() const;

	//Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setDireccion(const int x);
	void setHp(const int hp);
	void loseHp(const int value);

	//Functions
	void spingTop();
	void spingBottom();
	void spingRight();
	void spingLeft();
	void move(const float dirX, const float dirY);
	const bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};
#endif