#ifndef BIBLIOTHEQUE_HPP
#define BIBLIOTHEQUE_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"

class Bibliotheque : public Pile {

	private :

	std::vector<Carte*> m_bibliotheque;

	public :

	Bibliotheque();
	~Bibliotheque();
	std::vector<Carte*> getPile();
	void addPile(Carte*);
	Carte* pioche();
	void affiche();
	void efface();
	std::vector<Carte*>::iterator getBegin();
	std::vector<Carte*>::iterator getEnd();
};

#endif
