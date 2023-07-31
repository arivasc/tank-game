#include "Player.h"

void Player::initVariables()
{
	// Inicializa las variables del jugador.
	this->movementSpeed = 2.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->direc = DTOP;	// Inicializa la dirección del jugador.
}

// carga la textura del jugador desde un archivo llamado "tankR.png". 
// Si la carga falla, muestra un mensaje de error en la consola.
void Player::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("Textures/tankR.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	// if (!this->textureBase.loadFromFile("Textures/circulosPower.png"))
	// {
	// 	std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	// }
}

// inicializa el sprite del jugador, estableciendo su textura y recorte. Configura el 
// sprite para que tenga un origen en (0,0) y lo escala para que sea tres veces más 
// grande que la textura original.
void Player::initSprite()
{
	// int tRightHorizonalWidth = 48;
	// int tRightHorizonalHeight = 25;
	// int tRightHorizonalX = 7;
	// int tRightHorizonalY = 16;	
	
	// int tLeftHorizonalWidth = 48;
	// int tLeftHorizonalHeight = 25;
	// int tLeftHorizonalX = 230;
	// int tLeftHorizonalY = 16;

	// int tTopVerticalWidth = 25;
	// int tTopVerticalHeight = 48;
	// int tTopVerticalX = 130;
	// int tTopVerticalY = 2;

	// int tBottomVerticalWidth = 25;
	// int tBottomVerticalHeight = 48;
	// int tBottomVerticalX = 348;
    // int tBottomVerticalY = 2;
	//horizontalRITH
	//sf::IntRect rectSourceSprite(7.0f, 16.0f, 48,25);

	//VerticalTOp
	//this->rectSourceSprite = sf::IntRect(130.0f, 2.0f, tTopVerticalWidth,tTopVerticalHeight);
	this->rectSourceSprite = sf::IntRect(130, 2, 25,48);
    //Horizontal left
	//this->rectSourceSprite = sf::IntRect(230.0f, 16.0f, tLeftHorizonalWidth,tLeftHorizonalHeight);
	//this->rectSourceSprite = sf::IntRect(230, 16, 48,25);
	
	//VerticalBottom
	//this->rectSourceSprite = sf::IntRect(352.0f, 2.0f, tBottomVerticalWidth,tBottomVerticalHeight);
	//this->rectSourceSprite = sf::IntRect(352, 2, 25,48);
	
	//45
	//sf::IntRect rectSourceSprite(62.0f, 7.0f, 48,40);

	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->rectSourceSprite);
	this->sprite.setOrigin(0.0f, 0.0f);
	//Resize the sprite
	this->sprite.scale(3.0f, 3.0f);
	//this->sprite.setOrigin(this->sprite.getGlobalBounds().width/2,this->sprite.getGlobalBounds().height/2);

	//SPRITE BASE
    sf::Sprite spriteBase;
	sf::Texture texture2;
	texture2.loadFromFile("Textures/circuloPower.png");
	sf::IntRect rectSourceSpriteBase = sf::IntRect(32, 32, 160, 160);
	spriteBase.setTexture(texture2);
	spriteBase.setTextureRect(this->rectSourceSprite);
	float sca= (3*48.f)/160.f;
	spriteBase.scale(sca,sca);
}

// Este es el constructor de la clase "Player", que llama a las 
// funciones de inicialización del jugador en su creación.
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

// Destructor
Player::~Player() {}

const sf::Vector2f & Player::getPos() const
{
	return this->sprite.getPosition();
}

const int& Player::getDireccion() const{
	return this->direc;
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int & Player::getHp() const
{
	return this->hp;
}

const int & Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
	//this->spriteBase.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
	//this->spriteBase.setPosition(x, y);
}

void Player::setDireccion(const int x){
	this->direc = x;
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

// se utilizan para cambiar el recorte del sprite 
// del jugador y hacer que se muestre en diferentes
// direcciones o animaciones.

void Player::spingRight(){
	this->rectSourceSprite = sf::IntRect(7.0f, 16.0f, 48,25);
	this->sprite.setTextureRect(rectSourceSprite);
}

void Player::spingBottom(){
	this->rectSourceSprite = sf::IntRect(352, 2, 25,48);
	this->sprite.setTextureRect(rectSourceSprite);
}
void Player::spingTop(){
	this->rectSourceSprite = sf::IntRect(130, 2, 25,48);
	this->sprite.setTextureRect(rectSourceSprite);
}
void Player::spingLeft(){
	this->rectSourceSprite = sf::IntRect(230, 16, 48,25);
	this->sprite.setTextureRect(rectSourceSprite);
}


// permite mover al jugador en función de las componentes 
// de dirección proporcionadas (dirX, dirY) y su velocidad
// de movimiento.
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	//this->spriteBase.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

// canAttack() permite verificar si el jugador puede atacar en función del tiempo transcurrido 
// desde el último ataque. Si el tiempo de reutilización de ataque (attackCooldown) 
// ha alcanzado el valor máximo (attackCooldownMax), entonces se puede realizar un 
// nuevo ataque y se reinicia el tiempo de reutilización.
const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

// updateAttack() actualiza el tiempo de reutilización de ataque (attackCooldown) 
// sumándole un valor constante de 0.5f al tiempo actual. Esto permite
// que el tiempo de reutilización aumente y eventualmente el jugador 
// pueda atacar nuevamente.
void Player::updateAttack()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

// update() actualizar el estado del jugador, en este caso, 
// solo se actualiza el tiempo de reutilización de ataque llamando a la función "updateAttack()".
//Functions
void Player::update()
{
	this->updateAttack();
}

//dibujar por acciones
void Player::render(sf::RenderTarget& target)
{
	//target.draw(this->spriteBase);
	target.draw(this->sprite);
}