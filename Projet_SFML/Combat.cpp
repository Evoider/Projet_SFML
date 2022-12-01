#include "Combat.h"
#include <iostream>

Combat::Combat(Pokemon& gentil, Pokemon& mechant)
{
	this->m_compteur = 1;

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
	std::cin >> choixCapacite;
	m_gentil->attaquer(*m_mechant, choixCapacite);
}

void Combat::checkBeginer()
{
	if (m_gentil->getVitesse() >= m_mechant->getVitesse())
	{
		m_compteur = 1;	//Donc gentil commence
	}
	else if (m_gentil->getVitesse() < m_mechant->getVitesse())
	{
		m_compteur = 2;	//Donc m�chant commence
	}
}

void Combat::fighting()
{
	checkBeginer();
	do
	{
		if (m_compteur == 1)
		{
			choixCapacite();
		}
		else if (m_compteur == 2)
		{
			std::cout << "L'ennemi t'attaque" << std::endl;
			m_mechant->attaquer(*m_gentil, 2);
		}
		std::cout << "Vie " << m_gentil->getNom() << " - " << m_gentil->getPv() << std::endl;
		std::cout << "Vie " << m_mechant->getNom() << " - " << m_mechant->getPv() << std::endl;
		m_compteur++;
		if (m_compteur > 2)
		{
			m_compteur = 1;
		}
		system("pause");
	} while ((m_gentil->getPv() > 0) and (m_mechant->getPv() > 0));
	std::cout << "Combat fini" << std::endl;
}