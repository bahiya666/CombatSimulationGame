#include <string>
#include <sstream>
#include "Mage.h"

Mage :: Mage (std::string name, double health, double strength) : Soldier (name, health, strength), shadowBone (NULL)
{}

void Mage :: armShadow(ShadowBone* shadowBone) // !!!!!!!!!!!!
{
    if (this->shadowBone != shadowBone) 
    {
        if (this->shadowBone != NULL) 
        {
            delete this->shadowBone;
            this->shadowBone =NULL;
        }

        if (shadowBone != NULL) 
        {
            this->shadowBone = new ShadowBone(*shadowBone);
        } 
    }
    
}

Mage& Mage :: operator=(const Mage& mage ) //!!!!!!!!!!1111
{
    if (this != &mage) 
    {   
        static_cast<Soldier&>(*this) = mage;

        // Delete the old shadowBone if it exists
        if (this->shadowBone != NULL)
        {
            delete this->shadowBone;
            this->shadowBone = NULL;
        }

        // Check if mage has a shadowBone
        if (mage.shadowBone != NULL)
        {
            // Create a deep copy of mage's shadowBone
            this->shadowBone = new ShadowBone(*mage.shadowBone);
        }
    }

    return *this;
}



std::string Mage :: printSoldier()
{
    std::stringstream s;
    s<< Soldier::printSoldier();

    if (shadowBone != NULL)
    {
        s << shadowBone-> printSword();
    }

    return s.str();
}
    
bool Mage :: attack (Brute* brute) //!!!!!!!!!!!!!!!111
{
    if (brute == NULL || !brute->isAlive() || sword == NULL) 
    {
        return false; 
    }

    if (shadowBone) 
    {
        double d = shadowBone-> damage((static_cast<int>(strength)));
        if (brute-> takeDamage(d)) 
        {
            return true;
        }
    }
    
    double d = sword->damage ((static_cast<int>(strength)));

    if (brute->takeDamage(d))
    {
        return true;
    }
    return false;
}

bool Mage :: attack (Ninja* ninja)
{
    if (ninja == NULL || !ninja->isAlive() || sword == NULL) 
    {
        return false; 
    }

    if (shadowBone)
    {
        double n = shadowBone-> damage(static_cast<int>(strength));
        if (ninja->takeDamage(n))
        {
            return true;
        }
    }

    double n = sword->damage(static_cast<int>(strength));

    if (ninja->takeDamage(n))
    {
        return true;
    }
    
    return false;
}

bool Mage :: attack (Mage* mage )
{
    if (mage == NULL || !mage->isAlive() || sword == NULL) 
    {
        return false; 
    }

    double m = sword->damage (static_cast<int>(strength));

    if (mage->takeDamage(m))
    {
         return true;
    }

    return false;
}
