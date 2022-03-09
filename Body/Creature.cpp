#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "../Headers/Carte.hpp"
#include "../Headers/Creature.hpp"

// Constructeurs

Creature::Creature(std::string nom, std::string type, bool creature, bool engage, int force, int endurance, int coutTerr, std::vector<std::string> coutType, bool bloquee , int num, bool vol, bool portee) {
  m_nom = nom;
  m_type = type;
  m_isCreature = creature;
  m_engage = engage;
  m_force = force;
  m_endurance = endurance;
  m_coutTerr = coutTerr; // Correspond au coût en terrains que l'on peut choisir arbitrairement (1,2,3...)
  m_coutType = coutType; // Correspond au coût en terrains que l'on ne peut pas choisir arbitrairement (2 plaines pour l'Ange de Serra par exemple)
  m_estbloquee = bloquee;
  m_num = num;
  m_forcebase = force;
  m_endurancebase = endurance;
  m_vol = vol;
  m_portee = portee;
}

Creature::Creature(){
}

Creature::~Creature(){
}

// Methodes de base

bool Creature::getVol() {
  return m_vol;
}

bool Creature::getPortee(){
  return m_portee;
}

bool Creature::estBloquee() {
  return m_estbloquee;
}

int Creature::getForceBase(){
  return m_forcebase;
}

int Creature::getEnduranceBase(){
  return m_endurancebase;
}

void Creature::setBloquee(bool bloquee){
  m_estbloquee = bloquee;
}

std::string Creature::getNom() const {
  return m_nom;
}

void Creature::setNom(std::string nom) {
  m_nom = nom;
}

std::string Creature::getType() {
  return m_type;
}

void Creature::setType(std::string type) {
  m_type = type;
}

bool Creature::getCreature() {
  return m_isCreature;
}

void Creature::setCreature(bool creature) {
  m_isCreature = creature;
}

bool Creature::getEngage() {
  return m_engage;
}

void Creature::setEngage(bool engage) {
  m_engage = engage;
}

int Creature::getForce() {
  return m_force;
}

void Creature::setForce(int force) {
  m_force = force;
}

int Creature::getEndurance() {
  return m_endurance;
}

void Creature::setEndurance(int endurance) {
  m_endurance = endurance;
}

unsigned long Creature::getCoutTerr() {
  return m_coutTerr;
}

void Creature::setCoutTerr(int cout) {
  m_coutTerr = cout;
}

std::vector<std::string> Creature::getCoutType() {
  return m_coutType;
}

void Creature::setCoutType(std::vector<std::string> cout){
  m_coutType = cout;
}

// Methodes ajoutees

//Permet d'afficher correctement une carte de type créature dans la console.
void Creature::printCarte(){
  if (this->getType() == "R"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;31m▮\033[0m" << " | Engagée : " << this->getEngage() << " | Force/Endurance : " << this->getForce() << "/" << this->getEndurance() << " | " << "Types arbitraires : " << this->getCoutTerr() << " | " << std::endl ;
  }
  if (this->getType() == "B"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;34m▮\033[0m" << " | Engagée : " << this->getEngage() << " | Force/Endurance : " << this->getForce() << "/" << this->getEndurance() << " | " << "Types arbitraires : " << this->getCoutTerr() << " | " << std::endl ;
  }
  if (this->getType() == "W"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;37m▮\033[0m" << " | Engagée : " << this->getEngage() << " | Force/Endurance : " << this->getForce() << "/" << this->getEndurance() << " | " << "Types arbitraires : " << this->getCoutTerr() << " | " << std::endl ;
  }
  if (this->getType() == "G"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;32m▮\033[0m" << " | Engagée : " << this->getEngage() << " | Force/Endurance : " << this->getForce() << "/" << this->getEndurance() << " | " << "Types arbitraires : " << this->getCoutTerr() << " | " << std::endl ;
  }
  if (this->getType() == "N"){
  std::cout << "Nom : " << this->getNom() << " | Type : " << "\033[1;90m▮\033[0m" << " | Engagée : " << this->getEngage() << " | Force/Endurance : " << this->getForce() << "/" << this->getEndurance() << " | " << "Types arbitraires : " << this->getCoutTerr() << " | " << std::endl ;
  }

}
//Permet de créer un vecteur de Integer de taille 5, chaque fois qu'un type est reconnu on ajoute 1 à la position associée
std::vector<int> Creature::compteType(){
  int r = 0;
  int b = 0;
  int w = 0;
  int g = 0;
  int n = 0;
  std::vector<int> nbTypes;
  for (unsigned long i = 0; i < m_coutType.size(); i++){
    if (m_isCreature){
      if (m_coutType.at(i) == "R") { r = r + 1;}
      if (m_coutType.at(i) == "B") { b = b + 1;}
      if (m_coutType.at(i) == "W") { w = w + 1;}
      if (m_coutType.at(i) == "G") { g = g + 1;}
      if (m_coutType.at(i) == "N") { n = n + 1;}
      }
    }
    nbTypes.push_back(r);
    nbTypes.push_back(b);
    nbTypes.push_back(w);
    nbTypes.push_back(g);
    nbTypes.push_back(n);
    return nbTypes;
}

//Permet, à partir d'une position dans le vecteur de compteType, de trouver le type auquel la position est associée
std::string Creature::InttoType(int i){
    if ( i == 0 ) { return "R";}
    if ( i == 1 ) { return "B";}
    if ( i == 2 ) { return "W";}
    if ( i == 3 ) { return "G";}
    if ( i == 4 ) { return "N";}
    return "raté";
}

//Permet de compter le nombre de types "obligatoires" d'une créature
int Creature::nbTypes(){
  int total = 0;
  for (unsigned long i = 0; i < m_coutType.size() ; i ++){
    total += compteType().at(i);
  }
  return total + m_coutTerr;
}
