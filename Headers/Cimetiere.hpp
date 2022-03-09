#ifndef CIMETIERE_HPP
#define CIMETIERE_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Cimetiere.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"
#include "../Headers/Deck.hpp"

class Cimetiere : public Pile {

	private :

	std::vector<Carte*> m_cimetiere;

	public :

	Cimetiere();
	~Cimetiere();
	std::vector<Carte*> getPile();
	void addPile(Carte*);
	void efface();
	void affiche();
	std::vector<Carte*>::iterator getBegin();
	std::vector<Carte*>::iterator getEnd();

};

#endif
