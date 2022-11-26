#include <stdio.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "Combat.h"
#include "Pokemon.h"

int main()
{
    int choixStarteur;
    std::cout << "Bonjour jeune dresseur, choisie ton starteur" << std::endl;
    std::cin >> choixStarteur;
    std::cout << "Très bien tu as choisie Tiplouf" << std::endl;
    std::cout << "Voici ton premier combat contre Griknot (Il ne fais que les attaque les plus faibles" << std::endl;
    Pokemon Tiplouf, Griknot;
    Tiplouf.creationPokemon(393);
    Griknot.creationPokemon(443);

    Combat premierCombat(Tiplouf, Griknot);
    premierCombat.fighting();
    std::cout << Griknot.getPv();
    return 0;
}
