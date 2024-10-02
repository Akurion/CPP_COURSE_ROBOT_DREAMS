#include "Enemy.h"
#include "ResourcesManager.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2u windowSize)
{
    this->HPMax = rand() % 3 + 1;
    this->HP = HPMax;

    this->shape.setTexture(ResourcesManager::enemyTex);
    this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), 0);
    enemyShootingTimer = 0;
}
Enemy::~Enemy()
{
}

void Enemy::updateShooting()
{
    if (enemyShootingTimer < 30)
        enemyShootingTimer++;
}