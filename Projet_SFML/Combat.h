#pragma once
#include "Pokemon.h"

class Combat
{
public:
	Combat(Pokemon& gentil, Pokemon& mechant);
	void choixCapacite();
	void choixIA();
	void checkBeginer();
	void fighting();

private:
	int m_compteur;

	Pokemon* m_gentil;
	Pokemon* m_mechant;

};