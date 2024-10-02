
#include "HealthBooster.h"

HealthBooster::HealthBooster() {
}

void HealthBooster::applyBoost(Player& player) {
    if ((player.HP + 1 ) > 10)
        player.HP = 10;
    else
        player.HP += 1;
}
