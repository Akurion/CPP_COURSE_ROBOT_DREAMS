#include "Runaway.h"
#include "Munchkin.h"
#include "Modifier.h"
#include "Monster.h"
#include "Item.h"
#include <iostream>

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(-m_levelToDowngrade);
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
	{
		Runaway_LevelDowngrade::apply(munchkin);
	}
} 

void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin)
{
	const std::vector<Modifier*>& modifiers = munchkin->getModifiers();

	if (!modifiers.empty())
	{
		int randomIndex = rand() % modifiers.size();
		Modifier* removedModifier = munchkin->popModifier(randomIndex);
		std::cout << "Removed modifier from hand: " << removedModifier->getFullInfo() << std::endl;
		delete removedModifier;
	}
}

std::string Monster::getFullInfo() const
{
	std::string info = "Monster " + getName() + ", level " + std::to_string(getLevel());

	if (m_RunawayPolicy != nullptr) {
		info += ". " + m_RunawayPolicy->getFullInfo();
	}

	return info;
}
void Runaway_ItemEquipedRemoval::apply(Munchkin* munchkin)
{
	const std::vector<Item*>& items = munchkin->getItems();

	if (!items.empty()) {
		auto maxPowerItemIt = std::max_element(items.begin(), items.end(),
			[](const Item* item1, const Item* item2) {
				return item1->getBasePower() < item2->getBasePower();
			});

		if (maxPowerItemIt != items.end()) {
			int index = static_cast<int>(std::distance(items.begin(), maxPowerItemIt));



			munchkin->popItem(index);

		}
	}
}