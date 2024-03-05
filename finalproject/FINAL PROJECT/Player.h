#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class Bullet;

class Player
{
public:
    
    sf::Sprite shape;
    sf::Texture* texture;
    int HP;
    int HPMax;

    std::vector<Bullet> bullets;

    Player(sf::Texture* texture);
    ~Player();

    void reset();
    

};
