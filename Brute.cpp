#include "Brute.h"
#include <sstream>

Brute::Brute( std::string name, double health, double strength): Soldier(name, health, strength), rageMeter(0.0) 
{}

std::string Brute::printSoldier() 
{
    std::string soldierInfo = Soldier::printSoldier();

    std::stringstream ss;
    ss << "Rage meter : " << rageMeter << "\n";

    soldierInfo += ss.str();
    
    return soldierInfo;

}

Brute& Brute::operator=(const Brute& brute) {
    if (this != &brute) 
    {
        Soldier::operator=(brute);
        rageMeter = brute.rageMeter;
    }
    return *this;
}

bool Brute::attack(Mage* mage) 
{
     if (mage == NULL) 
    {
        return false;
    }

    if (!mage->isAlive()) 
    {
        return false;
    }

    if (sword == NULL) 
    {
        return false;
    }

    double attackStrength = strength;
    if (rageMeter >= 10.0) 
    {
        attackStrength = strength * 2.0 + strength * (rageMeter - 10.0) * 0.1;
    }

    double damageDealt = sword->damage(static_cast<int>(attackStrength));

    bool opponentKilled = mage->takeDamage(damageDealt);

    if (opponentKilled) 
    {
        rageMeter = 0.0; // Reset rage meter if the opponent is killed
    }
    else 
    {
        rageMeter += 1.0; // Increase rage meter if the attack didn't kill the opponent
    }

    return opponentKilled;
}


bool Brute::attack(Ninja* ninja) 
{
     if (ninja == NULL) 
    {
        return false;
    }

    if (!ninja->isAlive()) 
    {
        return false;
    }

    if (sword == NULL) 
    {
        return false;
    }

    double attackStrength = strength;
    if (rageMeter >= 10.0) 
    {
        attackStrength = strength * 2.0 + strength * (rageMeter - 10.0) * 0.1;
    }

    double damageDealt = sword->damage(static_cast<int>(attackStrength));

    bool killed = ninja->takeDamage(damageDealt);

    if (killed) 
    {
        rageMeter = 0.0; // Reset rage meter if the opponent is killed
    }
    else 
    {
        rageMeter += 1.0; // Increase rage meter if the attack didn't kill the opponent
    }

    return killed;
}


bool Brute::attack(Brute* brute) 
{
    if (brute==NULL || !brute->isAlive() || (!sword && rageMeter <10.0))
    {
        return false; 
    }

    double attackStrength = strength;
    if (rageMeter >= 10.0) 
    {
        attackStrength = strength * 2.0 + strength * (rageMeter - 10.0) * 0.1;
        attackStrength /= 2.0;
    }

    double damageDealt = sword->damage(static_cast<int>(attackStrength));

    bool killed = brute->takeDamage(damageDealt);

    if (killed) 
    {
        rageMeter = 0.0; // Reset rage meter if the opponent is killed
    }
    else 
    {
        rageMeter += 1.0; // Increase rage meter if the attack didn't kill the opponent
    }

    return killed;
}

    
   