#pragma once

#include <SFML/Graphics.hpp>

enum GameState {
    MENU,
    GAME,
    GAMEOVER,
    SETTINGS
};

class Menu {
public:
    Menu(sf::RenderWindow& window);

    void handleInput();
    void update();
    void render();

    int getSelectedOption() const;
    bool isEnterPressed() const;
    bool isVisible() const;
    GameState getGameState() const;

    void show();
    void hide();
    void setGameState(GameState state);

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text menuOptions[3];
    int selectedOption;
    bool enterPressed;
    bool visible;
    GameState gameState;
};