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

	case(39): //Rondoudou
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Chant Canon";
			m_type = "Normal";
			m_spe = true;
			m_puissance = 60;
			break;
		case(2):
			m_nom = "Réveil Forcé";
			m_type = "Combat";
			m_spe = false;
			m_puissance = 70;
			break;

		default:
			break;
		}
		break;

	case(40): //Grodoudou
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Mégaphone";
			m_type = "Normal";
			m_spe = true;
			m_puissance = 90;
			break;
		case(2):
			m_nom = "Calinerie";
			m_type = "Fairy";
			m_spe = false;
			m_puissance = 90;
			break;

		default:
			break;
		}
		break;

	case(63): //Abra
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

		default:
			break;
		}
		break;

	case(64): //Kadabra
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Coupe Psycho";
			m_type = "Psy";
			m_spe = false;
			m_puissance = 70;
			break;
		case(2):
			m_nom = "Rafale Psy";
			m_type = "Psy";
			m_spe = true;
			m_puissance = 65;
			break;

		default:
			break;
		}
		break;

	case(65): //Alakazam
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Devoreve";
			m_type = "Psy";
			m_spe = true;
			m_puissance = 100;
			break;
		case(2):
			m_nom = "Psycho";
			m_type = "Psy";
			m_spe = true;
			m_puissance = 90;
			break;

		default:
			break;
		}
		break;

	case(81): //Magnéti
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Charge";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;
		case(2):
			m_nom = "Eclair";
			m_type = "Electric";
			m_spe = true;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

	case(82): //Magnéton
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Etincelle";
			m_type = "Electric";
			m_spe = false;
			m_puissance = 65;
			break;
		case(2):
			m_nom = "Miroi-Tir";
			m_type = "Steel";
			m_spe = true;
			m_puissance = 65;
			break;

		default:
			break;
		}
		break;

	case(92): //Fantominus
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

		default:
			break;
		}
		break;

	case(93): //Spectrum
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Poing Ombre";
			m_type = "Ghost";
			m_spe = false;
			m_puissance = 60;
			break;
		case(2):
			m_nom = "Choc Venin";
			m_type = "Poison";
			m_spe = true;
			m_puissance = 65;
			break;

		default:
			break;
		}
		break;

	case(94): //Ectoplasma
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Ball'Ombre";
			m_type = "Ghost";
			m_spe = true;
			m_puissance = 80;
			break;
		case(2):
			m_nom = "Bomb Beurk";
			m_type = "Poison";
			m_spe = true;
			m_puissance = 90;
			break;

		default:
			break;
		}
		break;

	case(118): //Poissirene
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Picpic";
			m_type = "Fly";
			m_spe = false;
			m_puissance = 50;
			break;
		case(2):
			m_nom = "Siphon";
			m_type = "Water";
			m_spe = true;
			m_puissance = 60;
			break;

		default:
			break;
		}
		break;

	case(119): //Poissoroy
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Cascade";
			m_type = "Water";
			m_spe = false;
			m_puissance = 80;
			break;
		case(2):
			m_nom = "Laser Glace";
			m_type = "Ice";
			m_spe = true;
			m_puissance = 90;
			break;

		default:
			break;
		}
		break;

	case(124): //Lippoutou
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Psyko";
			m_type = "Psy";
			m_spe = true;
			m_puissance = 90;
			break;
		case(2):
			m_nom = "Laser Glace";
			m_type = "Ice";
			m_spe = true;
			m_puissance = 90;
			break;

		default:
			break;
		}
		break;

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
			m_type = "Fly";
			m_spe = false;
			m_puissance = 60;
			break;

		default:
			break;
		}
		break;

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

		default:
			break;
		}
		break;

	case(156): //Feurisson
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Roue de feu";
			m_type = "Fire";
			m_spe = false;
			m_puissance = 60;
			break;
		case(2):
			m_nom = "Nitrocharge";
			m_type = "Fire";
			m_spe = false;
			m_puissance = 50;
			break;
		default:
			break;
		}
		break;

	case(157): //Typhlosion
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Feu d'enfer";
			m_type = "Fire";
			m_spe = true;
			m_puissance = 100;
			break;
		case(2):
			m_nom = "Lance-Flammes";
			m_type = "Fire";
			m_spe = true;
			m_puissance = 90;
			break;
		default:
			break;
		}
		break;

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

		default:
			break;
		}
		break;

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

		default:
			break;
		}
		break;

	case(176): //Togetic
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Tranch'air";
			m_type = "Fly";
			m_spe = true;
			m_puissance = 60;
			break;
		case(2):
			m_nom = "Vampibaiser";
			m_type = "Fairy";
			m_spe = true;
			m_puissance = 50;
			break;

		default:
			break;
		}
		break;

	case(215): //Farfuret
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Griffe";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;
		case(2):
			m_nom = "Eclats Glace";
			m_type = "Ice";
			m_spe = false;
			m_puissance = 40;
			break;

		default:
			break;
		}
		break;

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

		default:
			break;
		}
		break;

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

		default:
			break;
		}
		break;

	case(247): //Ymphect
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Trépignement";
			m_type = "Ground";
			m_spe = false;
			m_puissance = 75;
			break;
		case(2):
			m_nom = "Jet-Pierres";
			m_type = "Rock";
			m_spe = false;
			m_puissance = 50;
			break;

		default:
			break;
		}
		break;

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

		default:
			break;
		}
		break;

	case(315): //Roselia
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Feuille Magik";
			m_type = "Grass";
			m_spe = true;
			m_puissance = 60;
			break;
		case(2):
			m_nom = "Choc Venin";
			m_type = "Poison";
			m_spe = true;
			m_puissance = 65;
			break;

		default:
			break;
		}
		break;

	case(349): //Barpau
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Charge";
			m_type = "Normal";
			m_spe = false;
			m_puissance = 40;
			break;
		case(2):
			m_nom = "Trempette";
			m_type = "Water";
			m_spe = false;
			m_puissance = 0;
			break;

		default:
			break;
		}
		break;

	case(350): //Milobellus
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Hydrocanon";
			m_type = "Water";
			m_spe = true;
			m_puissance = 110;
			break;
		case(2):
			m_nom = "Blizzard";
			m_type = "Water";
			m_spe = true;
			m_puissance = 110;
			break;

		default:
			break;
		}
		break;

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

	case(403):	//Crikzik
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Plaie-croix";
			m_type = "Bug";
			m_spe = false;
			m_puissance = 80;
			break;

		case(2):
			m_nom = "Bourdon";
			m_type = "Bug";
			m_spe = true;
			m_puissance = 90;
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

	case(407):	//Roserade
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Eco-Shpere";
			m_type = "Grass";
			m_spe = true;
			m_puissance = 90;
			break;

		case(2):
			m_nom = "Bomb-Beurk";
			m_type = "Poison";
			m_spe = true;
			m_puissance = 90;
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

	case(445):	//Carchacrok
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Telluriforce";
			m_type = "Ground";
			m_spe = true;
			m_puissance = 90;
			break;

		case(2):
			m_nom = "Colère";
			m_type = "Dragon";
			m_spe = false;
			m_puissance = 120;
			break;

		default:
			break;
		}
		break;

	case(447): //Riolu
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

	case(448): //Lucario
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

	case(461): //Dimoret 
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Vibrobscur";
			m_type = "Dark";
			m_spe = true;
			m_puissance = 80;
			break;
		case(2):
			m_nom = "Poing Glace";
			m_type = "Ice";
			m_spe = false;
			m_puissance = 75;
			break;

		default:
			break;
		}
		break;

	case(462): //Magnézone
		switch (numeroCapacite)
		{
		case (1):
			m_nom = "Tonnerre";
			m_type = "Electric";
			m_spe = true;
			m_puissance = 90;
			break;
		case(2):
			m_nom = "Luminocanon";
			m_type = "Steel";
			m_spe = true;
			m_puissance = 80;
			break;

		default:
			break;
		}
		break;

	case(468): //Togekiss
		switch (numeroCapacite)
		{
		case(1):
			m_nom = "Vol";
			m_type = "Fly";
			m_spe = false;
			m_puissance = 90;
			break;

		case(2):
			m_nom = "Pouvoir Lunaire";
			m_type = "Fairy";
			m_spe = true;
			m_puissance = 95;
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