#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "../Headers/Carte.hpp"

class Creature : public Carte {

	private :

	std::string m_nom;
	std::string m_type;
	bool m_engage;
	bool m_isCreature;
	int m_force;
	int m_endurance;
	int m_coutTerr;
	std::vector<std::string> m_coutType;
	bool m_estbloquee;
	int m_num;
	int m_forcebase;
	int m_endurancebase;
	bool m_vol;
	bool m_portee;

	public :

	Creature(std::string, std::string, bool, bool, int, int, int, std::vector<std::string>, bool, int, bool, bool);
	Creature();
	~Creature();
	bool estBloquee();
	int getForceBase();
	int getEnduranceBase();
	void setBloquee(bool);
	std::string getNom() const;
	void setNom(std::string);
	std::string getType();
	void setType(std::string);
	bool getCreature();
	void setCreature(bool);
	bool getEngage();
	void setEngage(bool);
	int getForce();
	void setForce(int);
	int getEndurance();
	void setEndurance(int);
	unsigned long getCoutTerr();
	void setCoutTerr(int);
	std::vector<std::string> getCoutType();
	void setCoutType(std::vector<std::string>);
	void printCarte();
	std::vector<int> compteType();
	int nbTypes();
	std::string InttoType(int);
	bool getVol();
	bool getPortee();


};

#endif
