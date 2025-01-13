#ifndef SWORD_H
#define SWORD_H


#include <string>


class ShadowBone;
class Sword
{
    private:
        std::string name;
    
    protected:
        int level;
        double xp;
        double attack;

    public:
        Sword (std::string name, double attack); //constructor 
        int getXPForNextLevel();
        void addXP(double damage);
        double damage (int playerStrength);
        std::string printSword();
        Sword(const Sword& sword); // copy constructor 
        friend class ShadowBone;

};

#endif
