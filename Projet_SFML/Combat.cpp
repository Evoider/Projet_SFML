#include "Combat.h"
#include <iostream>

Combat::Combat(Pokemon& gentil, Pokemon& mechant)
{
	m_gentil = &gentil;
	m_mechant = &mechant;
}

void Combat::choixCapacite()
{
	int choixCapacite;
	std::cout << "Que doit faire " << m_gentil->getNom() << "?" << std::endl;
	std::cout << std::endl;
	std::cout << "| 1-Utiliser  " << m_gentil->getCapacite1() << std::endl;
	std::cout << "| 2-Utiliser  " << m_gentil->getCapacite2() << std::endl;
	std:: cin >> choixCapacite;
	m_gentil->attaquer(*m_mechant, choixCapacite);
}

