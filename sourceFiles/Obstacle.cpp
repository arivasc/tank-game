#include "Obstacle.h"

void Obstacle::initTexture(){
    if (!this->texture.loadFromFile("Textures/obs2.jpg"))
	{
		std::cout << "ERROR::OBSTACLE::INITTEXTURE::Could not load texture file." << "\n";
	}
}
void Obstacle::initSprite(){
    //this->rectSourceSprite = sf::IntRect (0, 0, 135,135);
    // this->sprite.setTexture(this->texture);
	// this->sprite.setTextureRect(this->rectSourceSprite);
    // this->sprite2 =sf::Sprite(this->texture,rectSourceSprite);
    // this->sprite3 =sf::Sprite(this->texture,rectSourceSprite);
    // sf::FloatRect sprite1Bounds = this->sprite.getGlobalBounds();
    // this->sprite2.setPosition(sprite1Bounds.left + sprite1Bounds.width, 0);
    // sprite1Bounds = this->sprite2.getGlobalBounds();
    // this->sprite3.setPosition(sprite1Bounds.left + sprite1Bounds.width, 0);
    // //sf::RenderTexture renderTexture;
    // if (!renderTexture.create(405, 135))
    // {
    //     std::cout << "ERROR::OBSTACLE::INITSPRITE::Could not load redenderTexture." << "\n";
    // }
    // this->renderTexture.clear(sf::Color::Transparent);
    // this->renderTexture.draw(this->sprite);
    // this->renderTexture.draw(this->sprite2);
    // this->renderTexture.draw(this->sprite3);
    // this->renderTexture.display();

    // this->obstacle = sf::Sprite(this->renderTexture.getTexture());
    // this->obstacle.scale(0.5,0.5);
    //this->obstacle.setPosition(3*52, 3*52);
}
Obstacle::Obstacle(){}
Obstacle::Obstacle(float pos_x, float pos_y){
    this->initTexture();
    this->initSprite();
    //this->sprite.setPosition(pos_x, pos_y);
}
Obstacle::~Obstacle(){}

// const sf::FloatRect Obstacle::getBounds() const
// {
// 	return this->sprite.getGlobalBounds();
// }

void Obstacle::render(sf::RenderTarget& target){
    //target.draw(this->sprite);
}


