#pragma once
#include "DeckBase.h"
#include "Item.h"

class ItemDeck : public DeckBase<Item>
{
public:
    ItemDeck();
    ~ItemDeck();

    void loadDatabaseFromFile(const std::string& filename);
    std::vector<Item*> generateItems(int numberOfItems) const;
};
