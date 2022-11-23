#include "Pokemon.h"

Pokemon::Pokemon()
{
	this->m_numero = 0;
	this->m_type = "None";
	this->m_pv = 0;
	this->m_attaque = 0;
	this->m_attaqueSpe = 0;
	this->m_defense = 0;
	this->m_defenseSpe = 0;
	this->m_vitesse = 0;
	m_capacite1 = new Capacite;
}

void Pokemon::creationPokemon(int numeroPokemon) //Inclure attaque spé et défense spé
{
	switch (numeroPokemon)
	{
	case(197):	//Noctali
		m_numero = numeroPokemon;
		m_type = "Ténèbre";
		m_pv = 95;
		m_attaque = 65;
		m_defense = 110;
		m_vitesse = 65;
		break;

	case(393):	//Tiplouf
		m_numero = numeroPokemon;
		m_type = "Eau";
		m_pv = 53;
		m_attaque = 51;
		m_defense = 53;
		m_vitesse = 40;
		m_capacite1->capaciteCreation(numeroPokemon);
		break;
	default:
		break;
	}
}


void Pokemon::attaquer(Pokemon& victime)
{
	victime.recevoirDegats(m_attaque + m_capacite1->getPuissance());
}

void Pokemon::recevoirDegats(int degats)
{
	m_pv -= (degats - m_defense);
}

//Get

int Pokemon::getpv()
{
	return m_pv;
}