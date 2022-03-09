#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>


#include "../Headers/Carte.hpp"
#include "../Headers/Joueur.hpp"
#include "../Headers/Deck.hpp"
#include "../Headers/Hand.hpp"
#include "../Headers/Bibliotheque.hpp"
#include "../Headers/Cimetiere.hpp"
#include "../Headers/Plateau.hpp"



// Constructeurs

Joueur::Joueur(std::string pseudo, int pv, Deck* deck, Hand* hand, Bibliotheque* bibliotheque, Cimetiere* cimetiere, Plateau* plateau){
  m_pseudo = pseudo;
  m_pv = pv;
  m_deck = deck;
  m_hand = hand;
  m_bibliotheque = bibliotheque;
  m_cimetiere = cimetiere;
  m_plateau = plateau;
}

Joueur::Joueur(){
}

Joueur::~Joueur(){
}

// Methodes de base

std::string Joueur::getPseudo() const{
  return m_pseudo;
}

void Joueur::setPseudo(std::string pseudo){
  m_pseudo = pseudo;
}

int Joueur::getPV() const{
  return m_pv;
}

void Joueur::setPV(int pv){
  m_pv = pv;
}

void Joueur::afficheJoueur(){
  std::cout << "Pseudo : " << this->m_pseudo << " | PV : " << this->m_pv << std::endl ;
}

void Joueur::afficheMain(){
  m_hand->affiche();
}

void Joueur::setMain(Hand* main){
  m_hand = main;
}

Hand* Joueur::getMain(){
  return m_hand;
}

void Joueur::addMain(Carte* carte){
  m_hand->addPile(carte);
}

void Joueur::addBibliotheque(Carte* carte){
  m_bibliotheque->addPile(carte);
}

void Joueur::afficheBibliotheque(){
  m_bibliotheque->affiche();
}

void Joueur::setBibliotheque(Bibliotheque* bibliotheque){
  m_bibliotheque = bibliotheque;
}

Bibliotheque* Joueur::getBibliotheque(){
  return m_bibliotheque;
}

void Joueur::addDeck(Carte* carte){
  m_deck->addPile(carte);
}

void Joueur::afficheDeck(){
  m_deck->affiche();
}

void Joueur::setDeck(Deck* deck){
  m_deck = deck;
}

Deck* Joueur::getDeck() {
  return m_deck;
}

void Joueur::addCimetiere(Creature* creature){
if( std::find(m_plateau->getBegin(), m_plateau->getEnd(), creature) != m_plateau->getEnd()) {
  m_cimetiere->addPile(creature);
  m_plateau->effaceCreature(creature);
  }
else {
  std::cout << "Cette carte n'est pas sur votre plateau!" << std::endl ;
  }
}

void Joueur::afficheCimetiere(){
  m_cimetiere->affiche();
}

void Joueur::setCimetiere(Cimetiere* cimetiere){
  m_cimetiere = cimetiere;
}

Cimetiere* Joueur::getCimetiere(){
  return m_cimetiere;
}

void Joueur::affichePlateau(){
  m_plateau->affiche();
}

void Joueur::setPlateau(Plateau* plateau){
  m_plateau = plateau;
}

Plateau* Joueur::getPlateau(){
  return m_plateau;
}

void Joueur::addPlateau(Carte* carte){
  m_plateau->addPile(carte);
}

// Methodes ajoutees

// On crée la pioche
void Joueur::CreationPioche(){
  for (Carte* i : m_deck->getPile()){
    m_bibliotheque->addPile(i);
  }
}

// Lorsqu'un joueur pioche
void Joueur::pioche(){
  m_hand->addPile(m_bibliotheque->pioche());
  m_bibliotheque->efface();
}

// Première fois que le joueur pioche ses 7 cartes
void Joueur::piocheDebut(){
  for (int i = 0; i < 7; i++) {
    pioche();
  }
}

// Efface une carte à une position i de la main d'un joueur
void Joueur::effaceCarte(int i){
      m_hand->effacer(i);
  }

// Rend la taille de la main d'un joueur
int Joueur::tailleMain(){
  return m_hand->taille();
}

// Melange le deck d'un joueur
void Joueur::melangeDeck(){
  std::random_device rd;
  auto rng = std::default_random_engine (rd());
  std::shuffle(m_deck->getBegin(), m_deck->getEnd(), rng);
}

// Surcharge de == pour les joueurs, /!\ il ne faut pas que les joueurs s'appellent pareil
bool Joueur::operator== ( Joueur* joueur){
  return (this->getPseudo() == joueur->getPseudo() && this->getPV() == joueur->getPV() );
}

// Pose un terrain sur le plateau
void Joueur::poserTerrain(Carte* carte){
  if (carte->getCreature() == false) {
      addPlateau(carte);
      for (int i = 0 ; i < tailleMain() ; i++){
        if (carte->getNom() == getMain()->getCarte(i)->getNom()){
          effaceCarte(i);
        }
      }
  }
  else {
    std::cout << "> La carte n'est pas un terrain" << std::endl;
  }
}

// Compte le nombre de terrains sur un plateau
int Joueur::nbreTerrains(){
  int p = 0;
    for (unsigned long i = 0 ; i < m_plateau->compteTerrains().size() ; i ++ ) {
      p += m_plateau->compteTerrains().at(i);
    }
    return p;
}

// Permet de choisir des terrains qui ne sont pas engagés, pour pouvoir poser une créature et retourne tous ces terrains choisis
std::vector<Carte*> Joueur::ChoixTerrain(Creature* carte){
  std::vector<Carte*> terrainsChoisis;
  while (terrainsChoisis.size() < carte->getCoutTerr()) {
    std::cout << "> Quel terrain voulez-vous choisir, parmi ceux non engagés ? " << std::endl;
    std::string terrain  = "";
    std::cin >> terrain;
    for ( unsigned long j = 0 ; j < m_plateau->getPile().size() ; j ++ ) {
      if (terrain == ((m_plateau->position(j))->getNom()) ){
        if (m_plateau->position(j)->getEngage() == false && m_plateau->position(j)->getCreature() == false){
          terrainsChoisis.push_back(m_plateau->position(j));
          terrainsChoisis.back()->setEngage(true);
        }
      }
    }
  }
  return terrainsChoisis;
}

// Permet à partir d'un type d'avoir sa position dans le tableau de type compteType
int Joueur::TypetoInt(Carte* carte){
  if (carte->getType() == "R") { return 0;}
  if (carte->getType() == "B") { return 1;}
  if (carte->getType() == "W") { return 2;}
  if (carte->getType() == "G") { return 3;}
  if (carte->getType() == "N") { return 4;}
  return -1;
}


// Methode permettant de poser une créature, elle fait toutes les vérifications de type et du nombre de terrains, il faut qu'il y ait assez de terrains et qu'ils correspondent bien tout en n'étant pas engagés
void Joueur::poserCreature(Creature* carte) {
  int n,p = 0;
  if (carte->getCreature()){
    n = TypetoInt(carte);
    p = nbreTerrains();
  if (m_plateau->nbTerrains() >= carte->nbTypes()) {
  std::vector<Carte*> terrainsChoisis;
  terrainsChoisis = ChoixTerrain(carte);

    if (m_plateau->compteTerrains().at(n) >= carte->compteType().at(n) &&  terrainsChoisis.size() == carte->getCoutTerr()){

      for (unsigned long i = 0 ; i < 5; i++){
        if (carte->compteType().at(i) > 0){
          int coutCarteCopie = carte->compteType().at(i);
          for (int j = 0 ; j < carte->compteType().at(i); j++){
            for (Carte* c : m_plateau->getPile() ) {

              if (c->getEngage() == false && c->getType() == carte->InttoType(i) /*&& coutCarteCopie > 0 */ && c->getCreature() == false){
                if (coutCarteCopie > 0){
                  c->setEngage(true);
                  }
                coutCarteCopie -= 1;
              }

            }
          }


        }
      }
    addPlateau(carte);
    m_hand->effaceCarte(carte->getNom());
    carte->setEngage(true);
    std::cout << "> Pose de créature pour "<< getPseudo() << " réussie !" << std::endl;
    }
    else {
      std::cout << "> Impossible" << std::endl;
      for (unsigned long i = 0; i < terrainsChoisis.size(); i++){
        terrainsChoisis.at(i)->setEngage(false);
      }
    }
  }
  else {
    std::cout << "> Il n'y a pas assez de terrains en jeu !" << std::endl;
  }
}
  else {
    std::cout << "> La carte n'est pas une creature" << std::endl;
  }
}

//Methode permettant à un joueur de choisir une créature non engagée sur son plateau et la retourne
Creature* Joueur::choixCreature(){
  Creature* creatureChoix;
  bool exist = true;
  bool error = false;
  std::string reponse = "";
  std::cout << "> Voici votre plateau :" << std::endl;
  affichePlateau();
  std::cout << "> Quelle créature voulez-vous choisir ?" << std::endl;
  std::string creature;
  std::cin >> creature;

  for (Carte* c : m_plateau->getPile()){
    if (creature == c->getNom()){
      exist = false;
      if (c->getEngage() == false){
        if (c->getCreature() == true){
            c->setEngage(true);
            creatureChoix = dynamic_cast<Creature*> (c);
            break;
        }
        else {
          std::cout << "> Ce n'est pas une créature" << std::endl;
          error = true;
          }
        }
        else {
          std::cout << "> Cette créature est déjà engagée" << std::endl;
          error = true;
        }
      }
  }
  if (exist == true){
    std::cout << "Cette créature n'est pas sur votre plateau" << std::endl;
  }
  if (error == true) {
    choixCreature();
  }
  return creatureChoix;
}

//Methode pour poser une carte, si on a une créature elle fait appel à la méthode poserCreature, si on a un terrain elle fait appel à la methode poserTerrain
void Joueur::poserCarte(){
  std::string reponse = "";
  std::string reponse1 = "";
  std::cout << "> "<< getPseudo() << " veut-il poser une carte ? y|n " << std::endl;
  std::cin >> reponse;
  if (reponse == "y"){
    std::cout << "> Voici votre main : Veuillez renseigner le nom de la carte à poser" << std::endl;
    afficheMain();
    std::string carte;
    std::cin >> carte;
    for (Carte* c : m_hand->getPile()){
      if (carte == c->getNom()) {
        if (c->getCreature()){
          poserCreature(dynamic_cast<Creature*>(c));
        }
        else {
          poserTerrain(c);
        }
      }
    }
    std::cout << "> Voici votre plateau, s'il n'est pas vide : " << std::endl ;
    affichePlateau();

    std::cout << "> " << getPseudo() << " veut-il poser une nouvelle carte ? y|n " << std::endl;
    std::cin >> reponse1;

    if (reponse1 == "y"){
      poserCarte();
    }
    else {
      std::cout << "> Fin de la phase de pose de carte pour " << getPseudo() << std::endl;
    }
}
  else if (reponse == "n") {
    std::cout << "> Pas de jeu pour " << getPseudo() << std::endl;
  }
  else {
    std::cout << "> La réponse n'est pas bonne " << getPseudo() << std::endl;
    poserCarte();
  }
}

// Reset les engagements et les valeurs de force et endurance au début d'un tour
void Joueur::DebutTour(){
  for (Carte* c : m_plateau->getPile()){
    c->setEngage(false);
    if (c->getCreature()){
      dynamic_cast<Creature*> (c)->setForce(dynamic_cast<Creature*> (c)->getForceBase());
      dynamic_cast<Creature*> (c)->setEndurance(dynamic_cast<Creature*> (c)->getEnduranceBase());
    }
  }
}

//Methode vérifiant qu'on n'a pas plus de 7 cartes, si c'est le cas on doit se défausser
void Joueur::VerifMain(){
  if (tailleMain() > 7){
    std::cout << getPseudo() << ", vous avez plus de 7 cartes, choisissez un carte à mettre au cimetière : " << std::endl;
    afficheMain();
    std::string choix = "";
    std::cin >> choix;
    for (Carte* c : m_hand->getPile()){
      if (c->getNom() == choix){
        m_cimetiere->addPile(c);
        m_hand->effaceCarte(choix);
      }
    }
  }
}
