#include "ShadowBone.h"
#include <sstream>
#include <string>

ShadowBone :: ShadowBone(std::string name ,double attack, double magicMultiplier) : Sword (name,attack)
{
    this-> magicMultiplier = magicMultiplier;
}

ShadowBone :: ShadowBone (const ShadowBone& shadowBone) : Sword(shadowBone)
{
    this->magicMultiplier= shadowBone.magicMultiplier;
}

double ShadowBone :: damage (int playerStrength)
{
    return ( attack + (attack*((playerStrength*0.1+level*0.2)+magicMultiplier)) );
}

std::string ShadowBone :: printSword()
{
    std::stringstream s;
    s<< Sword::printSword();
    s << "Magic Multiplier: " << magicMultiplier << "\n";
    return s.str(); 
}
