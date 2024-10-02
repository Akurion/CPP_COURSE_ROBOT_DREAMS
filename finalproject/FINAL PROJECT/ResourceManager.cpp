#include "ResourcesManager.h"
#include "Player.h"

#include "Enemy.h"

sf::Font ResourcesManager::font;
sf::Texture ResourcesManager::playerTex;
sf::Texture ResourcesManager::enemyTex;
sf::Texture ResourcesManager::bulletTex;
sf::Text ResourcesManager::scoreText;
sf::Text ResourcesManager::gameOverText;
sf::Text ResourcesManager::hpText;
sf::Text ResourcesManager::ehpText;
std::unordered_map<std::string, sf::SoundBuffer> ResourcesManager::soundBuffers;
std::unordered_map<std::string, sf::Sound> ResourcesManager::sounds;
sf::Text ResourcesManager::fireboosterText;


void ResourcesManager::loadResources()
{
    font.loadFromFile("arial.ttf");
    playerTex.loadFromFile("ship_A.png");
    enemyTex.loadFromFile("enemy.png");
    bulletTex.loadFromFile("bullet.png");

    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, 10.f);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(600.f, 400.f);
    gameOverText.setString("GAME OVER!");

    hpText.setFont(font);
    hpText.setCharacterSize(12);
    hpText.setFillColor(sf::Color::White);

    ehpText.setFont(font);
    ehpText.setCharacterSize(12);
    ehpText.setFillColor(sf::Color::Red);


    fireboosterText.setFont(font);
    fireboosterText.setCharacterSize(20);
    fireboosterText.setFillColor(sf::Color::White);
    fireboosterText.setPosition(1000.f, 10.f);
    fireboosterText.setString("FireRate increased!");

}
sf::SoundBuffer& ResourcesManager::getSoundBuffer(const std::string& filename) {
    if (soundBuffers.find(filename) == soundBuffers.end()) {
        soundBuffers[filename].loadFromFile(filename);
    }
    return soundBuffers[filename];
}

sf::Sound& ResourcesManager::getSound(const std::string& filename) {
    if (sounds.find(filename) == sounds.end()) {
        sounds[filename].setBuffer(getSoundBuffer(filename));
    }
    return sounds[filename];
}