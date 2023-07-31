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
    obstacles.push_back(new sf::Sprite(this->texture,rectSourceSprite));
    obstacles.push_back(new sf::Sprite(this->texture,rectSourceSprite));
    float sca = 50.f/135.f;
    for(sf::Sprite* s : this->obstacles){
        s->scale(sca,sca);
    }
}
ObstacleB::ObstacleB(){}
ObstacleB::ObstacleB(float pos_x, float pos_y,int dir){
    this->initTexture();
    this->initSprite();
    this->direc = dir;
    this->bounds = sf::FloatRect(0,0,0,0);
    float sca = 50.f/135.f;
    if(this->direc == 0){
        float x = pos_x;
        for(sf::Sprite* s : this->obstacles){
            s->setPosition(x,pos_y);
            x += 135.f*sca;
            if(bounds.width == 0){
                this->bounds = s->getGlobalBounds();
            }else{
                this->bounds.width += s->getGlobalBounds().width;
            }
        }    
    }else if (this->direc == 1){
        float y = pos_y;
        for(sf::Sprite* s : this->obstacles){
            s->setPosition(pos_x,y);
            y += 135.f*sca;
            if(bounds.height == 0){
                this->bounds = s->getGlobalBounds();
            }else{
                this->bounds.height += s->getGlobalBounds().height;
            }
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


