#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{
	this->m_numero = 0;
	this->m_nom = "None";
	this->m_type1 = "None";
	this->m_type2 = "None";
	this->m_pv = 0;
	this->m_attaque = 0;
	this->m_attaqueSpe = 0;
	this->m_defense = 0;
	this->m_defenseSpe = 0;
	this->m_vitesse = 0;
	m_capacite1 = new Capacite;
	m_capacite2 = new Capacite;
}

void Pokemon::creationPokemon(int numeroPokemon) //Inclure attaque spé et défense spé
{
	switch (numeroPokemon)
	{
	case(393):	//Tiplouf
		m_numero = numeroPokemon;
		m_nom = "Tiplouf";
		m_type1 = "Eau";
		m_pv = 53;
		m_attaque = 51;
		m_defense = 53;
		m_vitesse = 40;
		m_capacite1->capaciteCreation(numeroPokemon,1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(443):	//Griknot
		m_numero = numeroPokemon;
		m_nom = "Griknot";
		m_type1 = "Sol";
		m_type2 = "Dragon";
		m_pv = 53;
		m_attaque = 70;
		m_attaqueSpe = 45;
		m_defense = 40;
		m_defenseSpe = 45;
		m_vitesse = 42;
		break;

	default:
		break;
	}
}


void Pokemon::attaquer(Pokemon& victime, int numeroCapacite)
{
	switch (numeroCapacite)
	{
	case(1):
		victime.recevoirDegats(m_attaque + m_capacite1->getPuissance());
		break;

	case(2):
		victime.recevoirDegats(m_attaque + m_capacite2->getPuissance());
		break;

	default:
		break;
	}
}

void Pokemon::recevoirDegats(int degats)
{
	if (degats - m_defense < 0)
	{
		std::cout << "L'attaque est negatif" << std::endl;
		m_pv--;
	}
	else
	{
		m_pv -= (degats - m_defense);
	}
}

//Get

std::string Pokemon::getNom()
{
	return m_nom;
}

int Pokemon::getPv()
{
	return m_pv;
}

int Pokemon::getDefense()
{
	return m_defense;
}

int Pokemon::getVitesse()
{
	return m_vitesse;
}

std::string Pokemon::getCapacite1()
{
	return m_capacite1->getNom();
}

std::string Pokemon::getCapacite2()
{
	return m_capacite2->getNom();
}