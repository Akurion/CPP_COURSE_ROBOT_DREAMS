#include "ModifierDeck.h"
#include <ctime>

ModifierDeck::ModifierDeck()
{
    m_database =
    {
        new SimpleModifier{3},
        new SimpleModifier{3},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{2},
        new SimpleModifier{4},
        new SimpleModifier{1},
        new SimpleModifier{1},
        new SimpleModifier{1},
        new DoubleMunchkinLevel{},
        new DoubleMunchkinLevel{}
    };
}

ModifierDeck::~ModifierDeck()
{
}

std::vector<Modifier*> ModifierDeck::generateModifiers(int numberOfModifiers)
{
    return generateItemsFromDatabase(numberOfModifiers, m_database);
}