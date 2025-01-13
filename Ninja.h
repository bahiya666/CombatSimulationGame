#ifndef NINJA_H
#define NINJA_H

#include <string>
#include "Soldier.h"
#include "Brute.h"
#include "Mage.h"
#include "Sword.h"


class Brute;
class Mage;

class Ninja : private Soldier
{
    private:  
        int moveCount;

    public:
        Ninja (std::string name, double health, double strength);
        bool takeDamage(double damage);
        Ninja& operator= (const Ninja& ninja);
        bool isAlive() const;
        bool attack (Brute* brute);
        bool attack (Ninja* ninja);
        bool attack (Mage* mage);
        void arm (Sword* sword);
};

#endif
