#include <stdio.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "Combat.h"
#include "Pokemon.h"

int main()
{
    Pokemon Tiplouf, Noctali;
    Tiplouf.creationPokemon(393);
    Noctali.creationPokemon(197);

    Combat premierCombat(Tiplouf, Noctali);
    premierCombat.choixCapacite();
    std::cout <<Noctali.getPv();
    return 0;
}
