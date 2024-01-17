#include "Player.h"
#include "PlayerClass.h"
#include "Weapon.h"
#include <iostream>

Player::~Player()
{
    delete m_class;
    delete m_weapon;
}

void Player::setWeapon(Weapon* weapon)
{
    delete m_weapon;
    m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
    delete m_class;
    m_class = playerClass;
}

void Player::attack(const Player& other, int distance)
{
    if (&other == this)
    {
        std::cout << "\n-------FRIENDLY FIRE!-------\n";
    }

    if (other.isEliminated())
    {
        std::cout << "Player " << other.getName() << " has been already eliminated!\n";
        return;
    }

    const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());
    m_health -= damage;

    std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
        " with weapon " << typeid(*m_weapon).name() << " with damage " << damage << std::endl;

    std::cout << "Health left: " << m_health << std::endl;

    if (m_health <= 0)
    {
        m_health = 0;
        std::cout << "Player " << other.getName() << " was eliminated!\n";
    }
}

int main()
{
    
    Player player1("Player1", new SniperRifle, new DefenderClass);
    Player player2("Player2", new Pistol, new AttackerClass);
    Player player3("Player3", new Axe, new LuckyManClass);

    
    std::cout << "Initial Player Information:\n";
    std::cout << "Player1: Health=" << player1.getHealth() << ", Class=" << typeid(*player1.getPlayerClass()).name() << ", Weapon=" << typeid(*player1.getWeapon()).name() << "\n";
    std::cout << "Player2: Health=" << player2.getHealth() << ", Class=" << typeid(*player2.getPlayerClass()).name() << ", Weapon=" << typeid(*player2.getWeapon()).name() << "\n";
    std::cout << "Player3: Health=" << player3.getHealth() << ", Class=" << typeid(*player3.getPlayerClass()).name() << ", Weapon=" << typeid(*player3.getWeapon()).name() << "\n\n";

    
    std::cout << "Attacking...\n";
    player1.attack(player2, 500);
    player2.attack(player3, 2);
    player3.attack(player1, 10);

    
    std::cout << "\nFinal Player Information:\n";
    std::cout << "Player1: Health=" << player1.getHealth() << "\n";
    std::cout << "Player2: Health=" << player2.getHealth() << "\n";
    std::cout << "Player3: Health=" << player3.getHealth() << "\n";

    return 0;
}