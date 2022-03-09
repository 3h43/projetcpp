#ifndef INGAME_HPP
#define INGAME_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Bibliotheque.hpp"
#include "../Headers/Cimetiere.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Deck.hpp"
#include "../Headers/Joueur.hpp"
#include "../Headers/Pile.hpp"
#include "../Headers/Terrain.hpp"

class Ingame {

	private :

	Joueur* m_joueur1;
	Joueur* m_joueur2;

	public :

// Constructeurs
	Ingame(Joueur*, Joueur*);
	Ingame();
	~Ingame();

// Methodes de base
	Joueur* getJoueur1();
	void setJoueur1(Joueur*);
	Joueur* getJoueur2();
	void setJoueur2(Joueur*);

// Methodes ajoutees
	void poserTerrain(Joueur*, Carte*);
	void poserCreature(Joueur*, Carte*);
	int TypetoInt(Carte*);
	int nbreTerrains(Joueur*);
	std::vector<Carte*> ChoixTerrain(Joueur*, Carte*);
	void attaquerCarte(Creature*, Creature*);
	void envoyerCimetiere(Joueur*, Carte*);
	void afficheJoueur(Joueur*);
	void bibliothequeDebut(Joueur*);
	void poserCarte(Joueur*);
	std::vector<Creature*> ChoixAttaque(Joueur*);
	std::vector<Creature*> ChoixDefense(Joueur*);
	void Combat(Joueur*, Joueur*);
};

#endif
