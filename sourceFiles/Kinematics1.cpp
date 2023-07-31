#include "Kinematics1.h"


void Kinematics::initVariables(){
    this->font = new sf::Font();
    this->font->loadFromFile("fonts/Dosis-Light.ttf");
    this->window = 0;
}
void Kinematics::initTexture(){
    this->texture.loadFromFile("Textures/apert-invasion.jpg");
    this->texture2.loadFromFile("Textures/potencias-eje.jpg");
}
void Kinematics::initSprite(){
    this->sprite = new sf::Sprite(texture);
    this->rectangle = new sf::RectangleShape(sf::Vector2f(700, 100));
    this->rectangle->setFillColor(sf::Color::Black);
    float sc = 600.f/this->sprite->getGlobalBounds().height;
    this->sprite->scale(sc,sc);
}
void Kinematics::initText(){
    this->texto = new sf::Text();
    this->texto->setString(L"Alemania invadió Polonia el 1 de septiembre de 1939");
    this->texto->setFont(*font);
    this->texto->setCharacterSize(20);
    this->texto->setFillColor(sf::Color(255,255,255,0));

    this->texto2 = new sf::Text();
    this->texto2->setString(L"así dio inicio a la Segunda Guerra Mundial");
    this->texto2->setFont(*font);
    this->texto2->setCharacterSize(20);
    this->texto2->setFillColor(sf::Color(255,255,255,0));
}

Kinematics::Kinematics(sf::Vector2u sz){
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initText();
    this->size = sz;
    this->setPosition(sz);
}
Kinematics::~Kinematics(){
  delete font;
	delete rectangle;
	delete texto;
	delete texto2;
	delete sprite;
}
const int Kinematics::getWindow() const{
    return this->window;
}

void Kinematics::setPosition(sf::Vector2u sz){
  this->rectangle->setPosition(0,sz.y - this->rectangle->getSize().y);
  this->texto->setPosition(10,sz.y - 80);
  this->texto2->setPosition(10,sz.y - 40);
}


void Kinematics::update(sf::Clock *clock){
    if (clock->getElapsedTime().asSeconds() >= 6)
    {
        if(this->window == 0){
            this->sprite = new sf::Sprite(texture2);
            this->window = 1;
            this->texto->setString("Nosotros somos un tanke de la Alianza");
            this->texto->setFillColor(sf::Color(255,255,255,0));
            this->texto2->setString("Vamos a enfretarnos contra el eje(Italia,Alemani.China)");
            this->texto2->setFillColor(sf::Color(255,255,255,0));

            float sc = sc = 700.f/this->sprite->getGlobalBounds().width;
            this->sprite->scale(sc,sc);
            clock->restart();
        }else if (this->window == 1){
            this->window = 2;
            this->texto->setString("Batalla de Stalingrado");
            this->texto->setFillColor(sf::Color(255,255,255,0));
            this->texto->setCharacterSize(30);
            this->texto->setPosition(this->size.x / 2 - this->texto->getLocalBounds().width / 2,
                                this->size.y / 2 - this->texto->getLocalBounds().height / 2);
            this->texto2->setString("17 de julio de 1942 - 2 de febrero de 1943");
            this->texto2->setFillColor(sf::Color(255,255,255,0));
            this->texto2->setCharacterSize(30);
            this->texto2->setPosition(this->size.x / 2 - this->texto2->getLocalBounds().width / 2,
                                this->size.y / 2 - this->texto2->getLocalBounds().height / 2 + 40);
            clock->restart();
        }else if(this->window == 2){
            this->window = 3;
            clock->restart();
        }
    }else if (clock->getElapsedTime().asSeconds() >= 3)
    {
      this->texto2->setFillColor(sf::Color(255,255,255,255));
    }else if (clock->getElapsedTime().asSeconds() >= 2.6)
    {
      this->texto2->setFillColor(sf::Color(255,255,255,170));
    }else if (clock->getElapsedTime().asSeconds() >= 2.3)
    {
      this->texto2->setFillColor(sf::Color(255,255,255,85));
    }else if (clock->getElapsedTime().asSeconds() >= 1){
      this->texto->setFillColor(sf::Color(255,255,255,255));
    }else if (clock->getElapsedTime().asSeconds() >= 0.6)
    {
      this->texto->setFillColor(sf::Color(255,255,255,170));
    }else if (clock->getElapsedTime().asSeconds() >= 0.3){
      this->texto->setFillColor(sf::Color(255,255,255,85));
    }
}
void Kinematics::render(sf::RenderTarget& target,sf::Clock *clock){
    if(this->window == 0){
      target.draw(*this->sprite);
      target.draw(*this->rectangle);
    }else if (this->window == 1){
      target.draw(*this->sprite);
      target.draw(*this->rectangle);
    }
    target.draw(*this->texto);
    if (clock->getElapsedTime().asSeconds() >= 2)
    target.draw(*this->texto2);
}

void Kinematics::render(sf::RenderTarget& target){
    if(this->window == 0){
      target.draw(*this->sprite);
      target.draw(*this->rectangle);
    }else if (this->window == 1){
      target.draw(*this->sprite);
      target.draw(*this->rectangle);
    }
    target.draw(*this->texto);
    target.draw(*this->texto2);
}