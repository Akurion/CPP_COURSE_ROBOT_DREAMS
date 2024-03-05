#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Star {
public:
    Star(float x, float y, bool isBright);

    void update(float speed);
    const sf::Vector2f& getPosition() const;
    bool isBright;

private:
    sf::Vector2f position;

};

class InfiniteBackground {
public:
    InfiniteBackground(sf::RenderWindow& window, int starLimit);

    void update(float speed);
    void render();

private:
    sf::RenderWindow& window;
    sf::Texture starTexture;
    std::vector<Star> stars;
    int starLimit;
};
