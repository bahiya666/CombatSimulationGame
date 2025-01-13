#include "Ninja.h"

Ninja :: Ninja (std:: string name , double health, double strength) : Soldier( name , health, strength) , moveCount (0)
{}

bool Ninja :: takeDamage (double damage)
{
    ++moveCount;

    if (moveCount % 3 == 0) 
    {
        moveCount = 0; // Reset moveCount
        return false; // No damage taken
    }

    return Soldier::takeDamage(damage);
}

Ninja& Ninja :: operator=(const Ninja& ninja)
{
    if (this != &ninja) 
    {
        Soldier::operator=(ninja);
        moveCount = ninja.moveCount;
    }
    return *this;

}
bool Ninja::isAlive() const 
{
    return Soldier::isAlive();
}


bool Ninja::attack(Brute* brute) {
    if (brute == NULL || !brute->isAlive() || sword == NULL) 
    {
        return false; 
    }

    double dd = sword->damage(static_cast<int>(strength));

    if (brute->takeDamage(dd)) 
    {
        return true; 
    }

    return false;
}


bool Ninja::attack(Ninja* ninja) {
    if (ninja == NULL || !ninja->isAlive() || sword == NULL) 
    {
        return false; 
    }

    double nn = sword->damage(static_cast<int>(strength));

    if (ninja->takeDamage(nn)) 
    {
        return true; 
    }

    return false; 
}


bool Ninja::attack(Mage* mage) 
{
    if (mage == NULL || !mage->isAlive() || sword == NULL) 
    {
        return false; 
    }
   
    double mm = sword->damage(static_cast<int>(strength));

    if (mage->takeDamage(mm)) 
    {
        return true;
    }

    return false; 
}