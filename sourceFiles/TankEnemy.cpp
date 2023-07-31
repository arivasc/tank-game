#include "TankEnemy.h"

void TankEnemy::initVariables(){
    this->movementSpeed = 0.5f;
}
void TankEnemy::initSprite(sf::Texture* texture,sf::Texture* textureB){
    this->sprite = new sf::Sprite();
    this->bullet = new sf::Sprite();
    this->sprite->setTexture(*texture);
    this->bullet->setTexture(*textureB);
    this->sprite->scale(50/this->sprite->getGlobalBounds().width,50/this->sprite->getGlobalBounds().height);
    this->sprite->setOrigin(this->sprite->getLocalBounds().width / 2.0f, this->sprite->getLocalBounds().height / 2.0f);
}

TankEnemy::TankEnemy(){}
TankEnemy::TankEnemy(sf::Texture* texture,sf::Texture* textureB, float pos_x,float pos_y){
    this->cam = 0;
    this->atack = 0;
    this->initVariables();
    this->initSprite(texture,textureB);
    this->setPosition(pos_x,pos_y);
    
}
TankEnemy::~TankEnemy(){
    delete this->sprite;
    delete this->bullet;
}

//Accessor
const sf::FloatRect TankEnemy::getBounds() const{
    return this->sprite->getGlobalBounds();
}
void TankEnemy::setPosition(float pos_x, float pos_y){
    this->sprite->setPosition(pos_x,pos_y);  
}
void TankEnemy::update(sf::Sprite* player){

    if(this->sprite->getGlobalBounds().top <= 300 && cam == 0){
      this->sprite->move(0.f,this->movementSpeed);
    }else if(this->sprite->getGlobalBounds().top >= 10 && cam == 1){
      this->sprite->move(0.f,-this->movementSpeed);
    }else if(this->cam == 0){
      this->sprite->setRotation(90.0f);
      this->cam = 1;
    }else if(this->cam == 1){
      this->sprite->setRotation(this->sprite->getRotation() - 90.0f);
      this->cam = 0;
    }

    sf::FloatRect transformedBounds = player->getGlobalBounds();
    //sf::Transform transform = player->getTransform();
    //transformedBounds = transform.transformRect(transformedBounds);

    sf::Vector2f posA = this->sprite->getPosition();
    sf::Vector2f posB = player->getPosition();

    if(atack == 0 && transformedBounds.top > this->sprite->getPosition().y + this->sprite->getGlobalBounds().height &&
        transformedBounds.left + transformedBounds.width > this->sprite->getPosition().x &&
        transformedBounds.left < this->sprite->getPosition().x + this->sprite->getGlobalBounds().width
        /* && abs(posB.y - posA.y) <= 100*/){
            this->bullet->setPosition(this->sprite->getPosition().x - 25 + this->sprite->getGlobalBounds().width/2.f,
            this->sprite->getPosition().y);
            atack = 1;
    }
    if(this->atack == 1 && this->bullet->getGlobalBounds().top <= 500){
        this->bullet->move(0,3.f);
    }else{
        this->atack = 0;
    }

}
void TankEnemy::render(sf::RenderTarget* target){
    target->draw(*this->sprite);
    if(this->atack == 1){
        target->draw(*this->bullet);
    }
}