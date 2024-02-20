#include "MonsterDeck.h"
#include "Runaway.h"
#include "Monster.h"

MonsterDeck::MonsterDeck()
{
    m_database =
    {
        new Monster{"Crazy Joe", 4, Tribe::Human, new Runaway_LevelDowngradeIf{2, 3}},
        new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},
        new Monster{"Vampire", 5, Tribe::Undead, new Runaway_LevelDowngrade{1}},
        new Monster{"ZombiePasha", 12, Tribe::Zombie, new Runaway_LevelDowngradeIf{2, 3}}, 
        new Monster{"Babue", 4, Tribe::Human, new Runaway_ItemEquipedRemoval},
        new Monster{"Abalaba", 30, Tribe::God, new Runaway_ModifierFromHandRemoval}
    };
}

MonsterDeck::~MonsterDeck()
{
}
Monster* MonsterDeck::generateMonster()
{
    return generateItemsFromDatabase(1, m_database).front();
}