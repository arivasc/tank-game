#include "menu.h"


void Menu::initVariables(){
    this->font = new sf::Font();
    this->font->loadFromFile("fonts/Dosis-Light.ttf");
    this->window = 0;
}
void Menu::initTexture(){
    this->texture.loadFromFile("Textures/bgmen.jpeg");
    this->texture2.loadFromFile("Textures/play.png");
    this->texture3.loadFromFile("Textures/control.png");
    this->texture4.loadFromFile("Textures/blacc.png");
    this->texture5.loadFromFile("Textures/x.png");
}
void Menu::initSprite(){
    this->sprite = new sf::Sprite(this->texture);
    this->sprite2 = new sf::Sprite(this->texture2);
    this->sprite3 = new sf::Sprite(this->texture3);
    this->sprite4 = new sf::Sprite(this->texture4);
    this->sprite5 = new sf::Sprite(this->texture5);

    float sc = 700.f/this->sprite->getGlobalBounds().height;
    this->sprite->scale(sc,sc);
    this->sprite2->scale(0.5,0.5);
    this->sprite3->scale(0.5,0.5);
    this->sprite4->scale(500/this->sprite4->getGlobalBounds().width,500/this->sprite4->getGlobalBounds().height);
    this->sprite5->scale(0.4,0.4);
}
void Menu::initText(){
    this->texto = new sf::Text();
    this->texto->setFont(*this->font);
    this->texto->setString("Arriba : W\nAbajo : S\nDerecha : D\nIzquiersa : A\nDisparo : click izquierdo");
    this->texto->setCharacterSize(40);
    this->texto->setFillColor(sf::Color::White);
    this->texto->setPosition(this->sprite4->getGlobalBounds().left+(this->sprite4->getGlobalBounds().width/2)-(this->texto->getGlobalBounds().width/2)+50,
                this->sprite4->getGlobalBounds().top+(this->sprite4->getGlobalBounds().height/2)-(this->texto->getGlobalBounds().height/2)+50);

}


Menu::Menu(sf::Vector2u sz){
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initText();
    //this->initSound();
    this->size = sz;
    this->setPosition(sz);
}
Menu::~Menu(){
    delete this->font;
	delete this->texto;
    delete this->sprite;
    delete this->sprite2;
    delete this->sprite3;
    delete this->sprite4;
    delete this->sprite5;
}
const int Menu::getWindow() const{
    return this->window;
}

void Menu::setPosition(sf::Vector2u sz){
    this->sprite2->setPosition(50,50);
    this->sprite3->setPosition(50,200);
    this->sprite4->setPosition((sz.x-this->sprite4->getGlobalBounds().width)/2,(sz.y-this->sprite4->getGlobalBounds().height)/2);
    this->sprite5->setPosition(this->sprite4->getGlobalBounds().left+this->sprite4->getGlobalBounds().width-this->sprite5->getGlobalBounds().width-25,
                      this->sprite4->getGlobalBounds().top+20);
}


void Menu::update(sf::RenderWindow& target,sf::Sound *sound){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(this->window == 0){
            if(this->sprite2->getGlobalBounds().contains(sf::Mouse::getPosition(target).x,sf::Mouse::getPosition(target).y)){
                sound->setPlayingOffset(sf::seconds(0.f));
                sound->play();
                this->window = 1;
            }else if (this->sprite3->getGlobalBounds().contains(sf::Mouse::getPosition(target).x,sf::Mouse::getPosition(target).y))
            {
                sound->setPlayingOffset(sf::seconds(0.f));
                sound->play();
                this->window = 2;
            }
        }else if (this->window == 2){
            if(this->sprite5->getGlobalBounds().contains(sf::Mouse::getPosition(target).x,sf::Mouse::getPosition(target).y)){
                sound->setPlayingOffset(sf::seconds(0.f));
                sound->play();
                this->window = 0;
            }
        } 
    }

    if(this->window == 0){
        if(this->sprite2->getGlobalBounds().contains(sf::Mouse::getPosition(target).x,sf::Mouse::getPosition(target).y)){
            this->sprite2->setScale(sf::Vector2f(0.55, 0.55));
        }else{
            this->sprite2->setScale(sf::Vector2f(0.5, 0.5));
        }

        if(this->sprite3->getGlobalBounds().contains(sf::Mouse::getPosition(target).x,sf::Mouse::getPosition(target).y)){
            this->sprite3->setScale(sf::Vector2f(0.55, 0.55));
        }else{
            this->sprite3->setScale(sf::Vector2f(0.5, 0.5));
        }
    }else if (this->window == 2){
        if(this->sprite5->getGlobalBounds().contains(sf::Mouse::getPosition(target).x,sf::Mouse::getPosition(target).y)){
            this->sprite5->setScale(sf::Vector2f(0.45, 0.45));
        }else{
            this->sprite5->setScale(sf::Vector2f(0.4, 0.4));
        }
    }
}

void Menu::render(sf::RenderTarget& target){
    target.draw(*this->sprite);
    if(this->window == 2){
      target.draw(*this->sprite4);
      target.draw(*this->texto);
      target.draw(*this->sprite5);
    }else if(this->window == 0){
      target.draw(*this->sprite2);
      target.draw(*this->sprite3);
    }
}