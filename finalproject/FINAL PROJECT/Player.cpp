#include "Player.h"
#include "Bullet.h"
#include "ResourcesManager.h"
Player::Player(sf::Texture* texture)
{
    this->HPMax = 10;
    this->HP = this->HPMax;
    this->texture = texture;
    this->shape.setTexture(*texture);
    this->shape.setPosition(600.f, 800.f);

}

Player::~Player()
{
}


