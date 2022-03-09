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
#include "../Headers/Plateau.hpp"


// Constructeurs

Plateau::Plateau(){
  std::vector<Carte*> plateau;
  m_plateau = plateau;
}

Plateau::~Plateau(){
}

// Methodes de Pile

std::vector<Carte*> Plateau::getPile(){
  return m_plateau;
}

void Plateau::addPile(Carte* carte){
  m_plateau.push_back(carte);
}

void Plateau::efface(){
  std::vector<Carte*>::iterator it;
  it = m_plateau.begin();
  m_plateau.erase(it);
}

void Plateau::effaceCreature(Creature* creature){
  int m = 0;
  for (Carte* c : m_plateau){
    if (c->getNom() == creature->getNom()){
      m_plateau.erase(m_plateau.begin() + m);
    }
    m +=1;
  }
}

void Plateau::affiche(){
  for (Carte* i : m_plateau) {
  i->printCarte() ;
  }
}

std::vector<Carte*>::iterator Plateau::getBegin(){
  return m_plateau.begin();
}

std::vector<Carte*>::iterator Plateau::getEnd(){
  return m_plateau.end();
}

// Methodes ajoutees

// Permet de compter les terrains sur un plateau en fonction de leur type, renvoie un vecteur de la forme (0,0,0,1,0) si on n'a qu'un terrain Vert sur le plateau
std::vector<int> Plateau::compteTerrains(){
  int r = 0;
  int b = 0;
  int w = 0;
  int g = 0;
  int n = 0;
  std::vector<int> nbTerrains;
  for (Carte* i : m_plateau){
    if (i->getCreature() == false && i->getEngage() == false){
      if (i->getType() == "R") { r = r + 1;}
      if (i->getType() == "B") { b = b + 1;}
      if (i->getType() == "W") { w = w + 1;}
      if (i->getType() == "G") { g = g + 1;}
      if (i->getType() == "N") { n = n + 1;}
      }
    }
    nbTerrains.push_back(r);
    nbTerrains.push_back(b);
    nbTerrains.push_back(w);
    nbTerrains.push_back(g);
    nbTerrains.push_back(n);
    return nbTerrains;
}

// Renvoie la carte à la position donnée i
  Carte* Plateau::position(int pos){
  return m_plateau.at(pos);
}

// Compte le nombre de terrains sur le plateau
int Plateau::nbTerrains(){
  int total = 0;
  for (unsigned long i = 0; i < 5 ; i ++){
    total += compteTerrains().at(i);
  }
  return total;
}
