#include <iostream>
#include <string>
#include <cmath>
#include "Sword.h"
#include "Mage.h"
#include "Brute.h"
#include "Ninja.h"
#include "Soldier.h"
#include "ShadowBone.h"

int main() {

    // Create a ShadowBone object
    ShadowBone* shadowBone = new ShadowBone("DarkBlade", 60.0, 2.0); // Create a dynamic ShadowBone object

    // Create a Mage and assign the ShadowBone
    Mage mage("Mysterious", 110.0, 12.0);
    mage.armShadow(shadowBone);

    // Test Mage functions
    std::cout << "Mage Information:\n" << mage.printSoldier() << "\n";

    Brute* opponent = NULL; // Create a Brute opponent or set it to an existing Brute object
    bool attackResult = mage.attack(opponent);

    if (attackResult) {
        std::cout << "Mage successfully attacked!\n";
    } else {
        std::cout << "Mage failed to attack.\n";
    }

    // Create characters and weapons
    Sword sword("Excalibur", 50.0);
    Soldier soldier("John", 100.0, 10.0);
    Brute brute("Hulk", 150.0, 20.0);
    Ninja ninja("Stealthy", 120.0, 15.0);

    // Display character and weapon information
    std::cout << "Character and Weapon Information:\n";
    std::cout << "Sword:\n" << sword.printSword() << "\n";
    std::cout << "Soldier:\n" << soldier.printSoldier() << "\n";
    std::cout << "Brute:\n" << brute.printSoldier() << "\n";

    // Brute attacks Ninja
    bool result = brute.attack(&ninja);
    std::cout << (result ? "Brute successfully attacked Ninja!\n" : "Brute failed to attack Ninja.\n");

    // Ninja attacks Mage
    result = ninja.attack(&mage);
    std::cout << (result ? "Ninja successfully attacked Mage!\n" : "Ninja failed to attack Mage.\n");

    // Check if Soldier is alive
    std::cout << "Is Soldier alive? " << (soldier.isAlive() ? "Yes" : "No") << "\n";

    // Test Mage's attack on a Brute
    attackResult = mage.attack(&brute);
    std::cout << (attackResult ? "Mage successfully attacked Brute!\n" : "Mage failed to attack Brute.\n");

    // Test ShadowBone's printSword() function
    std::cout << "ShadowBone Sword Information:\n" << shadowBone->printSword() << "\n";

    // Test Sword's XP and damage functions
    std::cout << "\nSword XP for Next Level: " << sword.getXPForNextLevel() << "\n";
    double damageDealt = sword.damage(15); // Assuming playerStrength is 15
    std::cout << "Damage Dealt by Sword: " << damageDealt << "\n";
    sword.addXP(100); // Add 10 XP (10% of 100) to the sword
    std::cout << "Sword XP after adding 100 damage: " << sword.getXPForNextLevel() << "\n";

    // Arm a Soldier with a sword and test damage again
    soldier.arm(&sword);
    damageDealt = sword.damage(15); // Assuming playerStrength is 15
    std::cout << "Damage Dealt by Soldier with Sword: " << damageDealt << "\n";

    // Arm a Soldier with a ShadowBone and display the weapon
    soldier.arm(shadowBone);
    std::cout << "Soldier's Weapon: " << soldier.printSoldier() << "\n";

    // Test the assignment operators for Mage and Brute
    Mage anotherMage("Another Mage", 90.0, 9.0);
    anotherMage = mage;
    std::cout << "Information of Another Mage after assignment:\n" << anotherMage.printSoldier() << "\n";

    Brute anotherBrute("Another Brute", 140.0, 18.0);
    anotherBrute = brute;
    std::cout << "Information of Another Brute after assignment:\n" << anotherBrute.printSoldier() << "\n";

    delete shadowBone;
    
    return 0;
}
