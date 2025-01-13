Overview
The game includes:
Soldiers: The base class for all characters. Soldiers can be armed with weapons and can take damage during combat.
Brutes: A type of soldier with a rage mechanic. Brutes get stronger as they engage in combat.
Mages: Mages use magic-based weapons, such as the ShadowBone, in addition to regular swords.
Ninjas: A stealthy class that can avoid damage every third turn.
Weapons: The game uses different types of weapons, such as Swords and ShadowBones, each with unique damage calculations and leveling systems.

Key Classes
Soldier
  Attributes:
  name: The name of the soldier.
  health: The soldier's health.
  strength: The soldier's strength.
  sword: A pointer to the sword or weapon the soldier is equipped with.
  Functions:
  takeDamage(double damage): Decreases health by the given damage value. Returns true if the soldier dies, otherwise false.
  arm(Sword* sword): Arms the soldier with a new sword.
  printSoldier(): Returns a string representation of the soldier's attributes.
Brute
  Attributes:
  rageMeter: A meter that increases when the brute attacks and resets when the brute kills an enemy.
  Functions:
  attack(Brute* brute): Attacks another Brute, with increased damage if the rage meter is full.
  attack(Ninja* ninja): Attacks a Ninja.
  attack(Mage* mage): Attacks a Mage.
Mage
  Attributes:
  shadowBone: A special weapon the Mage can equip in addition to a sword.
  Functions:
  armShadow(ShadowBone* shadowBone): Arms the Mage with a ShadowBone.
  attack(Brute* brute): Attacks a Brute using either the sword or the ShadowBone.
  attack(Ninja* ninja): Attacks a Ninja using either the sword or the ShadowBone.
  attack(Mage* mage): Attacks another Mage.
Ninja
  Attributes:
  moveCount: Tracks the number of moves made by the Ninja. Every third move, the Ninja avoids damage.
  Functions:
  takeDamage(double damage): Reduces health by the damage value, but the Ninja avoids damage every third move.
  attack(Brute* brute): Attacks a Brute.
  attack(Ninja* ninja): Attacks another Ninja.
  attack(Mage* mage): Attacks a Mage.
Sword and ShadowBone
  Sword: A weapon class with attributes such as attack, level, and xp. Swords gain experience and increase in strength as they are used in battle.
  ShadowBone: A special type of sword used by Mages. It includes a magicMultiplier attribute that affects the damage calculation.
  Features
  Combat Mechanics: Soldiers can attack each other with their equipped weapons. The damage dealt is calculated based on the soldier's strength and the weapon's attributes. Brutes get stronger over time through their rage mechanic.

Weapon Experience System: Swords and ShadowBones gain experience (XP) when used in combat. They level up, improving their damage output.

Ninja's Stealth Mechanic: Every third move, a Ninja avoids taking damage, making them harder to defeat.

Requirements
C++11 or later
C++ standard library
A C++ IDE or compiler (e.g., GCC, Clang, Visual Studio)

Compilation
To compile the project, use the following command:
g++ -std=c++11 -o combat_simulation main.cpp Soldier.cpp Brute.cpp Mage.cpp Ninja.cpp Sword.cpp ShadowBone.cpp
Then, run the program:
./combat_simulation
