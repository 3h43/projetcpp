#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "../Headers/Carte.hpp"
#include "../Headers/Terrain.hpp"

Terrain::Terrain(std::string nom, std::string type, bool creature, bool engage, int num ){
  m_nom = nom;
  m_type = type;
  m_isCreature = creature;
  m_engage = engage;
  m_num = num;
}

Terrain::Terrain(){
}

Terrain::~Terrain(){
}

std::string Terrain::getNom() const {
  return m_nom;
}

void Terrain::setNom(std::string nom) {
  m_nom = nom;
}

std::string Terrain::getType() {
  return m_type;
}

void Terrain::setType(std::string type) {
  m_type = type;
}

bool Terrain::getCreature() {
  return m_isCreature;
}

void Terrain::setCreature(bool Terrain) {
  m_isCreature = Terrain;
}

bool Terrain::getEngage() {
  return m_engage;
}

void Terrain::setEngage(bool engage) {
  m_engage = engage;
}

unsigned long Terrain::getCoutTerr(){
  return 10000;
}

std::vector<std::string> Terrain::getCoutType(){
  std::vector<std::string> coutType;
  return coutType;
}

std::vector<int> Terrain::compteType(){
  std::vector<int> comptetype;
  return comptetype;
}

int Terrain::nbTypes(){
  return 0;
}

// Methodes ajoutees


// Permet d'imprimer correctement un terrain
void Terrain::printCarte(){
  if (this->getType() == "R"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;31m▮\033[0m" << " | Engagée : "  << this->getEngage() << " | " << std::endl ;
  }
  if (this->getType() == "B"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;34m▮\033[0m" << " | Engagée : "  << this->getEngage() << " | " <<  std::endl ;
  }
  if (this->getType() == "W"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;37m▮\033[0m" << " | Engagée : "  << this->getEngage() << " | " << std::endl ;
  }
  if (this->getType() == "G"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;32m▮\033[0m" << " | Engagée : "  << this->getEngage() << " | " << std::endl ;
  }
  if (this->getType() == "N"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;90m▮\033[0m" << " | Engagée : "  << this->getEngage() << " | " << std::endl ;
  }
}
