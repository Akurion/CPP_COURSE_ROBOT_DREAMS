#include "ItemDeck.h"
#include <fstream>
#include <sstream>
#include <iostream>



ItemDeck::ItemDeck()
{
    
}

ItemDeck::~ItemDeck()
{
   
}
void ItemDeck::loadDatabaseFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::cout << "File opened successfully." << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string itemType;
        std::string itemName;
        int params;

        if (std::getline(iss, itemType, ';') &&
            std::getline(iss, itemName, ';') &&
            (iss >> params)) {
            if (itemType == "Weapon") {
                m_database.push_back(new Weapon{ itemName, params });
            }
            else if (itemType == "UndeadWeapon") {
                m_database.push_back(new UndeadWeapon{ itemName, params });
            }
            else if (itemType == "ZombieWeapon") {
                m_database.push_back(new ZombieWeapon{ itemName, params });
            }
            
        }
    }

    file.close();
}

std::vector<Item*> ItemDeck::generateItems(int numberOfItems) const
{
    return generateItemsFromDatabase(numberOfItems, m_database);
}
