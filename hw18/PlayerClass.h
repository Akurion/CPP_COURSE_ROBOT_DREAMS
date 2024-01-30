#pragma once

class PlayerClass
{
public:
    virtual float getDamageMultiplier() const = 0;
    virtual float getArmorMultiplier() const = 0;
    virtual float getMissChance() const = 0;

    virtual ~PlayerClass() {}
};

class DefaultClass : public PlayerClass
{
public:
    float getDamageMultiplier() const override { return 1.0f; }
    float getArmorMultiplier() const override { return 1.0f; }
    float getMissChance() const override { return 0.0f; }
};

class DefenderClass : public DefaultClass
{
public:
    float getArmorMultiplier() const override { return 1.2f; }
    float getMissChance() const override { return 0.1f; }
};

class AttackerClass : public DefaultClass
{
public:
    float getDamageMultiplier() const override { return 1.1f; }
    float getArmorMultiplier() const override { return 0.9f; }
};

class LuckyManClass : public DefaultClass
{
public:
    float getMissChance() const override { return 0.3f; }
};

class BerserkClass : public AttackerClass, public LuckyManClass
{
    float getArmorMultiplier() const override { return 0.7f; }
};
