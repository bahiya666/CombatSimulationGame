#include "Sword.h"
#include <cmath>
#include <sstream>

Sword:: Sword (std::string name, double attack)
{
    this->name = name;
    this->attack = attack;
    this->xp = 0.0;
    this->level = 1;
}

int Sword :: getXPForNextLevel ()
{
    return static_cast<int>(std::pow (std::log(2*(this->level+1)),3));
}

void Sword :: addXP (double damage)
{
    this->xp += (0.1*damage);

    if (this->xp > getXPForNextLevel())
    {
        this->level++;
        this->xp = 0.0;
    }
}

double Sword :: damage (int playerStrength)
{
    double damageOFsword = this->attack + (this->attack *(playerStrength*0.1+this->level*0.2));
    addXP (damageOFsword);
    return damageOFsword;
}

std::string Sword :: printSword()
{
    std::stringstream ss;
    ss << "Sword: " << this->name << "\n";
    ss << "Attack: " << this->attack << "\n";
    ss << "Level: " << this->level << "\n";
    ss << "XP: " << this->xp << "\n";
    return ss.str();
}

Sword :: Sword (const Sword& sword)
{
    this->name = sword.name;
    this->level = sword.level;
    this->xp = sword.xp;
    this->attack = sword.attack;
}

