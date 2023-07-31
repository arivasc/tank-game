#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "PlayerCircle.h"
#include "Bullet.h"
#include "Enemy.h"
#include "ObstacleB.h"
#include "kinematics1.h"
#include "TankEnemy.h"
#include "menu.h"
#include <vector>
#include <SFML/Audio.hpp>

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::SoundBuffer buffer;
    sf::Sound sonido;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;
	Kinematics* kinematics1;
	Menu* menu;
	int finKinematics1;
	int finMenu; 

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	sf::Clock* clock;
	//Systems
	unsigned points;

	//OBSTACLE
	ObstacleB* obstacle;
	std::vector<ObstacleB*> obstacles;
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
	TankEnemy* tankEnemy;
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
