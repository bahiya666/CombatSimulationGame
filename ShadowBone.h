#ifndef SHADOWBONE_H
#define SHADOWBONE_H

#include <string>
#include "Sword.h"

class Sword;

class ShadowBone : public Sword
{
    private:
        double magicMultiplier;
    
    public:
        ShadowBone (std::string name, double attack, double magicMultiplier); //constructor
        ShadowBone (const ShadowBone& shadowBone);
        double damage (int playerStrength);
        std::string printSword();

};

#endif