#pragma once
#include "Pokemon.h"

class Combat
{
public:
	Combat(Pokemon& gentil, Pokemon& mechant);
	void choixCapacite();

private:
	Pokemon* m_gentil;
	Pokemon* m_mechant;

};