#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"
#include <iostream>

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
        m_level += levels;
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
}

void Munchkin::setItems(const std::vector<Item*>& items)
{
    m_items = items;
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}
void Munchkin::popItem(int idx)
{
    if (idx >= 0 && idx < m_items.size())
    {
        delete m_items[idx];
        m_items.erase(m_items.begin() + idx);
    }
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];

    //Erase-remove idiom can be used as we don't really care about
    //internal order of the elements
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;

}



