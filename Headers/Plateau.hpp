#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"


class Plateau : public Pile {

	private :

	std::vector<Carte*> m_plateau;

	public :

	Plateau();
	~Plateau();
	std::vector<Carte*> getPile();
	void addPile(Carte*);
	void affiche();
	void effaceCreature(Creature*);
	void efface();

	std::vector<Carte*>::iterator getBegin();
	std::vector<Carte*>::iterator getEnd();
	std::vector<int> compteTerrains();
	Carte* position(int);
	int nbTerrains();
};

#endif
