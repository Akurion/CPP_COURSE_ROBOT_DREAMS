#pragma once

#include "Player.h"

class FireRateBooster {
public:
    FireRateBooster();

    void applyBoost(Player& player, int& shoottimer);
    bool isBoostActive() const;
    void update();
    int boostDuration = 0;

private:
};
