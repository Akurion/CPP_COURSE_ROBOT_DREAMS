#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <math.h>
#include <cstdlib>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ResourcesManager.h"
#include "Background.h"
#include "Menu.h"
#include "FireRateBooster.h"
#include "HealthBooster.h"

void resetGame(Player& player, std::vector<Enemy>& enemies, int& shoottimer, int& enemySpawnTimer, int& score)
{
	player.HP = 10;
	enemies.clear();
	player.bullets.clear();
	shoottimer = 20;
	enemySpawnTimer = 0;
	score = 0;
}

int main()
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1280, 960), "SFML Space Shooter", sf::Style::Default);
	window.setFramerateLimit(60);

	ResourcesManager::loadResources();

	sf::Font& font = ResourcesManager::font;

	sf::Texture& playerTex = ResourcesManager::playerTex;
	sf::Texture& enemyTex = ResourcesManager::enemyTex;
	sf::Texture& bulletTex = ResourcesManager::bulletTex;

	sf::Text& scoreText = ResourcesManager::scoreText;
	sf::Text& gameOverText = ResourcesManager::gameOverText;
	sf::Text& ehpText = ResourcesManager::ehpText;
	sf::Text& hpText = ResourcesManager::hpText;
	sf::Text& fireboosterText = ResourcesManager::fireboosterText;

	sf::Sound& shootingSound = ResourcesManager::getSound("shootsound.wav");
	sf::Sound& enemydestroySound = ResourcesManager::getSound("enemysound.mp3");
	sf::Sound& maingameSound = ResourcesManager::getSound("maingamesound.mp3");
	sf::Sound& boosterpickedSound = ResourcesManager::getSound("boostersound.mp3");
	enemydestroySound.setVolume(30);
	boosterpickedSound.setVolume(70);

	int score = 0;
	Player player(&playerTex);
	int shoottimer = 20;


	int enemySpawnTimer = 0;
	int enemyShootingTimer = 30;
	std::vector<Enemy> enemies;
	InfiniteBackground background(window, 75);
	HealthBooster healthBooster;
	FireRateBooster fireRateBooster;
	Menu menu(window);

	maingameSound.setLoop(true);
	maingameSound.play();
	while (window.isOpen())
	{
		
		menu.handleInput();
		window.clear();
		

		if (menu.isVisible()) {
			menu.update();
			menu.render();

			if (menu.isEnterPressed()) {
				if (menu.getSelectedOption() == 1) {
					menu.hide();
					menu.setGameState(GAME);
					
				}
				else if (menu.getSelectedOption() == 2) {
					menu.setGameState(SETTINGS);
				}
				else if (menu.getSelectedOption() == 3) {
					window.close();
				}

				menu.handleInput();
			}
		}
		else {
			if (menu.getGameState() == GAME && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				menu.setGameState(MENU);
				menu.show();
			}
			else if (menu.getSelectedOption() == 1 && menu.getGameState() == GAME) {
				if (player.HP > 0)
				{
					
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
						player.shape.move(10.0f, 0.f);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
						player.shape.move(-10.0f, 0.f);

					hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
					hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));

					if (player.shape.getPosition().x <= 0)
						player.shape.setPosition(0.f, player.shape.getPosition().y);
					if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width)
						player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);


					if (shoottimer < 20)
						shoottimer++;
					if (enemyShootingTimer < 30)
						enemyShootingTimer++;

					if (fireRateBooster.isBoostActive())
					{
						fireRateBooster.update();
						window.draw(fireboosterText);
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shoottimer >= 20)
						{
							shootingSound.play();
							player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
							shoottimer = 10;
						}
					}
					else
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shoottimer >= 20)
						{
							shootingSound.play();
							player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
							shoottimer = 0;
						}
					}



					for (size_t i = 0; i < player.bullets.size(); i++)
					{
						player.bullets[i].shape.move(0.f, -10.f);
						if (player.bullets[i].shape.getPosition().y > window.getSize().y)
						{
							player.bullets.erase(player.bullets.begin() + i);
							break;
						}

						for (size_t k = 0; k < enemies.size(); k++)
						{

							if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
							{
								if (enemies[k].HP == 1)
								{
									score += enemies[k].HPMax * 100;
									if (rand() % 4 == 0) {
										if (rand() % 2 == 0) {
											boosterpickedSound.play();
											healthBooster.applyBoost(player);
										}
										else if(!fireRateBooster.isBoostActive())
										{
											window.draw(fireboosterText);
											boosterpickedSound.play();
											fireRateBooster.applyBoost(player, shoottimer);
										}
									}
									enemydestroySound.play();
									enemies.erase(enemies.begin() + k);
								}

								else
									enemies[k].HP--;

								player.bullets.erase(player.bullets.begin() + i);
								break;
							}
						}
					}
					for (size_t i = 0; i < enemies.size(); i++)
					{
						for (size_t j = 0; j < enemies[i].enemybullets.size(); j++)
						{
							enemies[i].enemybullets[j].shape.move(0.f, 5.f);
							enemies[i].enemybullets[j].shape.setColor(sf::Color::Red);
							window.draw(enemies[i].enemybullets[j].shape);

							if (enemies[i].enemybullets[j].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
							{
								player.HP--;
								enemies[i].enemybullets.erase(enemies[i].enemybullets.begin() + j);
								break;
							}
						}

						enemies[i].shape.move(0.f, 3.f);
						enemies[i].updateShooting();

						if (enemies[i].enemyShootingTimer >= 30)
						{
							enemies[i].enemybullets.push_back(Bullet(&bulletTex, enemies[i].shape.getPosition()));
							enemies[i].enemyShootingTimer = 0;
						}

						if (enemies[i].shape.getPosition().y <= 0 - enemies[i].shape.getGlobalBounds().width)
						{
							enemies.erase(enemies.begin() + i);
							break;
						}

						if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
						{
							enemydestroySound.play();
							enemies.erase(enemies.begin() + i);
							player.HP--;
							break;
						}
		
					}

					if (enemySpawnTimer < 70)
						enemySpawnTimer++;

					if (enemySpawnTimer >= 70)
					{
						enemies.push_back(Enemy(&enemyTex, window.getSize()));
						enemySpawnTimer = 0;
					}

					
					scoreText.setString("Score: " + std::to_string(score));
					background.update(5);
				}



				window.draw(player.shape);
				background.render();
				for (size_t i = 0; i < player.bullets.size(); i++)
				{
					player.bullets[i].shape.setColor(sf::Color::Green);
					window.draw(player.bullets[i].shape);
				}
				for (size_t i = 0; i < enemies.size(); i++)
				{
					for (size_t j = 0; j < enemies[i].enemybullets.size(); j++)
					{
						window.draw(enemies[i].enemybullets[j].shape);
					}
				}
				for (size_t i = 0; i < enemies.size(); i++)
				{
					ehpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
					ehpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - ehpText.getGlobalBounds().height);
					window.draw(ehpText);
					window.draw(enemies[i].shape);
				}
			
				window.draw(scoreText);
				window.draw(hpText);
				if (player.HP <= 0)
				{
					background.update(0);
					window.draw(gameOverText);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						resetGame(player, enemies, shoottimer, enemySpawnTimer, score);
						background.update(5);
					}
					
				}	

			}
		}
		window.display();
		
	}
	return 0;
}

