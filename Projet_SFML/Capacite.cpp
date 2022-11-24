#include "Capacite.h"

Capacite::Capacite()
{
	this->m_nom = "None";
	this->m_type = "None";
	this->m_spe = false;
	this->m_puissance = 0;
}

void Capacite::capaciteCreation(int numeroPokemon, int numeroCapacite)
{
	switch (numeroPokemon)
	{
	case(393):
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Ecras'Face";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;

		case(2):
			m_nom = "Bulles d'O";
			m_type = "Eau";
			m_spe = true;
			m_puissance = 65;
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}
}

//Get

std::string Capacite::getNom()
{
	return m_nom;
}

int Capacite::getPuissance()
{
	return m_puissance;
}
