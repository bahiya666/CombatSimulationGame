#ifndef SOLDIER_H
#define SOLDIER_H

#include <string>
#include "Sword.h"

class Sword;
class Mage;

class Soldier
{
    private:
        double health;
        std::string name;

    protected:
        double strength;
        Sword* sword;
        static int aliveSoldiers;
        static int deadSoldiers;

    public:
        Soldier (std::string name, double health, double strength );
        ~Soldier();
        std::string printSoldier();
        void arm (Sword* sword);
        bool takeDamage (double damage);
        bool isAlive() const;
        Soldier& operator=(const Soldier& soldier);




};
#endif