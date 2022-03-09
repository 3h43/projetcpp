#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

class Carte {

	public :

	virtual void setNom(std::string) = 0;
	virtual std::string getNom() const = 0;
	virtual void setType(std::string) = 0;
	virtual std::string getType() = 0;
	virtual void setEngage(bool) = 0;
	virtual bool getEngage() = 0;
	virtual void printCarte() = 0;
	virtual bool getCreature() = 0;
	virtual void setCreature(bool) = 0;
	virtual unsigned long getCoutTerr() = 0;
	virtual std::vector<std::string> getCoutType() = 0;
	bool operator== (const Carte&);
	virtual std::vector<int> compteType() = 0;
	virtual int nbTypes() = 0;

};

#endif
