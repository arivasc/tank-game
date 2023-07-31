#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Obstacle
{
private:
    sf::Sprite sprite;
    // sf::Sprite sprite2;
    // sf::Sprite sprite3;
	// sf::Sprite obstacle;
    sf::Texture texture;
    // sf::RenderTexture renderTexture;
    sf::IntRect rectSourceSprite;
    //sf::RenderTexture renderTexture;
    void initTexture();
    void initSprite();
public:
	Obstacle();
	Obstacle(float pos_x, float pos_y);
	~Obstacle();

	//Accessor
	const sf::FloatRect getBounds() const;

	void render(sf::RenderTarget& target);
};

#endif