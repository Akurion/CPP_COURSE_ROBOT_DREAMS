#pragma once

class Weapon
{
public:
    virtual int getDamageRate(int distance) const = 0;
    virtual int getEffectiveRange() const = 0;
    virtual int getDamageLevel() const = 0;
};

class RangedWeapon : public Weapon
{
public:
    int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * getDamageMultiplier()); }
    int getEffectiveRange() const override { return effectiveRange; }
    int getDamageLevel() const override { return damageLevel; }

protected:
    virtual float getPrecision(int distance) const { return 1.0f; }
    virtual float getDamageMultiplier() const { return 1.0f; }

private:
    int effectiveRange;
    int damageLevel;
};

class SniperRifle : public RangedWeapon
{
public:
    SniperRifle() : effectiveRange(2000), damageLevel(3) {}

protected:
    float getPrecision(int distance) const override;
};

class Pistol : public RangedWeapon
{
public:
    Pistol() : effectiveRange(300), damageLevel(1) {}

protected:
    float getPrecision(int distance) const override { return 2.0f; }
    float getDamageMultiplier() const override { return 0.8f; }

private:
    int effectiveRange;
    int damageLevel;
};

class AssaultRifle : public RangedWeapon
{
public:
    AssaultRifle() : effectiveRange(1000), damageLevel(2) {}

protected:
    float getPrecision(int distance) const override { return 1.0f; }
    float getDamageMultiplier() const override { return 1.2f; }

private:
    int effectiveRange;
    int damageLevel;
};

class MeleeWeapon : public Weapon
{
public:
    int getDamageRate(int distance) const override { return 10; }
    int getEffectiveRange() const override { return 1; }
    int getDamageLevel() const override { return 1; }
};

class BareHand : public MeleeWeapon
{
public:
    BareHand() : effectiveRange(1), damageLevel(1) {}

    int getDamageRate(int distance) const override
    {
        return 5; 
    }

    int getEffectiveRange() const override { return effectiveRange; }
    int getDamageLevel() const override { return damageLevel; }

private:
    int effectiveRange;
    int damageLevel;
};

class Axe : public MeleeWeapon
{
public:
    Axe() : effectiveRange(2), damageLevel(2) {}

    int getDamageRate(int distance) const override
    {
        return 15; 
    }

    int getEffectiveRange() const override { return effectiveRange; }
    int getDamageLevel() const override { return damageLevel; }

private:
    int effectiveRange;
    int damageLevel;
};