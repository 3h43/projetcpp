#ifndef PILE_HPP
#define PILE_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"

class Pile {

	public :

		virtual std::vector<Carte*> getPile() = 0 ;
		virtual void addPile(Carte*) = 0 ;
		virtual void efface() = 0;
		virtual void affiche() = 0;
		virtual std::vector<Carte*>::iterator getBegin() = 0;
		virtual std::vector<Carte*>::iterator getEnd() = 0;
};

#endif
