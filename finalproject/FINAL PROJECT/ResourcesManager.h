#pragma once
#include "SFML\Graphics.hpp"
#include <unordered_map>
#include "SFML/Audio.hpp"

class ResourcesManager
{
public:
    static sf::Font font;
    static sf::Texture playerTex;
    static sf::Texture enemyTex;
    static sf::Texture bulletTex;

    static sf::Text scoreText;
    static sf::Text gameOverText;
    static sf::Text hpText;
    static sf::Text ehpText;
    static sf::SoundBuffer& getSoundBuffer(const std::string& filename);
    static sf::Sound& getSound(const std::string& filename);

    static sf::Text fireboosterText;

    static void loadResources();
private:
    static std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    static std::unordered_map<std::string, sf::Sound> sounds;
};
