#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"
#include "../Headers/Bibliotheque.hpp"


// Constructeurs

Bibliotheque::Bibliotheque(){
  std::vector<Carte*> bibliotheque;
  m_bibliotheque = bibliotheque;
}

Bibliotheque::~Bibliotheque(){
}

// Methodes de Pile

std::vector<Carte*> Bibliotheque::getPile(){
  return m_bibliotheque;
}

void Bibliotheque::addPile(Carte* carte){
  m_bibliotheque.push_back(carte);
}

void Bibliotheque::affiche(){
  for (Carte* i : m_bibliotheque) {
  i->printCarte() ;
  }
}

void Bibliotheque::efface(){
  std::vector<Carte*>::iterator it;
  it = m_bibliotheque.begin();
  m_bibliotheque.erase(it);
}

std::vector<Carte*>::iterator Bibliotheque::getBegin(){
  return m_bibliotheque.begin();
}

std::vector<Carte*>::iterator Bibliotheque::getEnd(){
  return m_bibliotheque.end();
}

// Methodes ajoutees

Carte* Bibliotheque::pioche(){
  return m_bibliotheque.at(0);
}
