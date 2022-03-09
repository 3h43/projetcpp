#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"

class Terrain : public Carte {

	private :

	std::string m_nom;
	std::string m_type;
	bool m_isCreature;
	bool m_engage;
	int m_num;


	public :

	Terrain(std::string, std::string, bool, bool, int);
	Terrain();
	~Terrain();
	std::string getNom() const;
	void setNom(std::string);
	std::string getType();
	void setType(std::string);
	bool getCreature();
	void setCreature(bool);
	bool getEngage();
	void setEngage(bool);
	void printCarte();
	unsigned long getCoutTerr();
	std::vector<std::string> getCoutType();
	std::vector<int> compteType();
	int nbTypes();
};

#endif
