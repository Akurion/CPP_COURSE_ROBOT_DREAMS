#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) : window(window), selectedOption(0), enterPressed(false), visible(true), gameState(MENU) {
    if (!font.loadFromFile("arial.ttf")) {

    }

    for (int i = 0; i < 3; ++i) {
        menuOptions[i].setFont(font);
        menuOptions[i].setCharacterSize(24);
        menuOptions[i].setFillColor(sf::Color::White);
        menuOptions[i].setPosition(500, 380 + i * 50);
    }

    menuOptions[0].setString("1) Start Game");
    menuOptions[1].setString("2) Game Settings");
    menuOptions[2].setString("3) Exit");

}

sf::RenderWindow settingsWindow(sf::VideoMode(1280, 960), "Settings");
bool settingsChanged = false;

void Menu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (visible) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedOption = (selectedOption - 1 + 3) % 3;
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    selectedOption = (selectedOption + 1) % 3;
                }
                else if (event.key.code == sf::Keyboard::Return && !enterPressed) {
                    enterPressed = true;
                }
            }

            if (event.key.code == sf::Keyboard::Escape) {
                if (gameState == GAME || gameState == SETTINGS) {
                    gameState = MENU;
                    visible = !visible;
                }
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Return) {
                enterPressed = false;
            }
        }
    }
}

void Menu::update() {

}

void Menu::render() {
    if (visible) {
        for (int i = 0; i < 3; ++i) {
            if (i == selectedOption) {
                menuOptions[i].setFillColor(sf::Color::Red);
            }
            else {
                menuOptions[i].setFillColor(sf::Color::White);
            }

            window.draw(menuOptions[i]);
        }
    }
}

int Menu::getSelectedOption() const {
    return selectedOption + 1;
}

bool Menu::isEnterPressed() const {
    return enterPressed;
}

bool Menu::isVisible() const {
    return visible;
}

GameState Menu::getGameState() const {
    return gameState;
}

void Menu::show() {
    visible = true;
}

void Menu::hide() {
    visible = false;
}

void Menu::setGameState(GameState state) {
    gameState = state;
}
