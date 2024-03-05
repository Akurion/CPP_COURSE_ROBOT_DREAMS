#include "Background.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Star::Star(float x, float y, bool isBright)
    : position(x, y), isBright(isBright) {}

void Star::update(float speed) {
    position.y += speed;
}

const sf::Vector2f& Star::getPosition() const {
    return position;
}

InfiniteBackground::InfiniteBackground(sf::RenderWindow& window, int starLimit)
    : window(window), starLimit(starLimit) {

    if (!starTexture.loadFromFile("star_A.png")) {
        std::cout << "Failed to load star_A.png" << std::endl;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void InfiniteBackground::update(float speed) {
    for (auto& star : stars) {
        star.update(speed);
    }

    stars.erase(std::remove_if(stars.begin(), stars.end(),
        [this](const Star& star) {
            return star.getPosition().y > window.getSize().y;
        }), stars.end());

    if (stars.size() < starLimit) {
        float x = static_cast<float>(std::rand() % window.getSize().x);
        float y = -static_cast<float>(std::rand() % window.getSize().y);
        bool isBright = std::rand() % 2 == 0;
        stars.emplace_back(x, y, isBright);
    }
}

void InfiniteBackground::render() {
    for (const auto& star : stars) {
        sf::Sprite starSprite(starTexture);
        starSprite.setPosition(star.getPosition());


        sf::Color starColor = starSprite.getColor();
        starColor.a = star.isBright ? 96 : 34;
        starSprite.setColor(starColor);

        window.draw(starSprite);
    }
}
