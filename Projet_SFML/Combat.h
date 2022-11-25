#pragma once
#include "Pokemon.h"

class Combat
{
public:
	Combat(Pokemon& gentil, Pokemon& mechant);
	void choixCapacite();
	void fighting();

private:
	Pokemon* m_gentil;
	Pokemon* m_mechant;

};