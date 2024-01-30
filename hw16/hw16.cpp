#include <iostream>
#include <vector>
#include <string>
#include "Rectangle.h"

enum PlayerClass {
    ASSAULT,
    SUPPORT,
    SNIPER,
    MEDIC
};

class Weapon {
public:
    std::string name;
    int damage;
    int range;

    Weapon(std::string n, int d, int r) : name(n), damage(d), range(r) {}
};

class Player {
public:
    std::string name;
    float health;
    PlayerClass playerClass;
    Weapon* weapon;

    Player() : name(""), health(100.0), playerClass(ASSAULT), weapon(nullptr) {}

    Player(std::string n, float h, PlayerClass pc) : name(n), health(h), playerClass(pc), weapon(nullptr) {}

    void setWeapon(Weapon* w) {
        weapon = w;
    }

    Weapon* getWeapon() const {
        return weapon;
    }

    void printPlayerInfo() const {
        std::cout << "Name: " << name << ", Health: " << health << ", Class: " << getPlayerClassName() << std::endl;
        if (weapon != nullptr) {
            std::cout << "Weapon: " << weapon->name << ", Damage: " << weapon->damage << ", Range: " << weapon->range << std::endl;
        }
    }

private:
    std::string getPlayerClassName() const {
        switch (playerClass) {
        case ASSAULT: return "Assault";
        case SUPPORT: return "Support";
        case SNIPER: return "Sniper";
        case MEDIC: return "Medic";
        default: return "Unknown";
        }
    }
};

class Team {
public:
    std::string teamName;
    std::vector<Player*> players;

    Team(std::string name) : teamName(name) {}

    bool addPlayer(Player* p) {
        if (players.size() < MAX_PLAYERS) {
            players.push_back(p);
            return true;
        }
        return false;
    }

    bool removePlayer(Player* p) {
        auto it = std::find(players.begin(), players.end(), p);
        if (it != players.end()) {
            players.erase(it);
            return true;
        }
        return false;
    }

    void printTeamInfo() const {
        std::cout << "Team: " << teamName << ", Players: " << players.size() << std::endl;
        for (const auto& player : players) {
            player->printPlayerInfo();
            std::cout << std::endl;
        }
    }

private:
    static const int MAX_PLAYERS = 10; 
};

int main() {

    Weapon* ak47 = new Weapon("AK-47", 30, 300);
    Weapon* sniperRifle = new Weapon("AWP", 100, 1000);

    Player* player1 = new Player("John", 100, ASSAULT);
    player1->setWeapon(ak47);

    Player* player2 = new Player("Alice", 90, SNIPER);
    player2->setWeapon(sniperRifle);

    Team* teamA = new Team("Team A");
    teamA->addPlayer(player1);
    teamA->addPlayer(player2);

    teamA->printTeamInfo();

    delete ak47;
    delete sniperRifle;
    delete player1;
    delete player2;
    delete teamA;

    Rectangle rectangle1;
    Rectangle rectangle2(3.0f, 4.0f);


    std::cout << "Rectangle 1 - area: " << rectangle1.getArea() << " . Rectangle 1 - perimeter: " << rectangle1.getPerimeter() << std::endl;
    std::cout << "Rectangle 2 - area: " << rectangle2.getArea() << " . Rectangle 2 - perimeter: " << rectangle2.getPerimeter() << std::endl;
    return true;

    return 0;
}
