#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "../Headers/Carte.hpp"
#include "../Headers/Cimetiere.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"
#include "../Headers/Deck.hpp"

// Constructeurs

Cimetiere::Cimetiere(){
  std::vector<Carte*> cimetiere;
  m_cimetiere = cimetiere;
}

Cimetiere::~Cimetiere(){
}

// Methodes de Pile

std::vector<Carte*> Cimetiere::getPile(){
  return m_cimetiere;
}

void Cimetiere::addPile(Carte* carte){
  m_cimetiere.push_back(carte);
}

void Cimetiere::efface(){
  std::vector<Carte*>::iterator it;
  it = m_cimetiere.begin();
  m_cimetiere.erase(it);
}

void Cimetiere::affiche(){
  for (Carte* i : m_cimetiere) {
  i->printCarte() ;
  }
}

std::vector<Carte*>::iterator Cimetiere::getBegin(){
  return m_cimetiere.begin();
}

std::vector<Carte*>::iterator Cimetiere::getEnd(){
  return m_cimetiere.end();
}

// Methodes ajoutees
