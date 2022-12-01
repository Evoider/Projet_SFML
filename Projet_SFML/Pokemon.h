#pragma once
#include "Capacite.h"
#include <string>

class Pokemon
{
public:
	Pokemon();
	void creationPokemon(int numeroPokemon);
	void evolutionPokemon(int numeroPokemon);
	void expUp(int exp);
	void lvlUp();
	void attaquer(Pokemon& victime, int numeroCapacite);
	void recevoirDegats(int degats);

	//Get
	std::string getNom();
	int getPv();
	int getLvl();
	int getDefense();
	int getDefenseSpe();
	int getVitesse();
	std::string getType1();
	std::string getType2();
	std::string getCapacite1();
	std::string getCapacite2();

	//Set
	void healMax();

	//checkResistance
	float resistance(Pokemon& victime, Capacite& capacity);

private:
	int m_numero;
	std::string m_nom;
	int m_exp;
	int m_lvl;
	std::string m_type1;
	std::string m_type2;
	int m_pvMax;
	int m_pv;
	int m_attaque;
	int m_attaqueSpe;
	int m_defense;
	int m_defenseSpe;
	int m_vitesse;

	Capacite* m_capacite1;
	Capacite* m_capacite2;

	int m_pvBase;
	int m_vitesseBase;
	int m_attaqueBase;
	int m_attaqueSpeBase;
	int m_defenseBase;
	int m_defenseSpeBase;

};