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
			m_nom = "Ecume";
			m_type = "Eau";
			m_spe = true;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

	case(406):
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Vol-vie";
			m_type = "Plante";
			m_spe = true;
			m_puissance = 25;
			break;

		case(2):
			m_nom = "Mega-sangsue";
			m_type = "Plante";
			m_spe = true;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

	case(443):
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Charge";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;

		case(2):
			m_nom = "Tourbi-sable";
			m_type = "Sol";
			m_spe = true;
			m_puissance = 35;
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

bool Capacite::getSpe()
{
	return m_spe;
}
