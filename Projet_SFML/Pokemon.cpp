#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{
	this->m_numero = 0;
	this->m_nom = "None";
	this->m_type = "None";
	this->m_pv = 0;
	this->m_attaque = 0;
	this->m_attaqueSpe = 0;
	this->m_defense = 0;
	this->m_defenseSpe = 0;
	this->m_vitesse = 0;
	m_capacite1 = new Capacite;
	m_capacite2 = new Capacite;
}

void Pokemon::creationPokemon(int numeroPokemon) //Inclure attaque sp� et d�fense sp�
{
	switch (numeroPokemon)
	{
	case(197):	//Noctali
		m_numero = numeroPokemon;
		m_nom = "Noctali";
		m_type = "T�n�bre";
		m_pv = 95;
		m_attaque = 65;
		m_defense = 110;
		m_vitesse = 65;
		break;

	case(393):	//Tiplouf
		m_numero = numeroPokemon;
		m_nom = "Tiplouf";
		m_type = "Eau";
		m_pv = 53;
		m_attaque = 51;
		m_defense = 53;
		m_vitesse = 40;
		m_capacite1->capaciteCreation(numeroPokemon,1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
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

std::string Pokemon::getCapacite1()
{
	return m_capacite1->getNom();
}

std::string Pokemon::getCapacite2()
{
	return m_capacite2->getNom();
}