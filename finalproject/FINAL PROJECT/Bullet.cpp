#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2f pos)
{
    this->shape.setTexture(*texture);
    this->shape.setPosition(pos);
}

Bullet::~Bullet()
{
}
