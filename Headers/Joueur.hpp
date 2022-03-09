#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"
#include "../Headers/Deck.hpp"
#include "../Headers/Hand.hpp"
#include "../Headers/Bibliotheque.hpp"
#include "../Headers/Cimetiere.hpp"
#include "../Headers/Plateau.hpp"



class Joueur {

	private :

	std::string m_pseudo;
	int m_pv;
	Deck* m_deck;
	Hand* m_hand;
	Bibliotheque* m_bibliotheque;
	Cimetiere* m_cimetiere;
	Plateau* m_plateau;

	public :

	// Constructeurs
	Joueur(std::string, int, Deck*, Hand*, Bibliotheque*, Cimetiere*, Plateau*);
	Joueur();
	~Joueur();


	void setPseudo(std::string);
	std::string getPseudo() const;
	void setPV(int);
	int getPV() const;
	void afficheJoueur();
	void afficheMain();
	void setMain(Hand*);
	Hand* getMain();
	void addMain(Carte*);
	void afficheBibliotheque();
	void addBibliotheque(Carte*);
	void setBibliotheque(Bibliotheque*);
	Bibliotheque* getBibliotheque();
	void afficheDeck();
	void addDeck(Carte*);
	void setDeck(Deck*);
	Deck* getDeck();
	void afficheCimetiere();
	void addCimetiere(Creature*);
	void setCimetiere(Cimetiere*);
	Cimetiere* getCimetiere();

	// Methodes ajoutees

	void defausser(Carte*);
	void pioche();
	void piocheDebut();
	void melangeDeck();
	void CreationPioche();
	Plateau* getPlateau();
	void setPlateau(Plateau*);
	void affichePlateau();
	void addPlateau(Carte*);
	bool operator== (Joueur*);
	void effaceCarte(int);
	int tailleMain();
	void poserTerrain(Carte*);
	int nbreTerrains();
	int TypetoInt(Carte*);
	void poserCreature(Creature*);
	Creature* choixCreature();
	void poserCarte();
	std::vector<Carte*> ChoixTerrain(Creature*);
	void DebutTour();
	void VerifMain();
};

#endif
