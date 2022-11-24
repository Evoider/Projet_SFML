#pragma once
#include <string>

class Capacite
{
public:
	Capacite();
	void capaciteCreation(int numeroPokemon, int numeroCapacite);

	//Get
	std::string getNom();
	int getPuissance();

private:
	std::string m_nom;
	std::string m_type;
	bool m_spe;
	int m_puissance;

};