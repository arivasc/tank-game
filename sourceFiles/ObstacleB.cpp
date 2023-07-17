#include "ObstacleB.h"

void ObstacleB::initTexture(){
    if (!this->texture.loadFromFile("Textures/obs2.jpg"))
	{
		std::cout << "ERROR::OBSTACLE::INITTEXTURE::Could not load texture file." << "\n";
	}
}
void ObstacleB::initSprite(){
    sf::IntRect rectSourceSprite(0, 0, 135,135);
    obstacles.push_back(new sf::Sprite(this->texture,rectSourceSprite));
    obstacles.push_back(new sf::Sprite(this->texture,rectSourceSprite));
    //obstacles.push_back(new sf::Sprite(this->texture,rectSourceSprite));
    //obstacles.push_back(new sf::Sprite(this->texture,rectSourceSprite));
    for(sf::Sprite* s : this->obstacles){
        s->scale(0.5,0.5);
    }
}
ObstacleB::ObstacleB(){}
ObstacleB::ObstacleB(float pos_x, float pos_y){
    this->initTexture();
    this->initSprite();
    float x = pos_x;
    this->bounds = sf::FloatRect(0,0,0,0);
    for(sf::Sprite* s : this->obstacles){
        s->setPosition(x,pos_y);
        x += 135.f*0.5f;
        if(bounds.width == 0){
            this->bounds = s->getGlobalBounds();
        }else{
            this->bounds.width += s->getGlobalBounds().width;
        }
    }
    
}
ObstacleB::~ObstacleB(){
    for(sf::Sprite* s : this->obstacles){
        delete s;
    }
}

const sf::FloatRect ObstacleB::getBounds() const
{
	return this->bounds;
}

void ObstacleB::render(sf::RenderTarget& target){
    for(sf::Sprite* s : this->obstacles){
        target.draw(*s);
    }
}


