#include "Game.h"

//Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Tank - Game");
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	//Init point text
	this->pointText.setPosition(700.f, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f, 
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Textures/background1.jpg"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << "\n";
	}

	this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::initSystems()
{
	this->points = 0;
}

void Game::initPlayer()
{
	//this->player = new Player();
	this->player = new PlayerCircle();
	this->previousPosition = new sf::Vector2f(this->player->getPosCircle());
}

void Game::initObstacle(){
	this->obstacle = new ObstacleB(3*54.1f,650.f);
	this->obstacles.push_back(new ObstacleB(300.f,650.f));
	this->obstacles.push_back(new ObstacleB(850.f,650.f));
	this->obstacles.push_back(new ObstacleB(0.f,650.f));
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

//Con/Des
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
	this->initSystems();
	this->initObstacle();
	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->obstacle;
	delete this->previousPosition;
	//Delete textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}

	//Delete bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}

	//Delete enemies
	for (auto *i : this->enemies)
	{
		delete i;
	}
}

//Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();

		if(this->player->getHp() > 0)
			this->update();

		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		if(this->player->getDireccion() != DLEFT){
			this->player->spingLeft();
			this->player->setDireccion(DLEFT);
		}
		this->player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if(this->player->getDireccion() != DRIGHT){
			this->player->spingRight();
			this->player->setDireccion(DRIGHT);
		}
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if(this->player->getDireccion() != DTOP){
			this->player->spingTop();
			this->player->setDireccion(DTOP);
		}
		this->player->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		if(this->player->getDireccion() != DBOTTOM){
			this->player->spingBottom();
			this->player->setDireccion(DBOTTOM);
		}
		this->player->move(0.f, 1.f);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(
			new Bullet(
			this->textures["BULLET"], 
			this->player->getPos().x + this->player->getBounds().width/2.f, 
			this->player->getPos().y, 
			0.f, 
			-1.f, 
			5.f,
			this->player->getDireccion()
			)
		);
	}
}

void Game::updateGUI()
{
	std::stringstream ss;

	ss << "Points: " << this->points;

	this->pointText.setString(ss.str());

	//Update player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
	//Left world collision
	if (this->player->getBoundsCircle().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBoundsCircle().top);
	}
	//Right world collison
	else if (this->player->getBoundsCircle().left + this->player->getBoundsCircle().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBoundsCircle().width, this->player->getBoundsCircle().top);
	}

	//Top world collision
	if (this->player->getBoundsCircle().top < 0.f)
	{
		this->player->setPosition(this->player->getBoundsCircle().left, 0.f);
	}
	//Bottom world collision
	else if (this->player->getBoundsCircle().top + this->player->getBoundsCircle().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBoundsCircle().left, this->window->getSize().y - this->player->getBoundsCircle().height);
	}
}

void Game::updateCollisionObstacle(){
	for(auto *obs : this->obstacles){
		if(this->player->getBoundsCircle().intersects(obs->getBounds())){
			this->player->setPosition(*this->previousPosition);
		}else{
			*this->previousPosition = this->player->getPosCircle();
		}
	}
};


void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f ||
		    bullet->getBounds().top >= this->window->getSize().y ||
			bullet->getBounds().left >= this->window->getSize().x ||
			bullet->getBounds().left + bullet->getBounds().width < 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}

		++counter;
	}
}

void Game::updateEnemies()
{
	//Spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x-20.f, -100.f));
		this->spawnTimer = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto *enemy : this->enemies)
	{
		enemy->update();

		//Bullet culling (top of screen)
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//Enemy player collision
		else if(enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}
	}
}

void Game::update()
{
	this->updateInput();

	this->player->update();

	this->updateCollision();

	this->updateCollisionObstacle();

	this->updateBullets();

	this->updateEnemies();

	this->updateCombat();

	this->updateGUI();
	this->player->updateBar();
	this->updateWorld();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	//Draw world
	this->renderWorld();

	//Draw all the stuffs
	this->player->render(*this->window);
	for(auto *obs : this->obstacles){
		obs->render(*this->window);
	}

	//this->obstacle->render(*this->window);

	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->renderGUI();

	//Game over screen
	if (this->player->getHp() <= 0)
		this->window->draw(this->gameOverText);

	this->window->display();
}