
CXX=g++ -std=c++11
CXXFLAGS=-Wall -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: Body/Bibliotheque.o Body/Cimetiere.o Body/Creature.o Body/Plateau.o Body/Deck.o Body/Ingame.o Body/Joueur.o Body/Hand.o Body/Terrain.o main.o
	$(CXX) $^ -o $@

.PHONY: run clean

run: main
	./$<

clean:
	rm -f Body/*.o *~ *.core
