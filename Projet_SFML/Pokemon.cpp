#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{
	this->m_numero = 0;
	this->m_exp = 0;
	this->m_lvl = 1;
	this->m_nom = "None";
	this->m_type1 = "None";
	this->m_type2 = "None";
	this->m_pvMax = 0;
	this->m_pv = 0;
	this->m_attaque = 0;
	this->m_attaqueSpe = 0;
	this->m_defense = 0;
	this->m_defenseSpe = 0;
	this->m_vitesse = 0;
	m_capacite1 = new Capacite;
	m_capacite2 = new Capacite;

	this->m_pvBase = 0;
	this->m_attaqueBase = 0;
	this->m_attaqueSpeBase = 0;
	this->m_defenseBase = 0;
	this->m_defenseSpeBase = 0;
	this->m_vitesseBase = 0;
}

void Pokemon::creationPokemon(int numeroPokemon) //Inclure attaque spé et défense spé
{
	switch (numeroPokemon)
	{
	case(393):	//Tiplouf 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Tiplouf";
		m_type1 = "Eau";
		m_pvBase = m_pvMax = m_pv = 53;
		m_attaqueBase = m_attaque = 51;
		m_attaqueBase = m_attaqueSpe = 61;
		m_defenseBase = m_defense = 53;
		m_defenseSpeBase = m_defenseSpe = 56;
		m_vitesseBase = m_vitesse = 40;
		m_capacite1->capaciteCreation(numeroPokemon,1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(406):	//Rozbouton 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Rozbouton";
		m_type1 = "Plante";
		m_pvBase = m_pvMax = m_pv = 40;
		m_attaqueBase = m_attaque = 30;
		m_attaqueSpeBase = m_attaqueSpe = 35;
		m_defenseBase = m_defense = 50;
		m_defenseSpeBase = m_defenseSpe = 70;
		m_vitesseBase = m_vitesse = 55;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(443):	//Griknot 40 et 35 CHECK
		m_numero = numeroPokemon;
		m_nom = "Griknot";
		m_type1 = "Sol";
		m_type2 = "Dragon";
		m_pvBase = m_pvMax = m_pv = 58;
		m_attaqueBase = m_attaque = 70;
		m_attaqueSpeBase = m_attaqueSpe = 45;
		m_defenseBase = m_defense = 40;
		m_defenseSpeBase = m_defenseSpe = 45;
		m_vitesseBase = m_vitesse = 42;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	default:
		break;
	}
}

void Pokemon::evolutionPokemon(int numeroPokemon)
{
	switch (numeroPokemon)
	{
	case(443):
		numeroPokemon = 444;
		break;

	default:
		break;
	}
}

void Pokemon::expUp(int exp)
{
	m_exp += exp;
	if (m_exp >= m_lvl ^ 3)
	{
		m_exp -= m_lvl ^ 3;
		lvlUp();
	}
}

void Pokemon::lvlUp()
{
	m_lvl++;

	m_pv += ((2*m_pvBase*m_lvl)/100) + m_lvl + 10;
	m_attaque += ((2*m_attaqueBase*m_lvl)/100) + 5;
	m_attaqueSpe += ((2 * m_attaqueSpeBase * m_lvl) / 100) + 5;
	m_defense += ((2 * m_defenseBase * m_lvl) / 100) + 5;
	m_defenseSpe += ((2 * m_defenseSpeBase * m_lvl) / 100) + 5;
	m_vitesse += ((2 * m_vitesseBase * m_lvl) / 100) + 5;
}

void Pokemon::attaquer(Pokemon& victime, int numeroCapacite)
{
	switch (numeroCapacite)
	{
	case(1):
		if (m_capacite1->getSpe() == true)
		{
			victime.recevoirDegats(m_attaqueSpe + m_capacite1->getPuissance() - victime.getDefense());
		}
		else
		{
			victime.recevoirDegats(m_attaque + m_capacite1->getPuissance() - victime.getDefense());
		}
		break;

	case(2):
		if (m_capacite2->getSpe() == true)
		{
			victime.recevoirDegats(m_attaqueSpe + m_capacite2->getPuissance() - victime.getDefense());
		}
		else
		{
			victime.recevoirDegats(m_attaque + m_capacite2->getPuissance() - victime.getDefense());
		}
		break;

	default:
		break;
	}
}

void Pokemon::recevoirDegats(int degats)
{
	if (degats< 0)
	{
		std::cout << "L'attaque est negatif" << std::endl;
		m_pv--;
	}
	else
	{
		m_pv -= (degats);
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

//Set
void Pokemon::healMax()
{
	m_pv = m_pvMax;
}

//checkResistance
float Pokemon::resistance(Pokemon& victime)
{

}