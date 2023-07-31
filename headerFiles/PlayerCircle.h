#ifndef PLAYERCIRCLE_H
#define PLAYERCIRCLE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tank.h"

#define DTOP 0
#define DRIGHT 1
#define DBOTTOM 2
#define DLEFT 3

class PlayerCircle:public Tank{
private:
	sf::Sprite sprite;
    sf::Sprite spriteBase;
	sf::Texture texture;
	sf::Texture textureBase;

	//float movementSpeed;
    bool d45;
	float attackCooldown;
	float attackCooldownMax;
	sf::IntRect rectSourceSprite;
	sf::IntRect rectSourceSpriteBase;

	//BARRA
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	int hp;
	int hpMax;

	//Private functions
	void initVariables() override;
	//void initVariables();
	void initTexture();
	void initSprite();
    void initBar();
	//Direccion
    int direc;

public:
	PlayerCircle();
	virtual ~PlayerCircle();


	//Accessor
	const sf::Vector2f& getPos() const;
    const sf::Vector2f& getPosCircle() const;
	const sf::FloatRect getBounds() const override;
	//const sf::FloatRect getBounds() const;
    const sf::FloatRect getBoundsCircle() const;
	const int& getHp() const;
	const int& getDireccion() const;
    const int& getDireccionCircle() const;
	const int& getHpMax() const;

	//Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y) override;
	//void setPosition(const float x, const float y);
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
	void updateBar();
	void update();
	void render(sf::RenderTarget& target);
	sf::Sprite* getSprite();
};
#endif