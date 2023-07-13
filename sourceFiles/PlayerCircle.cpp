#include "PlayerCircle.h"

void PlayerCircle::initVariables()
{
	this->movementSpeed = 2.f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
	this->d45 = false;
	this->direc = DTOP;
}

void PlayerCircle::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("Textures/tankR.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->textureBase.loadFromFile("Textures/circulosPower.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void PlayerCircle::initSprite()
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
	sf::Vector2f center(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height	 / 2);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->rectSourceSprite);

	//Resize the sprite
	this->sprite.scale(3.0f, 3.0f);
	this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(42.0f, 4.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
	//this->sprite.setOrigin(0.f,72.f);
	//this->sprite.setOrigin(this->sprite.getGlobalBounds().width/2,this->sprite.getGlobalBounds().height/2);



	//SPRITE BASE
	this->rectSourceSpriteBase = sf::IntRect(32, 32, 160, 160);
	this->spriteBase.setTexture(this->textureBase);
	this->spriteBase.setTextureRect(this->rectSourceSpriteBase);
	float sca= (3*54.f)/160.f;
	this->spriteBase.scale(sca,sca);
}

PlayerCircle::PlayerCircle()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

PlayerCircle::~PlayerCircle()
{

}

const sf::Vector2f & PlayerCircle::getPos() const
{
	return this->sprite.getPosition();
}

const int& PlayerCircle::getDireccion() const{
	return this->direc;
}

const sf::FloatRect PlayerCircle::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f & PlayerCircle::getPosCircle() const
{
	return this->spriteBase.getPosition();
}

const int& PlayerCircle::getDireccionCircle() const{
	return this->direc;
}

const sf::FloatRect PlayerCircle::getBoundsCircle() const
{
	return this->spriteBase.getGlobalBounds();
}

const int & PlayerCircle::getHp() const
{
	return this->hp;
}

const int & PlayerCircle::getHpMax() const
{
	return this->hpMax;
}

void PlayerCircle::setPosition(const sf::Vector2f pos)
{
	sf::Vector2f center(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height	 / 2);
	this->spriteBase.setPosition(pos);
	if(this->direc == DTOP || this->direc == DBOTTOM){
		this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(42.0f, 4.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
	}else{
		this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(4.0f, 42.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
	}
}

void PlayerCircle::setPosition(const float x, const float y)
{
	sf::Vector2f center(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height	 / 2);
	this->spriteBase.setPosition(x, y);
	if(this->direc == DTOP || this->direc == DBOTTOM){
		this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(42.0f, 4.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
	}else{
		this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(4.0f, 42.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
	}
}

void PlayerCircle::setDireccion(const int x){
	this->direc = x;
}

void PlayerCircle::setHp(const int hp)
{
	this->hp = hp;
}

void PlayerCircle::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void PlayerCircle::spingRight(){
	sf::Vector2f center(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height	 / 2);
	this->rectSourceSprite = sf::IntRect(7.0f, 16.0f, 48,25);
	this->sprite.setTextureRect(rectSourceSprite);
	// if(this->direc == DTOP && d45 == false){
	// 	sf::IntRect rectSourceSprite(62.0f, 7.0f, 48,40);
	// 	this->sprite.setTextureRect(rectSourceSprite);
	// 	d45 = true;
	// }
	this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(4.0f, 42.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
}

void PlayerCircle::spingBottom(){
	sf::Vector2f center(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height	 / 2);
	this->rectSourceSprite = sf::IntRect(352, 2, 25,48);
	this->sprite.setTextureRect(rectSourceSprite);
	this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(42.0f, 4.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
}
void PlayerCircle::spingTop(){
	sf::Vector2f center(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height	 / 2);
	this->rectSourceSprite = sf::IntRect(130, 2, 25,48);
	this->sprite.setTextureRect(rectSourceSprite);
	// if(this->direc == DRIGHT && d45 == false){
	// 	sf::IntRect rectSourceSprite(62.0f, 7.0f, 48,40);
	// 	this->sprite.setTextureRect(rectSourceSprite);
	// 	d45 = true;
	// }
	this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(42.0f, 4.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
}
void PlayerCircle::spingLeft(){
	sf::Vector2f center(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height	 / 2);
	this->rectSourceSprite = sf::IntRect(230, 16, 48,25);
	this->sprite.setTextureRect(rectSourceSprite);
	this->sprite.setPosition(this->spriteBase.getPosition() + sf::Vector2f(4.0f, 42.0f) + center - sf::Vector2f(this->spriteBase.getGlobalBounds().width / 2, this->spriteBase.getGlobalBounds().height/ 2));
}

void PlayerCircle::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	this->spriteBase.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool PlayerCircle::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void PlayerCircle::updateAttack()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

//Functions
void PlayerCircle::update()
{
	this->updateAttack();
}

void PlayerCircle::render(sf::RenderTarget& target)
{
	target.draw(this->spriteBase);
	target.draw(this->sprite);
}