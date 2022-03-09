#ifndef Hand_HPP
#define Hand_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"

class Hand : public Pile {

	private :

	std::vector<Carte*> m_hand;

	public :

		Hand();
		~Hand();
		std::vector<Carte*> getPile();
		void addPile(Carte*);
		Carte* getCarte(int);
		void effaceCarte(Carte*);
		void affiche();
		void efface();
		std::vector<Carte*>::iterator getBegin();
		std::vector<Carte*>::iterator getEnd();
		void effacer(int);
		int taille();
		void effaceCarte(std::string);

};

#endif
