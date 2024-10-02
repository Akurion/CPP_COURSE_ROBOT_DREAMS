#pragma once
#include "SFML\Graphics.hpp"
#include "Bullet.h"

class Enemy
{
public:
    sf::Sprite shape;
    int HP;
    int HPMax;

    std::vector<Bullet> enemybullets;
    int enemyShootingTimer;

    Enemy(sf::Texture* texture, sf::Vector2u windowSize);
    ~Enemy();
    void updateShooting();
};
