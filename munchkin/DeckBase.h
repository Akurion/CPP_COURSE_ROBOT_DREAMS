#pragma once
#include <vector>
#include <ctime>

template<typename T>
class DeckBase
{
public:
    DeckBase() = default;
    virtual ~DeckBase()
    {
        for (T* item : m_database)
        {
            delete item;
        }
        m_database.clear();
    }

    virtual std::vector<T*> generateItemsFromDatabase(int numberOfItems, const std::vector<T*>& database) const
    {
        std::vector<T*> selectedItems;

        if (numberOfItems <= 0 || database.empty()) {
            return selectedItems;
        }

        std::srand(std::time(0));

        std::vector<T*> itemsCopy = database;

        numberOfItems = std::min(numberOfItems, static_cast<int>(itemsCopy.size()));

        for (int i = 0; i < numberOfItems; ++i) {
            int randomIndex = std::rand() % itemsCopy.size();

            selectedItems.push_back(itemsCopy[randomIndex]);

            itemsCopy.erase(itemsCopy.begin() + randomIndex);
        }

        return selectedItems;
    }

protected:
    std::vector<T*> m_database;
};
