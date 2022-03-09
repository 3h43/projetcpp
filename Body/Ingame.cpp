#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "../Headers/Ingame.hpp"
#include "../Headers/Carte.hpp"
#include "../Headers/Bibliotheque.hpp"
#include "../Headers/Cimetiere.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Deck.hpp"
#include "../Headers/Joueur.hpp"
#include "../Headers/Pile.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Hand.hpp"

// Constructeurs

Ingame::Ingame(Joueur* joueur1, Joueur* joueur2){
  m_joueur1 = joueur1;
  m_joueur2 = joueur2;
}

Ingame::Ingame(){
}

Ingame::~Ingame(){
}

// Methodes de base

Joueur* Ingame::getJoueur1(){
  return m_joueur1;
}

void Ingame::setJoueur1(Joueur* joueur){
  m_joueur1 = joueur;
}

Joueur* Ingame::getJoueur2(){
  return m_joueur2;
}

void Ingame::setJoueur2(Joueur* joueur){
  m_joueur2 = joueur;
}

// Methodes ajoutees


//Cette méthode est celle correspondant à un joueur choisissant les cratures avec lesquelles il veut attaquer
std::vector<Creature*> Ingame::ChoixAttaque(Joueur* joueur){
  std::vector<Creature*> CreaturesChoisiesAttaque;
  std::string reponse = "";
  std::string reponse2 = "";
  std::cout << " " << std::endl;
  std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
  std::cout << "———————————————————————————PHASE D'ATTAQUE——————————————————————————————— " << std::endl;
  std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "> "<< joueur->getPseudo() << ", voulez-vous attaquer ? y|n" << std::endl;
  std::cin >> reponse;
  if (reponse == "y"){
    CreaturesChoisiesAttaque.push_back(joueur->choixCreature());
    std::cout << "> Voulez-vous choisir une autre créature pour attaquer ? y|n" << std::endl;
    std::cin >> reponse2;
    while (reponse2 == "y") {
      reponse2 = "";
      Creature* creature = joueur->choixCreature();
      CreaturesChoisiesAttaque.push_back(creature);
      creature->setEngage(true);
      std::cout << "> Voulez-vous choisir une autre créature pour attaquer ? y|n" << std::endl;
      std::cin >> reponse2;
      if (reponse2 == "n"){ break;}
      }
    std::cout << "> Vous avez choisi les créatures avec lesquelles vous allez attaquer " << std::endl;
    std::cout << "> Voici votre plateau : " << std::endl;
    joueur->affichePlateau();
  }
  else {
    std::cout << "> Pas d'attaque pour " << joueur->getPseudo() << std::endl;
  }
  std::cout << "> Fin de la phase d'attaque pour " << joueur->getPseudo() << ". Début de la phase de défense"<< std::endl;
  return CreaturesChoisiesAttaque;
}

//Cette méthode est celle correspondant à un joueur choisissant les cratures avec lesquelles il veut défendre
std::vector<Creature*> Ingame::ChoixDefense(Joueur* joueur){
  std::vector<Creature*> CreaturesChoisiesDef;
  std::string reponse = "";
  std::string reponse2 = "";
  std::cout << " " << std::endl;
  std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
  std::cout << "———————————————————————————PHASE DE DEFENSE—————————————————————————————— " << std::endl;
  std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "> " << joueur->getPseudo() << " peut commencer sa défense. Voulez-vous défendre ? y|n "<< std::endl;
  std::cin >> reponse;
  if (reponse == "y"){
      CreaturesChoisiesDef.push_back(joueur->choixCreature());
      std::cout << "> Voulez-vous choisir une autre créature pour défendre ? y|n" << std::endl;
      std::cin >> reponse2;
      while (reponse2 == "y") {
        reponse2 = "";
        Creature* creature = joueur->choixCreature();
        CreaturesChoisiesDef.push_back(creature);
        creature->setEngage(true);
        std::cout << "> Voulez-vous choisir une autre créature pour défendre ? y|n" << std::endl;
        std::cin >> reponse2;
        if (reponse2 == "n"){
          break;
          }
      }
      std::cout << "> Vous avez choisi les créatures avec lesquelles vous défendez" << std::endl;
      std::cout << "> Voici votre plateau : | Les créatures défendant sont engagées" << std::endl;
      joueur->affichePlateau();
  }
  else {
  std::cout << "> Pas de défense, vous prenez tout en pleine poire!" << std::endl;
  }
  return CreaturesChoisiesDef;
}

//Cette méthode est la méthode principale de la phase de combat, elle fait appel aux méthodes ChoixAttaque et ChoixDéfense ainsi qu'à un vecteur OrdreDef qui est un vecteur de paires (Creature*, int).
//Il contient les créatures qui défendent et sur quelles cartes elles défendent.
void Ingame::Combat(Joueur* joueur1, Joueur* joueur2){
  std::vector<Creature*> CreaturesChoisiesAttaque;
  std::vector<Creature*> CreaturesChoisiesDef;
  std::vector<std::pair<Creature*, int>> OrdreDef;

  CreaturesChoisiesAttaque = ChoixAttaque(joueur1);
  if (CreaturesChoisiesAttaque.size() != 0 ){

  CreaturesChoisiesDef = ChoixDefense(joueur2);
  for (Creature* c : CreaturesChoisiesDef){
    std::cout << "> Sur quelle créature " << c->getNom() << " doit-elle défendre ? Voici les créatures attaquant :" << std::endl;
    for (Creature* c : CreaturesChoisiesAttaque){
      c->printCarte();
      }
    std::cout << "> Choisissez un nombre entre 1 et " << CreaturesChoisiesAttaque.size() << std::endl;
    unsigned long ordre;
    std::cin >> ordre;
    if (ordre >= 1 && ordre <= CreaturesChoisiesAttaque.size()){
      CreaturesChoisiesAttaque.at(ordre -1)->setBloquee(true);
      OrdreDef.push_back(std::make_pair(c, ordre-1));
      }
    else {
      std::cout << "> Le chiffre n'est pas bon" << std::endl;
      }
    }

  std::vector<int> toutesCreaBloq;
  std::cout << "> Voici votre défense : " << std::endl;
  for (std::pair<Creature*,int> p : OrdreDef){
    std::cout << p.first->getNom() << " défend sur " << CreaturesChoisiesAttaque.at(p.second)->getNom() << std::endl;
    toutesCreaBloq.push_back(p.second);
    }

  // Phase d'attaque en tant que telle:

  //Si la creature n'est pas bloquée : le joueur prend les dégats
  for (Creature* p : CreaturesChoisiesAttaque){
    if ( p->estBloquee() == false ){
      joueur2->setPV(joueur2->getPV() - p->getForce());
      }
    }

  //Sinon, si la créature en attaque ne sont bloquées que par au maximum une seule autre créature
  auto i1 = std::adjacent_find(toutesCreaBloq.begin(), toutesCreaBloq.end());

  if (i1 == toutesCreaBloq.end()) {
     std::cout << "> Pas de défense OU toutes les créatures en attaque sont bloquées par une seule créature en défense" << std::endl;
     for (std::pair<Creature*,int> p : OrdreDef){
         if (CreaturesChoisiesAttaque.at(p.second)->getVol()){
           if (p.first->getVol() || p.first->getPortee()){
             CreaturesChoisiesAttaque.at(p.second)->setEndurance(CreaturesChoisiesAttaque.at(p.second)->getEndurance() - p.first->getForce());
             p.first->setEndurance(p.first->getEndurance() - CreaturesChoisiesAttaque.at(p.second)->getForce());
           }
           else {
             joueur2->setPV(joueur2->getPV() - CreaturesChoisiesAttaque.at(p.second)->getForce());
           }
         }
         else {
           CreaturesChoisiesAttaque.at(p.second)->setEndurance(CreaturesChoisiesAttaque.at(p.second)->getEndurance() - p.first->getForce());
           p.first->setEndurance(p.first->getEndurance() - CreaturesChoisiesAttaque.at(p.second)->getForce());
         }
         if (p.first->getEndurance() <= 0) {
           joueur2->addCimetiere(p.first);
           std::cout << "> Votre carte " << p.first->getNom() << " a été mise au cimetière" << std::endl;
         }
         if (CreaturesChoisiesAttaque.at(p.second)->getEndurance() <= 0) {
           joueur1->addCimetiere(CreaturesChoisiesAttaque.at(p.second));
           std::cout << "> Votre carte " << CreaturesChoisiesAttaque.at(p.second)->getNom() << " a été mise au cimetière" << std::endl;
         }
     }
  }
  //Sinon, si la ou les créatures en attaque sont bloquées par plusieurs autre créatures
  else {
       std::cout << "> Une ou plusieurs créatures en attaque sont bloquées par plusieurs créatures en défense " << std::endl;
       // On crée duplicates, qui est un vecteur de paires de (int, vecteur<Créatures*>), chaque créature défend sur une "position" entre 1 et la taille du vecteur OrdreDef, on parcourt Ordre Def et si on voit que plusieurs Créatures
       // Défendent sur une même position on les réunis dans le vecteur de créatures associé à cette même position.
       // Cela permet de laisser le joueur choisir l'ordre
       std::vector<std::pair<int, std::vector<Creature*>>> duplicates;
       std::sort(OrdreDef.begin(), OrdreDef.end()); // On trie OrdreDef pour ne pas avoir quelque chose du genre (C1,1)(C2,2)(C3,1) etc.. On met toutes les créatures qui défendent sur la même créature les unes à cotés des autres pour ne pas avoir à revenir en arrière tout le temps
       int m = -1; // m est une valeur tampon dans laquelle on stocke les positions, elle sert à directement ajouter les Créatures si elles défendent sur la même position. Si m diffère alors on crée un nouveau vecteur pour faire une nouvelle paire à ajouter au vecteur duplicates
       for (unsigned long i = 0 ; i < OrdreDef.size(); i++){
         if (OrdreDef.at(i).second != m){
         std::vector<Creature*> positions;
         positions.push_back(OrdreDef.at(i).first);
         for (unsigned long j = 1 ; j < OrdreDef.size() ; j++){
           if (OrdreDef.at(i).second == OrdreDef.at(j).second){
             positions.push_back(OrdreDef.at(j).first);
           }
         }
         duplicates.push_back(std::make_pair(i, positions)); // duplicates a donc la forme [(1,(C1,C3,C4)), (2, (C5,C7,C8,C9))...] C1,C2,C3,C4 défendent sur la créature à la place 1, C5,C7,C8,C9 sur celle à la position 2..
         m = OrdreDef.at(i).second;
        }
       }

       for (unsigned long k = 0; k < duplicates.size(); k++){
         std::vector<Creature*> ordreAttaque;
         if (duplicates.at(k).second.size() > 1){
           std::cout << "> " << joueur1->getPseudo() << " votre créature " << CreaturesChoisiesAttaque.at(duplicates.at(k).first)->getNom() << " est bloquée par : " << std::endl;
           for (unsigned long u = 0 ; u < duplicates.at(k).second.size(); u ++){
             std::cout << duplicates.at(k).second.at(u)->getNom() << " | " ;
           }


           std::cout << "> Choisissez l'ordre dans lequel vous voulez attaquer" << std::endl;
// On crée un vecteu ordre attaque à partir de duplicates, comme ça on choisit parmi les paires, pour chaque créature attaquant, l'ordre dans lequel elle veut attaquer.
           for (unsigned long s = 0; s < duplicates.at(k).second.size(); s++){
             std::string choix;
             std::cin >> choix;
             for (Creature* c : duplicates.at(k).second){
               if (choix == c->getNom()){
                 ordreAttaque.push_back(c);
               }
             }
           }
           for (Creature* c : ordreAttaque){
             int endurancePerdue = CreaturesChoisiesAttaque.at(duplicates.at(k).first)->getForce();
             CreaturesChoisiesAttaque.at(duplicates.at(k).first)->setEndurance(CreaturesChoisiesAttaque.at(duplicates.at(k).first)->getEndurance() - c->getForce());
             c->setEndurance(c->getEndurance() - CreaturesChoisiesAttaque.at(duplicates.at(k).first)->getForce());
             CreaturesChoisiesAttaque.at(duplicates.at(k).first)->setForce(CreaturesChoisiesAttaque.at(duplicates.at(k).first)->getForce() - endurancePerdue);
             if (CreaturesChoisiesAttaque.at(duplicates.at(k).first)->getEndurance() <= 0 ){
               joueur1->addCimetiere(CreaturesChoisiesAttaque.at(duplicates.at(k).first));
             }
             if (c->getEndurance() <= 0 ){
               joueur2->addCimetiere(c);
               std::cout << "> Votre carte " << c->getNom() << " a été mise au cimetière" << std::endl;
             }
           }
         }
       }
     }
   }
   else {
     std::cout << "Il n'y a pas de créature en attaque, pas besoin de défendre" << std::endl;
   }

     std::cout << " " << std::endl;
     std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
     std::cout << "——————————————————————————————FIN DU COMBAT—————————————————————————————— " << std::endl;
     std::cout << "————————————————————————————————————————————————————————————————————————— " << std::endl;
     std::cout << " " << std::endl;
     std::cout << "> Voici le plateau de " << joueur1->getPseudo() << ": " << std::endl;
     joueur1->affichePlateau();
     std::cout << "> Voici le plateau de " << joueur2->getPseudo() << ": " << std::endl;
     joueur2->affichePlateau();
}
