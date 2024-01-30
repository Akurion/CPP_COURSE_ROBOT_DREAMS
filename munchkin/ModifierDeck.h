#pragma once
#include "DeckBase.h"
#include "Modifier.h"

class ModifierDeck : public DeckBase<Modifier>
{
public:
    ModifierDeck();
    ~ModifierDeck();

    std::vector<Modifier*> generateModifiers(int numberOfModifiers);
};
