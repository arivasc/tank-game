#ifndef MENU_H
#define MENU_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
// #include <SFML/Audio/Sound.hpp>
// #include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio.hpp>

class Menu{
private:
	sf::Font *font;
	sf::Text *texto;
	sf::Vector2u size;
	sf::Texture texture;
	sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture texture5;
	sf::Sprite *sprite;
    sf::Sprite *sprite2;
    sf::Sprite *sprite3;
    sf::Sprite *sprite4;
    sf::Sprite *sprite5;
	int window;

	//Private functions
	void initVariables();
	void initTexture();
	void initSprite();
    void initText();
public:
	Menu(sf::Vector2u sz);
	virtual ~Menu();
	const int getWindow() const;
	void setPosition(sf::Vector2u sz);
	void update(sf::RenderWindow& target,sf::Sound *sound);
	void render(sf::RenderTarget& target);
};
#endif