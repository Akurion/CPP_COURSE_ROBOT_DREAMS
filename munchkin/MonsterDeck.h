#pragma once
#include "DeckBase.h"
#include "Monster.h"

class MonsterDeck : public DeckBase<Monster>
{
public:
    MonsterDeck();
    ~MonsterDeck();

    Monster* generateMonster();
};
