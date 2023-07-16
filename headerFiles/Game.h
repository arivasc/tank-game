#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "PlayerCircle.h"
#include "Bullet.h"
#include "Enemy.h"
#include "ObstacleB.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	sf::Clock clock;
	//Systems
	unsigned points;

	//OBSTACLE
	ObstacleB* obstacle;

	//Player
	//Player* player;
	PlayerCircle* player;

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	sf::Vector2f* previousPosition;
	//Private functions
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();
	void initObstacle();
public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateCollisionObstacle();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();

	void renderGUI();
	void renderWorld();
	void render();
};
