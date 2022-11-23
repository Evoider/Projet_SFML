#pragma once
#include <string>

class Capacite
{
public:
	Capacite();
	void capaciteCreation(int numeroPokemon);

	//Get
	int getPuissance();

private:
	std::string m_nom;
	std::string m_type;
	bool m_spe;
	int m_puissance;

};