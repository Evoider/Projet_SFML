#include "Capacite.h"

Capacite::Capacite()
{
	this->m_nom = "None";
	this->m_type = "None";
	this->m_spe = false;
	this->m_puissance = 0;
}

void Capacite::capaciteCreation(int numeroPokemon)
{
	switch (numeroPokemon)
	{
	case(393):
		m_nom = "Bulles d'O";
		m_type = "Eau";
		m_spe = true;
		m_puissance = 65;
		break;

	default:
		break;
	}
}

int Capacite::getPuissance()
{
	return m_puissance;
}
