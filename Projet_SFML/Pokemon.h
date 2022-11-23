#pragma once
#include "Capacite.h"
#include <string>

class Pokemon
{
public:
	Pokemon();
	void creationPokemon(int numeroPokemon);
	void attaquer(Pokemon& victime);
	void recevoirDegats(int degats);

	//Get
	int getpv();

private:
	int m_numero;
	std::string m_type;
	int m_pv;
	int m_vitesse;
	int m_attaque;
	int m_attaqueSpe;
	int m_defense;
	int m_defenseSpe;

	Capacite* m_capacite1;

};