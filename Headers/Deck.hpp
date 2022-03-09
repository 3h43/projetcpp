#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"

class Deck : public Pile {

	private :

	std::vector<Carte*> m_deck;

	public :

		Deck();
		~Deck();
		std::vector<Carte*> getPile();
		void addPile(Carte*);
		void affiche();
		void efface();
		std::vector<Carte*>::iterator getBegin();
		std::vector<Carte*>::iterator getEnd();
};

#endif
