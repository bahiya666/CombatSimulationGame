#include <string>
#include <sstream>
#include "Soldier.h"

int Soldier::aliveSoldiers = 0;
int Soldier::deadSoldiers = 0;

Soldier :: Soldier (std::string name, double health, double strength)
{
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->sword = NULL;
    this->aliveSoldiers++;
}

Soldier ::~Soldier()
{
    if ( sword != NULL)
    {
        delete sword;
        sword = NULL;
    }
}

std::string Soldier :: printSoldier()
{
    std::stringstream s;
    s << "Name: " << name << "\n";
    s << "Health: " << health << "\n";
    s << "Strength: " << strength << "\n";
    if (sword != NULL) 
    {
        s << sword->printSword();
    }
    return s.str();
}

void Soldier :: arm (Sword* sword) //!!!!!!!!!!!!!!!!
{
    if (sword ==sword)
    {
        return; // Do nothing if it's the same sword
    }

    if (sword != NULL)
    {
        delete sword;
    }

    sword = sword;
}

bool Soldier :: takeDamage(double damage)
{
    if (damage < 0)
    {
        return false;
    }

    if (health<=0)
    {
        return false;
    }

    health-=damage;

    if (health < 0)
    {
        health = 0;
    }

    if (health == 0)
    {
        aliveSoldiers--;
        deadSoldiers++;
        return true;
    }
     
     return false;
    
}

bool Soldier ::isAlive() const
{
    if (health > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Soldier& Soldier :: operator=(const Soldier& soldier)
{
    if (this == &soldier)
    {
        return *this;
    }
    
    this->name = soldier.name;
    this->health = soldier.health;
    this->strength = soldier.strength;

    if (this->sword !=NULL)
    {
        delete this->sword;
    }
        
    if (soldier.sword != NULL)
    {
        this->sword = new Sword(*soldier.sword);
    }
    else 
    {
        this->sword = NULL;
    }
    
    return *this;
}