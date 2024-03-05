#include "FireRateBooster.h"

FireRateBooster::FireRateBooster() {
}

void FireRateBooster::applyBoost(Player& player, int& shoottimer) {
    shoottimer = 10;
    boostDuration = 300;
}

bool FireRateBooster::isBoostActive() const {
    return boostDuration > 0;
}

void FireRateBooster::update() {
    if (isBoostActive()) {
        boostDuration--;
    }
}
