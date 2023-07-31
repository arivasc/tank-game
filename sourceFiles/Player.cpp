#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;

	this->direc = DTOP;
}

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

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

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

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	//this->spriteBase.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

//Functions
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	//target.draw(this->spriteBase);
	target.draw(this->sprite);
}