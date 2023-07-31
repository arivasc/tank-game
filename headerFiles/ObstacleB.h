#ifndef OBSTACLEB_H
#define OBSTACLEB_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class ObstacleB
{
private:
    std::vector<sf::Sprite*> obstacles;
    //sf::Sprite spriteDos;
    //sf::Sprite sprite3;
	// sf::Sprite obstacle;
    sf::Texture texture;
    sf::FloatRect bounds;
    int direc;
    //sf::Texture texture2;
    // sf::RenderTexture renderTexture;
    //sf::IntRect rectSourceSprite;
    //sf::RenderTexture renderTexture;
    void initTexture();
    void initSprite();
public:
	ObstacleB();
	ObstacleB(float pos_x, float pos_y,int dir);
	~ObstacleB();

	//Accessor
	const sf::FloatRect getBounds() const;

	void render(sf::RenderTarget& target);
};

#endif