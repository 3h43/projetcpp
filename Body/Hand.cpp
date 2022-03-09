#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"
#include "../Headers/Deck.hpp"
#include "../Headers/Hand.hpp"

// Constructeurs

Hand::Hand(){
  std::vector<Carte*> hand;
  m_hand = hand;
}

Hand::~Hand(){
}

// Methodes de Pile

std::vector<Carte*> Hand::getPile(){
  return m_hand;
}

void Hand::addPile(Carte* carte){
  m_hand.push_back(carte);
}

void Hand::efface(){
  std::vector<Carte*>::iterator it;
  it = m_hand.begin();
  m_hand.erase(it);
}

void Hand::effacer(int i){
  m_hand.erase(m_hand.begin() + i );
}

void Hand::affiche(){
  for (unsigned long i = 0; i < m_hand.size(); i++) {
      m_hand.at(i)->printCarte();
  }
}

std::vector<Carte*>::iterator Hand::getBegin(){
  return m_hand.begin();
}

std::vector<Carte*>::iterator Hand::getEnd(){
  return m_hand.end();
}

int Hand::taille(){
  return m_hand.size();
}

// Methodes ajoutees

//Permet d'avoir la carte à une position n dans la main
Carte* Hand::getCarte(int n){
  return m_hand.at(n);
}
// Permet d'effacer une carte de son choix dans la main
void Hand::effaceCarte(std::string choix){
  for (unsigned long i = 0; i < m_hand.size(); i++){
    if (choix == m_hand.at(i)->getNom() ){
      effacer(i);
    }
  }
}
