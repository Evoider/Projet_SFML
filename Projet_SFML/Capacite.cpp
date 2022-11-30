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

	case(40): //Fantominus
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Lechouille";
			m_type = "Ghost";
			m_spe = false;
			m_puissance = 30;
			break;
		case(2):
			m_nom = "Puredpois";
			m_type = "Poison";
			m_spe = true;
			m_puissance = 30;
			break;
		}

	case(60): //Abra
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Téléport";
			m_type = "Psy";
			m_spe = false;
			m_puissance = 0;
			break;
		case(2):
			m_nom = "Vague Psy";
			m_type = "Psy";
			m_spe = true;
			m_puissance = 20;
			break;
		}

	case(147): //Ptéra
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Anti-Air";
			m_type = "Rock";
			m_spe = false;
			m_puissance = 50;
			break;
		case(2):
			m_nom = "Aéropique";
			m_type = "Fire";
			m_spe = false;
			m_puissance = 60;
			break;
		}

	case(155): //Héricendre
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Roulade";
			m_type = "Rock";
			m_spe = false;
			m_puissance = 30;
			break;
		case(2):
			m_nom = "Flammèche";
			m_type = "Fire";
			m_spe = true;
			m_puissance = 40;
			break;
		}

	case(174): //Toudoudou
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Ecras'Face";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;
		case(2):
			m_nom = "Voix Enjoleuse";
			m_type = "Fairy";
			m_spe = true;
			m_puissance = 40;
			break;
		}

	case(175): //Togepi
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Charge";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;
		case(2):
			m_nom = "Vent Feerique";
			m_type = "Fairy";
			m_spe = true;
			m_puissance = 40;
			break;
		}

	case(238): //Lippouti
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Poudreuse";
			m_type = "Ice";
			m_spe = true;
			m_puissance = 40;
			break;
		case(2):
			m_nom = "Lechouille";
			m_type = "Ghost";
			m_spe = false;
			m_puissance = 30;
			break;
		}

	case(246): //Embrylex
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Charge";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;
		case(2):
			m_nom = "Jet-Pierres";
			m_type = "Rock";
			m_spe = false;
			m_puissance = 50;
			break;
		}

	case(248): //Tyranocif 80 et 100
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Vibrobscur";
			m_type = "Dark";
			m_spe = false;
			m_puissance = 80;
			break;
		case(2):
			m_nom = "Lame de Roc";
			m_type = "Rock";
			m_spe = false;
			m_puissance = 100;
			break;
		}

	case(393):	//Tiplouf
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
			m_type = "Water";
			m_spe = true;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

	case(402):	//Crikzik
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Vol-vie";
			m_type = "Grass";
			m_spe = true;
			m_puissance = 20;
			break;

		case(2):
			m_nom = "Survinsecte";
			m_type = "Bug";
			m_spe = true;
			m_puissance = 50;
			break;

		default:
			break;
		}
		break;

	case(406):	//Rozbouton
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Vol-vie";
			m_type = "Grass";
			m_spe = true;
			m_puissance = 25;
			break;

		case(2):
			m_nom = "Mega-sangsue";
			m_type = "Grass";
			m_spe = true;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

	case(417):	//Pachirisu 20 et 40
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Vive-Attaque";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 20;
			break;

		case(2):
			m_nom = "Frotte-Frimousse";
			m_type = "Electric";
			m_spe = false;
			m_puissance = 20;
			break;

		default:
			break;
		}
		break;

	case(442):	//Spiritomb
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Ombre Portee";
			m_type = "Ghost";
			m_spe = false;
			m_puissance = 40;
			break;

		case(2):
			m_nom = "Poursuite";
			m_type = "Dark";
			m_spe = false;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

	case(443):	//Griknot
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
			m_type = "Ground";
			m_spe = true;
			m_puissance = 35;
			break;

		default:
			break;
		}
		break;

	case(444):	//Carmache
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Pietisol";
			m_type = "Ground";
			m_spe = false;
			m_puissance = 60;
			break;

		case(2):
			m_nom = "Draco-Griffe";
			m_type = "Dragon";
			m_spe = false;
			m_puissance = 80;
			break;

		default:
			break;
		}
		break;

	case('447'): //Riolu
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Vive-Attaque";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;

		case(2):
			m_nom = "Eclate-Roc";
			m_type = "Fighting";
			m_spe = false;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

	case('448'): //Lucario
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Luminocanon";
			m_type = "Steel";
			m_spe = true;
			m_puissance = 80;
			break;

		case(2):
			m_nom = "Exploforce";
			m_type = "Fighting";
			m_spe = true;
			m_puissance = 120;
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

std::string Capacite::getType()
{
	return m_type;
}