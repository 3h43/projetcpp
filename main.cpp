#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "Headers/Carte.hpp"
#include "Headers/Bibliotheque.hpp"
#include "Headers/Cimetiere.hpp"
#include "Headers/Creature.hpp"
#include "Headers/Deck.hpp"
#include "Headers/Ingame.hpp"
#include "Headers/Joueur.hpp"
#include "Headers/Pile.hpp"
#include "Headers/Terrain.hpp"



// ENLEVER PIOCHE SI ON UTILISE DES DECKS DE 7 CARTES SEULEMENT
// JE NAI PAS MIS LA LIMITE DE 1 SEUL TERRAIN PAR TOUR
// Parler de l'aléatoire dans le choix du premier joueur
// Pas trop faire nimporte quoi
// Compte ajouter vol et portée
// quelques trucs à régler dans l'affichage comme si plusieurs types -> plusieurs carrés

int main () {

// Créations des vecteurs de types "obligatoires"
  std::vector<std::string> Bleu;
  std::vector<std::string> Rouge;
  std::vector<std::string> Vert;
  std::vector<std::string> Noir;
  std::vector<std::string> Blanc;
  std::vector<std::string> Multiples;
  std::vector<std::string> Multiples2;
  Bleu.push_back("B");
  Rouge.push_back("R");
  Vert.push_back("G");
  Noir.push_back("N");
  Blanc.push_back("W");
  Multiples.push_back("W");
  Multiples.push_back("B");
  Multiples2.push_back("W");
  Multiples2.push_back("B");
  Multiples2.push_back("B");

// Création de carte de type créatures
  Creature* carte1 = new Creature("C1", "B", true, false, 1, 10, 1, Bleu, false, 1, false, false);
  Creature* carte2 = new Creature("C2", "N", true, false, 2, 10, 1, Noir, false, 2, false, false);
  Creature* carte3 = new Creature("C3", "N", true, false, 1, 10, 1, Noir, false, 3, false, false);
  Creature* carte4 = new Creature("C4", "G", true, false, 4, 10, 1, Vert, false, 4, false, false);
  Creature* carte5 = new Creature("C5", "W", true, false, 1, 10, 1, Blanc, false, 5, false, false);
  Creature* carte6 = new Creature("C6", "W", true, false, 3, 10, 1, Blanc, false, 6, false, false);
  Creature* carte7 = new Creature("C7", "B", true, false, 1, 10, 1, Bleu, false, 7, false, false);
  Creature* carte8 = new Creature("C8", "N", true, false, 2, 10, 1, Noir, false, 8, false, false);
  Creature* carte9 = new Creature("C9", "G", true, false, 1, 10, 1, Vert, false, 9, false, false);
  Creature* carte26 = new Creature("C10", "B", true, false, 3, 10, 1, Bleu, false, 10, false, false);
  Creature* carte27 = new Creature("C11", "B", true, false, 1, 10, 1, Bleu, false, 11, false, false);
  Creature* carte28 = new Creature("C12", "N", true, false, 2, 10, 1, Noir, false, 12, false, false);
  Creature* carte29 = new Creature("C13", "N", true, false, 1, 10, 1, Noir, false, 13, false, false);
  Creature* carte30 = new Creature("C14", "W", true, false, 5, 10, 1, Blanc, false, 14, false, false);
  Creature* carte31 = new Creature("C15", "W", true, false, 20, 10, 1, Blanc, false, 15, false, false);
  Creature* carte32 = new Creature("C16", "G", true, false, 1, 10, 1, Vert, false, 16, false, false);
  Creature* carte35 = new Creature("CSpeciale1", "B", true, false, 1, 10, 3, Bleu, false, 35, false, false);
  Creature* carte36 = new Creature("CSpeciale2", "B", true, false, 1, 10, 1, Multiples, false, 36, false, false);
  Creature* carte37 = new Creature("CSpeciale3", "B", true, false, 1, 10, 1, Multiples2, false, 37, false, false);
  Creature* carte38 = new Creature("CVol", "B", true, false, 1, 10, 1, Bleu, false, 38, true, false);
  Creature* carte39 = new Creature("CPortee", "G", true, false, 1, 10, 1, Vert, false, 39, false, true);

// Création de cartes de type terrain
  Terrain* carte10 = new Terrain("B1", "B", false, false, 17);
  Terrain* carte11 = new Terrain("B2", "B", false, false, 18);
  Terrain* carte12 = new Terrain("B3", "B", false, false, 19);
  Terrain* carte13 = new Terrain("N1", "N", false, false, 20);
  Terrain* carte14 = new Terrain("W1", "W", false, false, 21);
  Terrain* carte15 = new Terrain("W2", "W", false, false, 22);
  Terrain* carte16 = new Terrain("W3", "W", false, false, 23);
  Terrain* carte17 = new Terrain("B4", "B", false, false, 24);
  Terrain* carte18 = new Terrain("N2", "N", false, false, 25);
  Terrain* carte19 = new Terrain("W4", "W", false, false, 26);
  Terrain* carte20 = new Terrain("B5", "B", false, false, 27);
  Terrain* carte21 = new Terrain("N3", "N", false, false, 28);
  Terrain* carte22 = new Terrain("W5", "W", false, false, 29);
  Terrain* carte23 = new Terrain("B6", "B", false, false, 30);
  Terrain* carte24 = new Terrain("N4", "N", false, false, 31);
  Terrain* carte25 = new Terrain("W6", "W", false, false, 32);
  Terrain* carte33 = new Terrain("G1", "G", false, false, 33);
  Terrain* carte34 = new Terrain("G2", "G", false, false, 34);

  std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
  std::cout << "———————————————————————————DEBUT DE LA PARTIE———————————————————————————— " << std::endl;
  std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
  std::cout << " " << std::endl;

// Création des deux joueurs

  std::string nomUtilisateur1("");
  std::cout << "> Quel est votre pseudo?" << std::endl;
  std::cin >> nomUtilisateur1 ;

  std::string nomUtilisateur2("");
  std::cout << "> Quel est votre pseudo?" << std::endl;
  std::cin >> nomUtilisateur2 ;

  Deck* deck1 = new Deck();
  Bibliotheque* bibliotheque1 = new Bibliotheque();
  Hand* hand1 = new Hand();
  Cimetiere* cimetiere1 = new Cimetiere();
  Plateau* plateau1 = new Plateau();

  Deck* deck2 = new Deck();
  Bibliotheque* bibliotheque2 = new Bibliotheque();
  Hand* hand2 = new Hand();
  Cimetiere* cimetiere2 = new Cimetiere();
  Plateau* plateau2 = new Plateau();
  std::cout << " " << std::endl;

  Joueur* joueur1 = new Joueur(nomUtilisateur1, 20, deck1, hand1, bibliotheque1, cimetiere1, plateau1);
  std::cout << "> Joueur 1 créé !" << std::endl;
  std::cout << " " << std::endl;

  Joueur* joueur2 = new Joueur(nomUtilisateur2, 20, deck2, hand2, bibliotheque2, cimetiere2, plateau2);
  std::cout << "> Joueur 2 créé !" << std::endl;
  std::cout << " " << std::endl;

// Création du jeu en lui même avec les deux joueurs

  Ingame* jeu = new Ingame(joueur1, joueur2);

  std::cout << "> Voici les joueurs : " << std::endl;
  std::cout << " " << std::endl;

  joueur1->afficheJoueur();
  joueur2->afficheJoueur();

// Création des différents decks, voici différents Deck en fonction de ce que l'on souhaite faire. Le deck partie Normale permet d'avoir un semblant de partie normale, les autres sont des cas spéciaux.

//Partie Normale
/*
  joueur1->addDeck(carte8);
  joueur1->addDeck(carte4);
  joueur1->addDeck(carte3);
  joueur1->addDeck(carte11);
  joueur1->addDeck(carte12);
  joueur1->addDeck(carte13);
  joueur1->addDeck(carte14);
  joueur1->addDeck(carte15);
  joueur1->addDeck(carte16);
  joueur1->addDeck(carte26);
  joueur1->addDeck(carte27);
  joueur1->addDeck(carte28);
  joueur1->addDeck(carte29);
  joueur1->addDeck(carte30);
  joueur1->addDeck(carte31);
  joueur1->addDeck(carte32);


  joueur2->addDeck(carte2);
  joueur2->addDeck(carte1);
  joueur2->addDeck(carte5);
  joueur2->addDeck(carte6);
  joueur2->addDeck(carte7);
  joueur2->addDeck(carte10);
  joueur2->addDeck(carte9);
  joueur2->addDeck(carte17);
  joueur2->addDeck(carte18);
  joueur2->addDeck(carte19);
  joueur2->addDeck(carte20);
  joueur2->addDeck(carte21);
  joueur2->addDeck(carte22);
  joueur2->addDeck(carte23);
  joueur2->addDeck(carte24);
  joueur2->addDeck(carte25);
*/

//Victoire CAR PV = 0 + AJOUTER LES PIOCHES POUR MONTRER FIN DE JEU QUAND PLUS DE PLACE BIBLIOTHEQUE
/*
joueur1->addDeck(carte31);
joueur1->addDeck(carte14);
joueur1->addDeck(carte15);
joueur1->addDeck(carte16);
joueur1->addDeck(carte19);
joueur1->addDeck(carte22);
joueur1->addDeck(carte25);

joueur2->addDeck(carte10);
joueur2->addDeck(carte27);
joueur2->addDeck(carte11);
joueur2->addDeck(carte7);
joueur2->addDeck(carte13);
joueur2->addDeck(carte12);
joueur2->addDeck(carte9);
*/

//Deck défense de plusieurs creatures sur une créature

joueur1->addDeck(carte27);
joueur1->addDeck(carte28);
joueur1->addDeck(carte11);
joueur1->addDeck(carte12);
joueur1->addDeck(carte18);
joueur1->addDeck(carte13);
joueur1->addDeck(carte25);

joueur2->addDeck(carte6);
joueur2->addDeck(carte32);
joueur2->addDeck(carte22);
joueur2->addDeck(carte25);
joueur2->addDeck(carte19);
joueur2->addDeck(carte33);
joueur2->addDeck(carte34);


//Deck un monstre sur une créature
/*
joueur1->addDeck(carte27);
joueur1->addDeck(carte28);
joueur1->addDeck(carte11);
joueur1->addDeck(carte12);
joueur1->addDeck(carte18);
joueur1->addDeck(carte13);
joueur1->addDeck(carte25);

joueur2->addDeck(carte6);
joueur2->addDeck(carte32);
joueur2->addDeck(carte22);
joueur2->addDeck(carte25);
joueur2->addDeck(carte19);
joueur2->addDeck(carte33);
joueur2->addDeck(carte34);
*/

//Pioche fonctionne + plus de 7 cartes en main => défausse / dire non tout le temps
/*
joueur1->addDeck(carte8);
joueur1->addDeck(carte4);
joueur1->addDeck(carte3);
joueur1->addDeck(carte11);
joueur1->addDeck(carte12);
joueur1->addDeck(carte13);
joueur1->addDeck(carte14);
joueur1->addDeck(carte15);
joueur1->addDeck(carte16);
joueur1->addDeck(carte26);
joueur1->addDeck(carte27);
joueur1->addDeck(carte28);
joueur1->addDeck(carte29);
joueur1->addDeck(carte30);
joueur1->addDeck(carte31);
joueur1->addDeck(carte32);


joueur2->addDeck(carte2);
joueur2->addDeck(carte1);
joueur2->addDeck(carte5);
joueur2->addDeck(carte6);
joueur2->addDeck(carte7);
joueur2->addDeck(carte10);
joueur2->addDeck(carte9);
joueur2->addDeck(carte17);
joueur2->addDeck(carte18);
joueur2->addDeck(carte19);
joueur2->addDeck(carte20);
joueur2->addDeck(carte21);
joueur2->addDeck(carte22);
joueur2->addDeck(carte23);
joueur2->addDeck(carte24);
joueur2->addDeck(carte25);
*/

//Deck utilisation de cartes avec un coût en terrains arbitraires de + de 1
/*
joueur1->addDeck(carte35);
joueur1->addDeck(carte28);
joueur1->addDeck(carte11);
joueur1->addDeck(carte12);
joueur1->addDeck(carte18);
joueur1->addDeck(carte13);
joueur1->addDeck(carte25);

joueur2->addDeck(carte6);
joueur2->addDeck(carte32);
joueur2->addDeck(carte22);
joueur2->addDeck(carte25);
joueur2->addDeck(carte19);
joueur2->addDeck(carte33);
joueur2->addDeck(carte34);
*/

//Deck utilisation de cartes avec un coût de type de + de 1 — Bleu - White
/*
joueur1->addDeck(carte36);
joueur1->addDeck(carte28);
joueur1->addDeck(carte11);
joueur1->addDeck(carte12);
joueur1->addDeck(carte18);
joueur1->addDeck(carte13);
joueur1->addDeck(carte25);

joueur2->addDeck(carte6);
joueur2->addDeck(carte32);
joueur2->addDeck(carte22);
joueur2->addDeck(carte25);
joueur2->addDeck(carte19);
joueur2->addDeck(carte33);
joueur2->addDeck(carte34);
*/

//Même chose mais avec comme cout en type Bleu - Bleu - White
/*
joueur1->addDeck(carte37);
joueur1->addDeck(carte28);
joueur1->addDeck(carte11);
joueur1->addDeck(carte12);
joueur1->addDeck(carte18);
joueur1->addDeck(carte13);
joueur1->addDeck(carte25);

joueur2->addDeck(carte6);
joueur2->addDeck(carte32);
joueur2->addDeck(carte22);
joueur2->addDeck(carte25);
joueur2->addDeck(carte19);
joueur2->addDeck(carte33);
joueur2->addDeck(carte34);
*/

// Test de vol et portee. On voit que C16 qui bloque CVol ne prend pas de dégats car c'est le joueur qui les prend, on voit que CPortee bloque bien car elle a portee/vol
/*
joueur1->addDeck(carte38);
joueur1->addDeck(carte28);
joueur1->addDeck(carte11);
joueur1->addDeck(carte12);
joueur1->addDeck(carte18);
joueur1->addDeck(carte13);
joueur1->addDeck(carte25);

joueur2->addDeck(carte6);
joueur2->addDeck(carte32);
joueur2->addDeck(carte22);
joueur2->addDeck(carte25);
joueur2->addDeck(carte34);
joueur2->addDeck(carte33);
joueur2->addDeck(carte39);
*/

// Début de la partie, on mélange les decks, crée les pioches, pioche les 7 premières cartes pour chaque joueur
  joueur1->melangeDeck();
  joueur2->melangeDeck();

  joueur1->CreationPioche();
  joueur2->CreationPioche();

  joueur1->piocheDebut();
  joueur2->piocheDebut();

  int tour = 1;

// Le joueur commençant la partie est choisi au hasard
  std::vector<Joueur*> ChoixJoueurs;

  std::mt19937 rng(std::random_device{}());
  auto hasard = std::uniform_int_distribution<>{0, 100}(rng);
  if (hasard % 2 == 0){
      ChoixJoueurs.push_back(joueur2);
      ChoixJoueurs.push_back(joueur1);
  }
  else {
      ChoixJoueurs.push_back(joueur1);
      ChoixJoueurs.push_back(joueur2);
  }

// La partie commence, tant que l'on n'a pas les conditions de fin on continue d'enchaîner les tours.

  while( ChoixJoueurs.at(0)->getPV() != 0 && ChoixJoueurs.at(1)->getPV() != 0  && ChoixJoueurs.at(0)->getMain()->getPile().size() != 0  && ChoixJoueurs.at(1)->getMain()->getPile().size() != 0 ){

      // TOUR 1

      // PHASE DE PIOCHE
/*
      if (tour > 1) {
        if (ChoixJoueurs.at(0)->getBibliotheque()->getPile().size() == 0) {
          std::cout << ChoixJoueurs.at(0)->getPseudo() << " n'a plus de carte dans la pioche, " << ChoixJoueurs.at(1)->getPseudo() << " a gagné!";
          break;
        }
        else {
          ChoixJoueurs.at(0)->pioche();
        }
        if (ChoixJoueurs.at(1)->getBibliotheque()->getPile().size() == 0) {
          std::cout << ChoixJoueurs.at(1)->getPseudo() << " n'a plus de carte dans la pioche, " << ChoixJoueurs.at(0)->getPseudo() << " a gagné!";
          break;
        }
        else {
          ChoixJoueurs.at(1)->pioche();
        }
      }
*/
      // PHASE DE DESENGAGEMENT

      ChoixJoueurs.at(0)->DebutTour();
      ChoixJoueurs.at(1)->DebutTour();

      // PHASE PRINCIPALE

      std::cout << " " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << "—————————————————————————PHASE DE POSE DE CARTES————————————————————————— " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << " " << std::endl;
      ChoixJoueurs.at(0)->poserCarte();

      // PHASE DE COMBAT

      jeu->Combat(ChoixJoueurs.at(0), ChoixJoueurs.at(1));

      // PHASE SECONDAIRE

      std::cout << " " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << "—————————————————————————PHASE DE POSE DE CARTES————————————————————————— " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << " " << std::endl;
      ChoixJoueurs.at(0)->poserCarte();

      // FIN DE TOUR

      std::cout << " " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << "———————————————————————————AFFICHAGE DES PV—————————————————————————————— " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << " " << std::endl;
      ChoixJoueurs.at(0)->afficheJoueur();
      ChoixJoueurs.at(1)->afficheJoueur();

      ChoixJoueurs.at(0)->VerifMain();
      ChoixJoueurs.at(1)->VerifMain();

      tour += 1;

      // TOUR 2 DANS LE SENS CONTRAIRE

      if(ChoixJoueurs.at(0)->getPV() != 0 && ChoixJoueurs.at(1)->getPV() != 0 && ChoixJoueurs.at(0)->getMain()->getPile().size() != 0  && ChoixJoueurs.at(1)->getMain()->getPile().size() != 0 ){

      // PHASE DE PIOCHE
/*
        if (tour > 1) {
          if (ChoixJoueurs.at(0)->getBibliotheque()->getPile().size() == 0) {
            std::cout << ChoixJoueurs.at(0)->getPseudo() << " n'a plus de carte dans la pioche, " << ChoixJoueurs.at(1)->getPseudo() << " a gagné!";
            break;
          }
          else {
            ChoixJoueurs.at(0)->pioche();
          }
          if (ChoixJoueurs.at(1)->getBibliotheque()->getPile().size() == 0) {
            std::cout << ChoixJoueurs.at(1)->getPseudo() << " n'a plus de carte dans la pioche, " << ChoixJoueurs.at(0)->getPseudo() << " a gagné!";
            break;
          }
          else {
            ChoixJoueurs.at(1)->pioche();
          }
        }
*/
      // PHASE DE DESENGAGEMENT

      ChoixJoueurs.at(0)->DebutTour();
      ChoixJoueurs.at(1)->DebutTour();

      // PHASE PRINCIPALE

        std::cout << " " << std::endl;
        std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
        std::cout << "—————————————————————————PHASE DE POSE DE CARTES————————————————————————— " << std::endl;
        std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
        std::cout << " " << std::endl;
        ChoixJoueurs.at(1)->poserCarte();

      // PHASE DE COMBAT

        jeu->Combat(ChoixJoueurs.at(1), ChoixJoueurs.at(0));

      // PHASE SECONDAIRE

        std::cout << " " << std::endl;
        std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
        std::cout << "—————————————————————————PHASE DE POSE DE CARTES————————————————————————— " << std::endl;
        std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
        std::cout << " " << std::endl;
        ChoixJoueurs.at(1)->poserCarte();

     // FIN DE TOUR

        std::cout << " " << std::endl;
        std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
        std::cout << "———————————————————————————AFFICHAGE DES PV—————————————————————————————— " << std::endl;
        std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
        std::cout << " " << std::endl;
        ChoixJoueurs.at(0)->afficheJoueur();
        ChoixJoueurs.at(1)->afficheJoueur();

        ChoixJoueurs.at(0)->VerifMain();
        ChoixJoueurs.at(1)->VerifMain();

        tour += 1;
        }
      }


      // Messages de fin de partie avec annonce du gagnant

      if (ChoixJoueurs.at(0)->getPV() == 0) {
        std::cout << "Fin de partie : " << ChoixJoueurs.at(1)->getPseudo() << " a gagné !" << std::endl;
      }

      else if (ChoixJoueurs.at(1)->getPV() == 0) {
        std::cout << "Fin de partie : " << ChoixJoueurs.at(0)->getPseudo() << " a gagné !" << std::endl;
      }

      std::cout << " " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << "————————————————————————————FIN DE LA PARTIE————————————————————————————— " << std::endl;
      std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
      std::cout << " " << std::endl;

      return 0;
}
