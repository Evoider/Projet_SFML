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

void Pokemon::creationPokemon(int numeroPokemon) //Inclure attaque sp� et d�fense sp�
{
	switch (numeroPokemon)
	{

	case(39): //Rondoudou 60 et 70 
		m_numero = numeroPokemon;
		m_nom = "Rondoudou";
		m_type1 = "Normal";
		m_type2 = "Fairy";
		m_pvBase = m_pvMax = m_pv = 115;
		m_attaqueBase = m_attaque = 45;
		m_attaqueBase = m_attaqueSpe = 20;
		m_defenseBase = m_defense = 105;
		m_defenseSpeBase = m_defenseSpe = 55;
		m_vitesseBase = m_vitesse = 90;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(40): //Grodoudou 90 et 90 
		m_numero = numeroPokemon;
		m_nom = "Grodoudou";
		m_type1 = "Normal";
		m_type2 = "Fairy";
		m_pvBase = m_pvMax = m_pv = 140;
		m_attaqueBase = m_attaque = 70;
		m_attaqueBase = m_attaqueSpe = 45;
		m_defenseBase = m_defense = 75;
		m_defenseSpeBase = m_defenseSpe = 50;
		m_vitesseBase = m_vitesse = 45;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(63): //Abra 0 et 20
		m_numero = numeroPokemon;
		m_nom = "Abra";
		m_type1 = "Psy";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 25;
		m_attaqueBase = m_attaque = 20;
		m_attaqueBase = m_attaqueSpe = 15;
		m_defenseBase = m_defense = 105;
		m_defenseSpeBase = m_defenseSpe = 55;
		m_vitesseBase = m_vitesse = 90;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(64): //Kadabra 70 et 65
		m_numero = numeroPokemon;
		m_nom = "Kadabra";
		m_type1 = "Psy";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 40;
		m_attaqueBase = m_attaque = 35;
		m_attaqueBase = m_attaqueSpe = 30;
		m_defenseBase = m_defense = 120;
		m_defenseSpeBase = m_defenseSpe = 70;
		m_vitesseBase = m_vitesse = 105;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(65): //Alakazam 70 et 65
		m_numero = numeroPokemon;
		m_nom = "Alakazam";
		m_type1 = "Psy";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 55;
		m_attaqueBase = m_attaque = 50;
		m_attaqueBase = m_attaqueSpe = 45;
		m_defenseBase = m_defense = 135;
		m_defenseSpeBase = m_defenseSpe = 85;
		m_vitesseBase = m_vitesse = 120;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(91): //Magn�ti 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Magn�ti";
		m_type1 = "Steel";
		m_type2 = "Electric";
		m_pvBase = m_pvMax = m_pv = 25;
		m_attaqueBase = m_attaque = 35;
		m_attaqueBase = m_attaqueSpe = 70;
		m_defenseBase = m_defense = 95;
		m_defenseSpeBase = m_defenseSpe = 55;
		m_vitesseBase = m_vitesse = 45;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(92): //Fantominus 30 et 30
		m_numero = numeroPokemon;
		m_nom = "Fantominus";
		m_type1 = "Poison";
		m_type2 = "Ghost";
		m_pvBase = m_pvMax = m_pv = 30;
		m_attaqueBase = m_attaque = 35;
		m_attaqueBase = m_attaqueSpe = 30;
		m_defenseBase = m_defense = 100;
		m_defenseSpeBase = m_defenseSpe = 35;
		m_vitesseBase = m_vitesse = 80;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(93): //Spectrum 60 et 65
		m_numero = numeroPokemon;
		m_nom = "Spectrum";
		m_type1 = "Poison";
		m_type2 = "Ghost";
		m_pvBase = m_pvMax = m_pv = 40;
		m_attaqueBase = m_attaque = 50;
		m_attaqueBase = m_attaqueSpe = 45;
		m_defenseBase = m_defense = 115;
		m_defenseSpeBase = m_defenseSpe = 55;
		m_vitesseBase = m_vitesse = 95;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(94): //Ectoplasma 80 et 90
		m_numero = numeroPokemon;
		m_nom = "Ectoplasma";
		m_type1 = "Poison";
		m_type2 = "Ghost";
		m_pvBase = m_pvMax = m_pv = 60;
		m_attaqueBase = m_attaque = 65;
		m_attaqueBase = m_attaqueSpe = 60;
		m_defenseBase = m_defense = 130;
		m_defenseSpeBase = m_defenseSpe = 75;
		m_vitesseBase = m_vitesse = 110;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(113): //Poissirene
		m_numero = numeroPokemon;
		m_nom = "Poissirene";
		m_type1 = "Water";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 45;
		m_attaqueBase = m_attaque = 67;
		m_attaqueBase = m_attaqueSpe = 60;
		m_defenseBase = m_defense = 35;
		m_defenseSpeBase = m_defenseSpe = 50;
		m_vitesseBase = m_vitesse = 63;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(114): //Poissoroy
		m_numero = numeroPokemon;
		m_nom = "Poissoroy";
		m_type1 = "Water";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 80;
		m_attaqueBase = m_attaque = 92;
		m_attaqueBase = m_attaqueSpe = 65;
		m_defenseBase = m_defense = 65;
		m_defenseSpeBase = m_defenseSpe = 80;
		m_vitesseBase = m_vitesse = 68;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(124): //Lippoutou
		m_numero = numeroPokemon;
		m_nom = "Lippoutou";
		m_type1 = "Ice";
		m_type2 = "Psy";
		m_pvBase = m_pvMax = m_pv = 65;
		m_attaqueBase = m_attaque = 50;
		m_attaqueBase = m_attaqueSpe = 35;
		m_defenseBase = m_defense = 115;
		m_defenseSpeBase = m_defenseSpe = 95;
		m_vitesseBase = m_vitesse = 95;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(147): //Pt�ra 50 et 60
		m_numero = numeroPokemon;
		m_nom = "Ptera";
		m_type1 = "Fly";
		m_type2 = "Rock";
		m_pvBase = m_pvMax = m_pv = 80;
		m_attaqueBase = m_attaque = 105;
		m_attaqueBase = m_attaqueSpe = 65;
		m_defenseBase = m_defense = 60;
		m_defenseSpeBase = m_defenseSpe = 75;
		m_vitesseBase = m_vitesse = 130;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(155): //H�ricendre 40 et 30
		m_numero = numeroPokemon;
		m_nom = "Hericendre";
		m_type1 = "Fire";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 39;
		m_attaqueBase = m_attaque = 52;
		m_attaqueBase = m_attaqueSpe = 43;
		m_defenseBase = m_defense = 60;
		m_defenseSpeBase = m_defenseSpe = 50;
		m_vitesseBase = m_vitesse = 35;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(156): //Feurisson 60 et 50
		m_numero = numeroPokemon;
		m_nom = "Feurisson";
		m_type1 = "Fire";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 58;
		m_attaqueBase = m_attaque = 64;
		m_attaqueBase = m_attaqueSpe = 58;
		m_defenseBase = m_defense = 80;
		m_defenseSpeBase = m_defenseSpe = 65;
		m_vitesseBase = m_vitesse = 80;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(157): //Typhlosion 100 et 90
		m_numero = numeroPokemon;
		m_nom = "Typhlosion";
		m_type1 = "Fire";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 78;
		m_attaqueBase = m_attaque = 84;
		m_attaqueBase = m_attaqueSpe = 78;
		m_defenseBase = m_defense = 109;
		m_defenseSpeBase = m_defenseSpe = 85;
		m_vitesseBase = m_vitesse = 100;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(174): //Toudoudou 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Toudoudou";
		m_type1 = "Normal";
		m_type2 = "Fairy";
		m_pvBase = m_pvMax = m_pv = 90;
		m_attaqueBase = m_attaque = 30;
		m_attaqueBase = m_attaqueSpe = 15;
		m_defenseBase = m_defense = 40;
		m_defenseSpeBase = m_defenseSpe = 20;
		m_vitesseBase = m_vitesse = 15;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(175): //Togepi 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Togepi";
		m_type1 = "Fairy";
		m_type2 = "Null";
		m_pvBase = m_pvMax = m_pv = 35;
		m_attaqueBase = m_attaque = 20;
		m_attaqueBase = m_attaqueSpe = 65;
		m_defenseBase = m_defense = 40;
		m_defenseSpeBase = m_defenseSpe = 65;
		m_vitesseBase = m_vitesse = 20;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(176): //Togetic 60 et 50
		m_numero = numeroPokemon;
		m_nom = "Togetic";
		m_type1 = "Fairy";
		m_type2 = "Fly";
		m_pvBase = m_pvMax = m_pv = 55;
		m_attaqueBase = m_attaque = 40;
		m_attaqueBase = m_attaqueSpe = 85;
		m_defenseBase = m_defense = 80;
		m_defenseSpeBase = m_defenseSpe = 105;
		m_vitesseBase = m_vitesse = 40;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(215): //Farfuret 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Farfuret";
		m_type1 = "Ice";
		m_type2 = "Dark";
		m_pvBase = m_pvMax = m_pv = 55;
		m_attaqueBase = m_attaque = 95;
		m_attaqueBase = m_attaqueSpe = 55;
		m_defenseBase = m_defense = 65;
		m_defenseSpeBase = m_defenseSpe = 45;
		m_vitesseBase = m_vitesse = 115;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(238): //Lippouti 40 et 30
		m_numero = numeroPokemon;
		m_nom = "Lippouti";
		m_type1 = "Ice";
		m_type2 = "Psy";
		m_pvBase = m_pvMax = m_pv = 45;
		m_attaqueBase = m_attaque = 30;
		m_attaqueBase = m_attaqueSpe = 15;
		m_defenseBase = m_defense = 85;
		m_defenseSpeBase = m_defenseSpe = 65;
		m_vitesseBase = m_vitesse = 65;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(246): //Embrylex 40 et 50
		m_numero = numeroPokemon;
		m_nom = "Embrylex";
		m_type1 = "Rock";
		m_type2 = "Ground";
		m_pvBase = m_pvMax = m_pv = 50;
		m_attaqueBase = m_attaque = 64;
		m_attaqueBase = m_attaqueSpe = 50;
		m_defenseBase = m_defense = 45;
		m_defenseSpeBase = m_defenseSpe = 50;
		m_vitesseBase = m_vitesse = 41;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(247): //Ymphect 75 et 50
		m_numero = numeroPokemon;
		m_nom = "Ymphect";
		m_type1 = "Rock";
		m_type2 = "Ground";
		m_pvBase = m_pvMax = m_pv = 70;
		m_attaqueBase = m_attaque = 84;
		m_attaqueBase = m_attaqueSpe = 70;
		m_defenseBase = m_defense = 65;
		m_defenseSpeBase = m_defenseSpe = 70;
		m_vitesseBase = m_vitesse = 51;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(248): //Tyranocif 80 et 100
		m_numero = numeroPokemon;
		m_nom = "Tyranocif";
		m_type1 = "Dark";
		m_type2 = "Ground";
		m_pvBase = m_pvMax = m_pv = 100;
		m_attaqueBase = m_attaque = 134;
		m_attaqueBase = m_attaqueSpe = 110;
		m_defenseBase = m_defense = 95;
		m_defenseSpeBase = m_defenseSpe = 100;
		m_vitesseBase = m_vitesse = 61;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(315):	//Roselia
		m_numero = numeroPokemon;
		m_nom = "Roselia";
		m_type1 = "Grass";
		m_type1 = "Poison";
		m_pvBase = m_pvMax = m_pv = 50;
		m_attaqueBase = m_attaque = 60;
		m_attaqueBase = m_attaqueSpe = 45;
		m_defenseBase = m_defense = 100;
		m_defenseSpeBase = m_defenseSpe = 80;
		m_vitesseBase = m_vitesse = 65;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(349):	//Barpau 40 et 0
		m_numero = numeroPokemon;
		m_nom = "Barpau";
		m_type1 = "Water";
		m_type1 = "None";
		m_pvBase = m_pvMax = m_pv = 20;
		m_attaqueBase = m_attaque = 15;
		m_attaqueBase = m_attaqueSpe = 20;
		m_defenseBase = m_defense = 10;
		m_defenseSpeBase = m_defenseSpe = 55;
		m_vitesseBase = m_vitesse = 80;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(350):	//Milobellus
		m_numero = numeroPokemon;
		m_nom = "Milobellus";
		m_type1 = "Water";
		m_type1 = "None";
		m_pvBase = m_pvMax = m_pv = 95;
		m_attaqueBase = m_attaque = 60;
		m_attaqueBase = m_attaqueSpe = 79;
		m_defenseBase = m_defense = 100;
		m_defenseSpeBase = m_defenseSpe = 125;
		m_vitesseBase = m_vitesse = 81;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(393):	//Tiplouf 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Tiplouf";
		m_type1 = "Water";
		m_type1 = "None";
		m_pvBase = m_pvMax = m_pv = 53;
		m_attaqueBase = m_attaque = 51;
		m_attaqueBase = m_attaqueSpe = 61;
		m_defenseBase = m_defense = 53;
		m_defenseSpeBase = m_defenseSpe = 56;
		m_vitesseBase = m_vitesse = 40;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(402):	//Crikzik 20 et 50
		m_numero = numeroPokemon;
		m_nom = "Crikzik";
		m_type1 = "Bug";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 37;
		m_attaqueBase = m_attaque = 25;
		m_attaqueSpeBase = m_attaqueSpe = 41;
		m_defenseBase = m_defense = 25;
		m_defenseSpeBase = m_defenseSpe = 41;
		m_vitesseBase = m_vitesse = 25;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(403):	//Melokrik 80 et 90
		m_numero = numeroPokemon;
		m_nom = "Melokrik";
		m_type1 = "Bug";
		m_type2 = "None";
		m_pvBase = m_pvMax = m_pv = 77;
		m_attaqueBase = m_attaque = 85;
		m_attaqueSpeBase = m_attaqueSpe = 51;
		m_defenseBase = m_defense = 55;
		m_defenseSpeBase = m_defenseSpe = 51;
		m_vitesseBase = m_vitesse = 65;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(406):	//Rozbouton 25 et 40
		m_numero = numeroPokemon;
		m_nom = "Rozbouton";
		m_type1 = "Grass";
		m_type2 = "Poison";
		m_pvBase = m_pvMax = m_pv = 40;
		m_attaqueBase = m_attaque = 30;
		m_attaqueSpeBase = m_attaqueSpe = 35;
		m_defenseBase = m_defense = 50;
		m_defenseSpeBase = m_defenseSpe = 70;
		m_vitesseBase = m_vitesse = 55;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(407):	//Roserade 90 et 90
		m_numero = numeroPokemon;
		m_nom = "Roserade";
		m_type1 = "Grass";
		m_type2 = "Poison";
		m_pvBase = m_pvMax = m_pv = 60;
		m_attaqueBase = m_attaque = 70;
		m_attaqueSpeBase = m_attaqueSpe = 55;
		m_defenseBase = m_defense = 125;
		m_defenseSpeBase = m_defenseSpe = 105;
		m_vitesseBase = m_vitesse = 90;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(417):	//Pachirisu 20 et 40
		m_numero = numeroPokemon;
		m_nom = "Pachirisu";
		m_type1 = "Electric";
		m_pvBase = m_pvMax = m_pv = 60;
		m_attaqueBase = m_attaque = 45;
		m_attaqueSpeBase = m_attaqueSpe = 70;
		m_defenseBase = m_defense = 45;
		m_defenseSpeBase = m_defenseSpe = 90;
		m_vitesseBase = m_vitesse = 95;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(442): //Spiritomb
		m_numero = numeroPokemon;
		m_nom = "Spiritomb";
		m_type1 = "Ghost";
		m_pvBase = m_pvMax = m_pv = 50;
		m_attaqueBase = m_attaque = 92;
		m_attaqueBase = m_attaqueSpe = 108;
		m_defenseBase = m_defense = 92;
		m_defenseSpeBase = m_defenseSpe = 108;
		m_vitesseBase = m_vitesse = 35;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(443):	//Griknot 40 et 35 CHECK
		m_numero = numeroPokemon;
		m_nom = "Griknot";
		m_type1 = "Ground";
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

	case(444):	//Carmache 60 et 80
		m_numero = numeroPokemon;
		m_nom = "Carmache";
		m_type1 = "Dragon";
		m_type2 = "Ground";
		m_pvBase = m_pvMax = m_pv = 68;
		m_attaqueBase = m_attaque = 90;
		m_attaqueSpeBase = m_attaqueSpe = 65;
		m_defenseBase = m_defense = 50;
		m_defenseSpeBase = m_defenseSpe = 55;
		m_vitesseBase = m_vitesse = 82;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(445):	//Carchacrok 9O et 120
		m_numero = numeroPokemon;
		m_nom = "Carchacrok";
		m_type1 = "Dragon";
		m_type2 = "Ground";
		m_pvBase = m_pvMax = m_pv = 108;
		m_attaqueBase = m_attaque = 130;
		m_attaqueSpeBase = m_attaqueSpe = 95;
		m_defenseBase = m_defense = 80;
		m_defenseSpeBase = m_defenseSpe = 85;
		m_vitesseBase = m_vitesse = 102;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(447): //Riolu 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Riolu";
		m_type1 = "Fighting";
		m_type2 = "Null";
		m_pvBase = m_pvMax = m_pv = 40;
		m_attaqueBase = m_attaque = 70;
		m_attaqueBase = m_attaqueSpe = 40;
		m_defenseBase = m_defense = 35;
		m_defenseSpeBase = m_defenseSpe = 40;
		m_vitesseBase = m_vitesse = 60;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(448): //Lucario 80 et 120
		m_numero = numeroPokemon;
		m_nom = "Lucario";
		m_type1 = "Steel";
		m_type2 = "Fighting";
		m_pvBase = m_pvMax = m_pv = 70;
		m_attaqueBase = m_attaque = 110;
		m_attaqueBase = m_attaqueSpe = 70;
		m_defenseBase = m_defense = 115;
		m_defenseSpeBase = m_defenseSpe = 70;
		m_vitesseBase = m_vitesse = 90;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(461): //Dimoret 80 et 75
		m_numero = numeroPokemon;
		m_nom = "Dimoret";
		m_type1 = "Ice";
		m_type2 = "Dark";
		m_pvBase = m_pvMax = m_pv = 70;
		m_attaqueBase = m_attaque = 120;
		m_attaqueBase = m_attaqueSpe = 65;
		m_defenseBase = m_defense = 45;
		m_defenseSpeBase = m_defenseSpe = 85;
		m_vitesseBase = m_vitesse = 125;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(462): //Magn�zone 90 et 80
		m_numero = numeroPokemon;
		m_nom = "Magn�zone";
		m_type1 = "Steel";
		m_type2 = "Electric";
		m_pvBase = m_pvMax = m_pv = 70;
		m_attaqueBase = m_attaque = 70;
		m_attaqueBase = m_attaqueSpe = 115;
		m_defenseBase = m_defense = 130;
		m_defenseSpeBase = m_defenseSpe = 90;
		m_vitesseBase = m_vitesse = 60;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(468): //Togekiss 90 et 95
		m_numero = numeroPokemon;
		m_nom = "Togekiss";
		m_type1 = "Fairy";
		m_type2 = "Fly";
		m_pvBase = m_pvMax = m_pv = 85;
		m_attaqueBase = m_attaque = 50;
		m_attaqueBase = m_attaqueSpe = 95;
		m_defenseBase = m_defense = 120;
		m_defenseSpeBase = m_defenseSpe = 115;
		m_vitesseBase = m_vitesse = 80;
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

	m_pv += ((2 * m_pvBase * m_lvl) / 100) + m_lvl + 10;
	m_attaque += ((2 * m_attaqueBase * m_lvl) / 100) + 5;
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
			victime.recevoirDegats(resistance(victime, *m_capacite1) * (m_attaqueSpe + m_capacite1->getPuissance() - victime.getDefenseSpe()));
		}
		else
		{
			victime.recevoirDegats(resistance(victime, *m_capacite1) * (m_attaque + m_capacite1->getPuissance() - victime.getDefense()));
		}
		break;

	case(2):
		if (m_capacite2->getSpe() == true)
		{
			victime.recevoirDegats(resistance(victime, *m_capacite2) * (m_attaqueSpe + m_capacite2->getPuissance() - victime.getDefenseSpe()));
		}
		else
		{
			victime.recevoirDegats(resistance(victime, *m_capacite2) * (m_attaque + m_capacite2->getPuissance() - victime.getDefense()));
		}
		break;

	default:
		break;
	}
}

void Pokemon::recevoirDegats(int degats)
{
	if (degats < 0)
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

int Pokemon::getLvl()
{
	return m_lvl;
}

int Pokemon::getDefense()
{
	return m_defense;
}

int Pokemon::getDefenseSpe()
{
	return m_defenseSpe;
}

int Pokemon::getVitesse()
{
	return m_vitesse;
}

std::string Pokemon::getType1()
{
	return m_type1;
}
std::string Pokemon::getType2()
{
	return m_type2;
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
float Pokemon::resistance(Pokemon& victime, Capacite& Capacity)
{
	if (victime.getType1() == "Fire")
	{
		if (Capacity.getType() == "Water" || Capacity.getType() == "Ground" || Capacity.getType() == "Rock")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Fairy" || Capacity.getType() == "Fire" || Capacity.getType() == "Ice" || Capacity.getType() == "Grass" || Capacity.getType() == "Bug")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Water")
	{
		if (Capacity.getType() == "Grass" || Capacity.getType() == "Electric")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Water" || Capacity.getType() == "Fire" || Capacity.getType() == "Ice")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Grass")
	{
		if (Capacity.getType() == "Fire" || Capacity.getType() == "Poison" || Capacity.getType() == "Ice" || Capacity.getType() == "Fly" || Capacity.getType() == "Bug")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Grass" || Capacity.getType() == "Water" || Capacity.getType() == "Electric" || Capacity.getType() == "Ground")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Electric")
	{
		if (Capacity.getType() == "Ground")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Fly" || Capacity.getType() == "Steel" || Capacity.getType() == "Electric")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Rock")
	{
		if (Capacity.getType() == "Water" || Capacity.getType() == "Grass" || Capacity.getType() == "Fighting" || Capacity.getType() == "Ground" || Capacity.getType() == "Steel")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Fire" || Capacity.getType() == "Normal" || Capacity.getType() == "Poison" || Capacity.getType() == "Fly")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Ground")
	{
		if (Capacity.getType() == "Water" || Capacity.getType() == "Ice" || Capacity.getType() == "Grass")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Poison" || Capacity.getType() == "Rock")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else if (Capacity.getType() == "Electric")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Steel")
	{
		if (Capacity.getType() == "Fighting" || Capacity.getType() == "Fire" || Capacity.getType() == "Ground")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Dragon" || Capacity.getType() == "Fairy" || Capacity.getType() == "Ice" || Capacity.getType() == "Bug" || Capacity.getType() == "Normal" || Capacity.getType() == "Grass" || Capacity.getType() == "Psy" || Capacity.getType() == "Rock" || Capacity.getType() == "Fly")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else if (Capacity.getType() == "Poison")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Steel")
	{
		if (Capacity.getType() == "Fighting" || Capacity.getType() == "Fire" || Capacity.getType() == "Ground")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Dragon" || Capacity.getType() == "Fairy" || Capacity.getType() == "Ice" || Capacity.getType() == "Bug" || Capacity.getType() == "Normal" || Capacity.getType() == "Grass" || Capacity.getType() == "Psy" || Capacity.getType() == "Rock" || Capacity.getType() == "Fly")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else if (Capacity.getType() == "Poison")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Ice")
	{
		if (Capacity.getType() == "Steel" || Capacity.getType() == "Fighting" || Capacity.getType() == "Fire" || Capacity.getType() == "Rock")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Ice")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Psy")
	{
		if (Capacity.getType() == "Bug" || Capacity.getType() == "Ghost" || Capacity.getType() == "Dark")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Psy")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Dark")
	{
		if (Capacity.getType() == "Fighting" || Capacity.getType() == "Fairy" || Capacity.getType() == "Bug")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Ghost" || Capacity.getType() == "Dark")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else if (Capacity.getType() == "Psy")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Fairy")
	{
		if (Capacity.getType() == "Steel" || Capacity.getType() == "Poison")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Bug" || Capacity.getType() == "Dark")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else if (Capacity.getType() == "Dragon")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}

	}
	if (victime.getType1() == "Ghost")
	{
		if (Capacity.getType() == "Ghost" || Capacity.getType() == "Dark")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Bug" || Capacity.getType() == "Poison")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Normal")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Fighting")
	{
		if (Capacity.getType() == "Psy" || Capacity.getType() == "Fairy" || Capacity.getType() == "Fly")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Bug" || Capacity.getType() == "Rock" || Capacity.getType() == "Dark")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Dragon")
	{
		if (Capacity.getType() == "Dragon" || Capacity.getType() == "Fairy" || Capacity.getType() == "Ice")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Water" || Capacity.getType() == "Fire" || Capacity.getType() == "Grass" || Capacity.getType() == "Electric")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Bug")
	{
		if (Capacity.getType() == "Fire" || Capacity.getType() == "Rock" || Capacity.getType() == "Fly")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Grass" || Capacity.getType() == "Ground")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Normal")
	{
		if (Capacity.getType() == "Fighting")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Ghost")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Fly")
	{
		if (Capacity.getType() == "Electric" || Capacity.getType() == "Ice" || Capacity.getType() == "Rock")
		{
			std::cout << "C'est super efficace !" << std::endl;
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Bug" || Capacity.getType() == "Grass")
		{
			std::cout << "Ce n'est pas tres efficace..." << std::endl;
			return 0.5;
		}
		else if (Capacity.getType() == "Ground")
		{
			std::cout << "Ca n'affecte pas " << victime.getNom() << std::endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}