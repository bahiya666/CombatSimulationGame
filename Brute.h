#ifndef BRUTE_H
#define BRUTE_H

#include <string>
#include "Soldier.h" // Assuming Soldier class is included here
#include "Mage.h"
#include "Ninja.h"

class Mage;
class Ninja;
class Soldier;

class Brute : public Soldier
{
    private:
        double rageMeter;
    
    public:
        Brute (std::string name, double health, double strength);
        std::string printSoldier();
        Brute& operator=(const Brute& brute);
        bool attack (Brute* brute);
        bool attack (Ninja* ninja);
        bool attack (Mage* mage);

};
#endif