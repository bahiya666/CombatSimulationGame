main: main.o
	g++ -std=gnu++98 Main.o -o Main

main.o: main.cpp
	g++ -c -std=gnu++98 Main.cpp

Ninja: Ninja.o
	g++ -std=gnu++98 Ninja.o -o Ninja

Ninja.o: Ninja.cpp Ninja.h
	g++ -c -std=gnu++98 Ninja.cpp

Brute: Brute.o
	g++ -std=gnu++98 Brute.o -o Brute

Brute.o: Brute.cpp Brute.h
	g++ -c -std=gnu++98 Brute.cpp

Mage: Mage.o
	g++ -std=gnu++98 Mage.o -o Mage

Mage.o: Mage.cpp Mage.h
	g++ -c -std=gnu++98 Mage.cpp

Soldier: Soldier.o
	g++ -std=gnu++98 Soldier.o -o Soldier

Soldier.o: Soldier.cpp Soldier.h
	g++ -c -std=gnu++98 Soldier.cpp

Sword: Sword.o
	g++ -std=gnu++98 Sword.o -o Sword

Sword.o: Sword.cpp Sword.h
	g++ -c -std=gnu++98 Sword.cpp

ShadowBone: ShadowBone.o
	g++ -std=gnu++98 ShadowBone.o -o ShadowBone

ShadowBone.o: ShadowBone.cpp ShadowBone.h
	g++ -c -std=gnu++98 ShadowBone.cpp

run_main: main
	./main

run_Ninja: Ninja
	./Ninja

run_Brute: Brute
	./Brute

run_Mage: Mage
	./Mage

run_Soldier: Soldier
	./Soldier

run_Sword: Sword
	./Sword

run_ShadowBone: ShadowBone
	./ShadowBone

clean:
	rm -f *.o main Ninja Brute Mage Soldier Sword ShadowBone
