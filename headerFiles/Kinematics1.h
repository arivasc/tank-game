#ifndef KINEMATICS1_H
#define KINEMATICS1_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class Kinematics{
private:
	sf::Font *font;
	sf::RectangleShape *rectangle;
	sf::Text *texto;
	sf::Text *texto2;
	sf::Vector2u size;
	sf::Texture texture;
	sf::Texture texture2;
	sf::Sprite *sprite;
	int window;

	//Private functions
	void initVariables();
	void initTexture();
	void initSprite();
    void initText();
public:
	Kinematics(sf::Vector2u sz);
	virtual ~Kinematics();
	const int getWindow() const;
	void setPosition(sf::Vector2u sz);
	void update(sf::Clock *reloj);
	void render(sf::RenderTarget& target,sf::Clock *clock);
	void render(sf::RenderTarget& target);
};
#endif