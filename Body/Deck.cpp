#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Pile.hpp"
#include "../Headers/Deck.hpp"

// Constructeurs

Deck::Deck() {
  std::vector<Carte*> deck;
  m_deck = deck;
}

Deck::~Deck(){
}

// Methodes de Pile

std::vector<Carte*> Deck::getPile(){
  return m_deck;
}

void Deck::addPile(Carte* carte){
  m_deck.push_back(carte);
}

void Deck::affiche(){
  for (unsigned long i = 0; i < m_deck.size(); i++) {
      m_deck.at(i)->printCarte();
  }
}

void Deck::efface(){
  std::vector<Carte*>::iterator it;
  it = m_deck.begin();
  m_deck.erase(it);
}

std::vector<Carte*>::iterator Deck::getBegin(){
  return m_deck.begin();
}

std::vector<Carte*>::iterator Deck::getEnd(){
  return m_deck.end();
}

// Methodes ajoutees
